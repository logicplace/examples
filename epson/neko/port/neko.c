/*** definition constant ***/
#define	VramStt			0x1000					//display start memory
#define	VramXmax		0x60					//X display memory max size
#define	VramYstep		0x60					//Y step memory size

#define WAIT(n)		wait(n*4-7)
void wait(int time);

/*** SFR definition ***/
_sfrbyte	sfr_osc			_at(0x2002);
_sfrword	sfr_lcd1		_at(0x2080);
_sfrbyte	sfr_lcd2		_at(0x2000);
_sfrbyte	sfr_intpri1		_at(0x2021);
_sfrbyte	sfr_intpri2		_at(0x2022);
_sfrbyte	sfr_intena1		_at(0x2024);
_sfrbyte	sfr_intena2		_at(0x2025);
_sfrbyte	sfr_intfnc1		_at(0x2028);
_sfrbyte	sfr_intfnc2		_at(0x2029);
_sfrbyte	sfr_wchtmr1		_at(0x2040);
_sfrbyte	sfr_k00			_at(0x2052);		//K00�`K07 PORT
_sfrbyte	sfr_k10			_at(0x2053);		//K10,K11  PORT
_sfrbyte	sfr_p10s		_at(0x2060);
_sfrbyte	sfr_p10			_at(0x2061);		//P10�`P17 PORT
_sfrbyte	sfr_r00			_at(0x20D2);

