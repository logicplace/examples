#include "pm.h"
#include "neko.h"

#define FRAMEBUFFER         ((volatile unsigned char *)(0x1000))
#define SCREEN_WIDTH        96
#define SCREEN_PAGE_HEIGHT  8

enum STATUS sleep = sleep1;
int animation = sleep1;


#define WAIT(n)  wait(n*4-7)
void wait(int time);

//========================================================================
//====  <Vram Clear>				          ============================
//========================================================================
void clear_vram(void)
{
	volatile unsigned char *vram;
	unsigned char i;
	
	vram = FRAMEBUFFER;
	//-------------------  clear MCU Vram  -------------------------------
	for (i = SCREEN_WIDTH * SCREEN_PAGE_HEIGHT; i; --i, ++vram) {
		*vram = 2;
	}
}

//========================================================================
//====  <Draw Charactor>				          ============================
//========================================================================
void draw(int n)
{
	volatile unsigned char *vram;
	unsigned char *p;
	unsigned char x, y;
	
	//--------------------- OSC1 --> OSC3 ---------------------------------
	SYS_CTRL3 |= 0x02;				// high power mode
	WAIT(5);						// wait 5msec
	SYS_CTRL3 |= 0x04;				// OSC3 on
	WAIT(20);						// wait 20msec
	SYS_CTRL3 |= 0x08;				// OSC1 --> OSC3

	vram = FRAMEBUFFER;
	p = (unsigned char *) neko[n];
	//-------------------  clear MCU Vram  -------------------------------
	for (y = 0; y < ICON_PAGE_HEIGHT; ++y) {
		for (x = 0; x < ICON_WIDTH; ++x, ++vram, ++p) {
			*vram = *p;
		}
		// Increment to start of next row
		vram += (SCREEN_WIDTH - ICON_WIDTH);
	}

	//--------------------- OSC1 --> OSC3 ---------------------------------
	SYS_CTRL3 &= ~0x08;				// OSC3 --> OSC1
	SYS_CTRL3 &= ~0x04;				// OSC3 off
	SYS_CTRL3 &= ~0x03;				// normal power mode
}

//========================================================================
//====  <clock 1Hz interrupt> clock  =====================================
//========================================================================
void rtclock1Hz (void)
{
	draw(sleep);
	sleep = sleep == sleep1 ? sleep2 : sleep1;
}

//========================================================================
//====  <clock 2Hz interrupt> clock  =====================================
//========================================================================
void rtclock2Hz (void)
{
	static int ANIMATION[] = {
		awake,	mati,
		jare,	mati,	jare,	mati,	jare,	mati,
		kaki1,	kaki2,	kaki1,	kaki2,	kaki1,	kaki2,
		akubi,
		-1
	};

	draw(ANIMATION[animation]);
	animation++;
	if (ANIMATION[animation] == -1) {
		sleep = sleep1;
		IRQ_ACT2 = IRQ2_1HZ;			// reset 1Hz interrupt factor flag
		IRQ_ENA2 &= ~IRQ2_2HZ;			// 2Hz interrupt disable
		IRQ_ENA2 |= IRQ2_1HZ;			// 1Hz interrupt enable
		TMR256_CTRL |= 0x02;			// reset clock timer
	}
}

//========================================================================
//====  <K00-K03 interrupt> keymatrix  ===================================
//========================================================================
void inputport (void)
{
	IRQ_ENA2 &= ~IRQ2_1HZ;			// 1Hz interrupt disable
	IRQ_ENA2 |= IRQ2_2HZ;			// 2Hz interrupt enable
	TMR256_CTRL |= 0x02;			// reset clock timer
	
	animation = 0;
	draw(awake);
}

int main(void)
{
	//----------------------  set I/O register  ---------------------------
	// <display>
	PRC_MODE = COPY_ENABLE;			/* 12x16 map, frame copy enabled
									   frame divider of 3 */

	/*<clock>*/
	IRQ_PRI2 |= PRI2_TIM256(2);		// set interrupt priority 2
	TMR256_CTRL |= 0x02;			// reset clock timer
	IRQ_ENA2 |= IRQ2_1HZ;			// 1Hz interrupt enable
	TMR256_CTRL |= 0x01;			// run clock timer
	
	/*<keypad>*/
	IRQ_PRI2 |= PRI2_KEY(3);	// set interrupt priority 3
	// K00-K03 interrupt enable
	IRQ_ENA3 |= IRQ3_KEYUP | IRQ3_KEYC | IRQ3_KEYB | IRQ3_KEYA;

	//-------------------  clear MCU Vram  --------------------------------
	clear_vram();

	//---------------------  Main Loop  ----------------------------------
	for ( ; ; ) {
		//<Halt>
		_halt();
	}
}