_rom unsigned char neko[][128] = {
{	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	// sleep1
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,
	0x22,0x3A,0x2A,0x26,0x22,0x00,0x80,0x40,
	0x80,0x48,0x68,0x58,0xC8,0x40,0x20,0x10,
	0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xC0,0x20,0x18,
	0x04,0x04,0x02,0x7A,0x86,0x01,0x80,0x80,
	0x81,0x03,0x05,0x07,0x01,0x00,0x00,0x80,
	0x43,0x05,0xFA,0x3C,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x07,0x08,0x10,
	0x10,0x10,0x10,0x10,0x33,0x24,0x28,0x28,
	0x28,0x29,0x29,0x3A,0x18,0x1C,0x39,0x24,
	0x24,0x3A,0x2D,0x26,0x31,0x1F,0x00,0x00,},
{	0x00,0x00,0x00,0x00,0x00,0x08,0x08,0xA8,	// sleep2
	0x48,0xA8,0x18,0x08,0x00,0x00,0x00,0x80,
	0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x02,0x03,0x02,
	0x02,0x02,0x02,0x02,0x80,0x40,0x80,0x04,
	0x04,0x06,0x05,0xC4,0x20,0x10,0x60,0x80,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xC0,0x20,0x18,
	0x04,0x04,0x02,0x7E,0x81,0x00,0x40,0x41,
	0x43,0x45,0x87,0x01,0x00,0x40,0x20,0x91,
	0x43,0x05,0xFA,0x3C,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x07,0x08,0x10,
	0x10,0x10,0x10,0x10,0x33,0x24,0x28,0x2A,
	0x2A,0x2A,0x28,0x38,0x18,0x1A,0x38,0x24,
	0x24,0x3A,0x2D,0x26,0x31,0x1F,0x00,0x00,},
{	0x00,0x40,0x40,0x80,0x80,0x04,0x08,0x10,		// awake
	0x20,0x00,0xC0,0x30,0x08,0x10,0x60,0x80,
	0x00,0x80,0x60,0x10,0x08,0x30,0xC0,0x00,
	0x10,0x08,0x04,0x80,0x80,0x40,0x40,0x00,
	0x08,0x08,0x08,0x08,0x00,0x01,0x01,0x00,
	0x00,0x7F,0x80,0x40,0x40,0x5C,0x00,0x01,
	0x41,0x01,0x00,0x5C,0x40,0x40,0x80,0x7F,
	0x00,0x01,0x01,0x08,0x08,0x08,0x08,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
	0x40,0x40,0x80,0xE1,0x12,0x0A,0x06,0x00,
	0x80,0x00,0x06,0x0A,0x12,0xE1,0x90,0x48,
	0x64,0x92,0x0C,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x18,0x1F,0x14,
	0x14,0x10,0x10,0x11,0x1F,0x10,0x10,0x18,
	0x0F,0x18,0x10,0x10,0x1F,0x11,0x10,0x10,
	0x14,0x14,0x1F,0x18,0x00,0x00,0x00,0x00,},
{	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,		// mati
	0x00,0x00,0xC0,0x30,0x08,0x10,0x60,0x80,
	0x00,0x80,0x60,0x10,0x08,0x30,0xC0,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x7F,0x80,0x40,0x40,0x5C,0x00,0x01,
	0x41,0x01,0x00,0x5C,0x40,0x40,0x80,0x7F,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
	0x40,0x40,0x80,0xE1,0x12,0x0A,0x06,0x00,
	0x80,0x00,0x06,0x0A,0x12,0xE1,0x80,0x40,
	0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x18,0x1F,0x14,
	0x14,0x10,0x10,0x11,0x1F,0x10,0x10,0x18,
	0x0F,0x18,0x10,0x10,0x1F,0x11,0x10,0x10,
	0x14,0x14,0x1F,0x1C,0x14,0x14,0x14,0x08,},
{	0x00,0x00,0x00,0x00,0x00,0xC0,0x40,0x40,		// jare
	0x80,0x80,0x80,0x00,0xFC,0x84,0x08,0x08,
	0x10,0x20,0x40,0x40,0x80,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x1E,0x60,
	0x80,0x00,0x00,0x91,0xA1,0x80,0x00,0x00,
	0x22,0x84,0x40,0x50,0x48,0xC1,0x3E,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
	0x40,0x41,0x82,0xE2,0x12,0x0A,0x06,0x00,
	0x80,0x88,0x4F,0x02,0x22,0xE2,0x9F,0x40,
	0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x18,0x1F,0x14,
	0x14,0x10,0x10,0x11,0x1F,0x10,0x10,0x18,
	0x0F,0x18,0x14,0x10,0x10,0x10,0x10,0x10,
	0x14,0x14,0x1F,0x1A,0x0A,0x0A,0x04,0x00,},
{	0x00,0x00,0x00,0x00,0x80,0x40,0x80,0x00,		// kaki1
	0x00,0x00,0x00,0x00,0xE0,0x10,0x20,0x40,
	0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x01,
	0x02,0x04,0x04,0x03,0x80,0x40,0x40,0x20,
	0x00,0x01,0x02,0x8C,0x70,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x07,0x0D,0x8D,
	0x55,0x50,0x94,0xF0,0x10,0x0A,0x0E,0x1D,
	0x95,0x24,0x24,0x27,0x13,0xE1,0xE1,0x01,
	0x01,0x01,0x02,0xFC,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x18,0x1F,0x14,
	0x14,0x10,0x10,0x11,0x1F,0x10,0x10,0x18,
	0x0F,0x18,0x18,0x10,0x1F,0x19,0x19,0x18,
	0x1C,0x14,0x17,0x14,0x14,0x14,0x14,0x08,},
{	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,		// kaki2
	0x00,0xF0,0x10,0x20,0x20,0x40,0x40,0x80,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x06,0x1A,0x22,0xC2,0x04,0x04,
	0x04,0x07,0x00,0xC0,0x20,0x10,0x80,0x80,
	0x01,0x01,0x02,0xFC,0xFE,0x02,0x3C,0x20,
	0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x07,0x0D,0x8D,
	0x55,0x50,0x94,0xF0,0x10,0x09,0x08,0x00,
	0x80,0x00,0x06,0x09,0x1B,0xEE,0x00,0x00,
	0x00,0x00,0x81,0xFE,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x18,0x1F,0x14,
	0x14,0x10,0x10,0x11,0x1F,0x10,0x10,0x18,
	0x0F,0x18,0x10,0x10,0x1F,0x19,0x18,0x1C,
	0x14,0x16,0x15,0x14,0x14,0x14,0x14,0x08,},
{	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,		// akubi
	0x00,0x00,0xC0,0x30,0x08,0x10,0x60,0x80,
	0x00,0x80,0x60,0x10,0x08,0x30,0xC0,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x7F,0x90,0x12,0x0A,0x02,0xF4,0x09,
	0x0D,0xF1,0x04,0x02,0x0A,0x12,0x90,0x7F,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
	0x40,0x40,0x80,0xE1,0x12,0x0A,0x06,0x01,
	0x81,0x00,0x06,0x0A,0x12,0xE1,0x80,0x40,
	0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x18,0x1F,0x14,
	0x14,0x10,0x10,0x11,0x1F,0x10,0x10,0x18,
	0x0F,0x18,0x10,0x10,0x1F,0x11,0x10,0x10,
	0x14,0x14,0x1F,0x1C,0x14,0x14,0x14,0x08,},
};

enum STATUS { sleep1, sleep2, awake, mati, jare, kaki1, kaki2, akubi };
enum STATUS sleep = sleep1;
int animation = sleep1;

//========================================================================
//====  <Vram Clear>				          ============================
//========================================================================
void clear_vram(void)
{
	unsigned char *vram;
	unsigned char x=0,y=0;
	
	vram = (unsigned char *) VramStt;
	//-------------------  clear MCU Vram  -------------------------------
	do 
	{
		do 
		{
			*(vram + x) = 0;
		} while ((x++) <= VramXmax);
		vram += VramYstep;
		x = 0;
		y++;
	} while (y < 8);
	//-------------------  clear global variable  ------------------------
}

//========================================================================
//====  <Draw Charactor>				          ============================
//========================================================================
void draw(int n)
{
	unsigned char *vram;
	unsigned char *p;
	unsigned char x=0,y=0;
	
	//--------------------- OSC1 --> OSC3 ---------------------------------
	sfr_osc |= 0x02;				// high power mode
	WAIT(5);						// wait 5msec
	sfr_osc |= 0x04;				// OSC3 on
	WAIT(20);						// wait 20msec
	sfr_osc |= 0x08;				// OSC1 --> OSC3

	vram = (unsigned char *) VramStt;
	p = neko[n];
	//-------------------  clear MCU Vram  -------------------------------
	do 
	{
		do 
		{
			*(vram + x) = *p++;
		} while ((x++) <= 30);
		vram += VramYstep;
		x = 0;
		y++;
	} while (y < 4);

	//--------------------- OSC1 --> OSC3 ---------------------------------
	sfr_osc &= ~0x08;				// OSC3 --> OSC1
	sfr_osc &= ~0x04;				// OSC3 off
	sfr_osc &= ~0x03;				// normal power mode
}

//========================================================================
//====  <clock 1Hz interrupt> clock  =====================================
//========================================================================
void _interrupt(0x44) rtclock1Hz (void) 
{
	//------------------  reset interrupt flag  --------------------------
	sfr_intfnc1 = 0x04;

	draw(sleep);
	sleep = sleep == sleep1 ? sleep2 : sleep1;

	sfr_r00 = sleep;
}

//========================================================================
//====  <clock 2Hz interrupt> clock  =====================================
//========================================================================
void _interrupt(0x4a) rtclock2Hz (void) 
{
	static int ANIMATION[] = {
		awake,	mati,
		jare,	mati,	jare,	mati,	jare,	mati,
		kaki1,	kaki2,	kaki1,	kaki2,	kaki1,	kaki2,
		akubi,
		-1
	};
	//------------------  reset interrupt flag  --------------------------
	sfr_intfnc1 = 0x08;

	draw(ANIMATION[animation]);
	animation++;
	if (ANIMATION[animation] == -1) {
		sleep = sleep1;
		sfr_intfnc1 = 0x04;				// reset 1Hz interrupt factor flag
		sfr_intena1 &= ~0x08;			// 2Hz interrupt disable
		sfr_intena1 |= 0x04;			// 1Hz interrupt enable
		sfr_wchtmr1 |= 0x02;			// reset clock timer
	}

	sfr_r00 = animation;
}

//========================================================================
//====  <K00-K03 interrupt> keymatrix  ===================================
//========================================================================
void _interrupt(0x86) inputport (void) 
{
	//------------------  reset interrupt flag  --------------------------
	sfr_intfnc2 = 0x0F;
	sfr_intena1 &= ~0x04;			// 1Hz interrupt disable
	sfr_intena1 |= 0x08;			// 2Hz interrupt enable
	sfr_wchtmr1 |= 0x02;			// reset clock timer
	
	animation = 0;
	draw(awake);
}

int main(void)
{
	//----------------------  set I/O register  ---------------------------
	// <display>
	//sfr_r2xd |= 0x60;				// set R25(CL),R26(FR) output data to H
	sfr_lcd1 = 0x0008;				/* 12x16 map, frame copy enabled
									   frame divider of 3 */
	sfr_lcd2 = 0x1c;				/* initial contrast = 7 */
	/*<clock>*/
	sfr_intpri1 |= 0x80;			// set interrupt priority 2
	sfr_wchtmr1 |= 0x02;			// reset clock timer
	sfr_intena1 |= 0x04;			// 1Hz interrupt enable
	sfr_wchtmr1 |= 0x01;			// run clock timer
	
	/*<I/O port>*/
	sfr_p10s |= 0x0c;				// set output P02-P03
	sfr_p10 &= 0xfb;				// set P02 low
	sfr_p10 |= 0x08;				// set P03 high
	sfr_p10 |= 0x04;				// set P02 high
	sfr_p10s = 0x32;				// set output P02 & P04-P05
	sfr_intpri1 |= 0x0C;			// set interrupt priority 3
	sfr_intena2 |= 0x0F;			// K00-K03 interrupt enalbe

	//-------------------  clear MCU Vram  --------------------------------
	clear_vram();

	// <all interrupt enable>
	#pragma asm
	; /*
		AND SC,#00111111b				; all interrupt enable
	; */
	#pragma endasm

	//---------------------  Main Loop  ----------------------------------
	for ( ; ; ) {
		//<reset WDT>
		//sfr_wchtmr1 |= 0x04;
		//<Halt>
		_halt();
	}

	return 0;
}

//========================================================================
//====  <wait>						          ============================
//========================================================================
#pragma asm
	; /*
	_wait:
		DEC	BA						; 2 cycle
		JRS	NZ,_wait				; 2 cycle
		RET
	; */
#pragma endasm
