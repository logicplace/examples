#include "pm.h"

int main(void)
{
	// Initialize PTM_C in 16-bit mode
	TMR3_CTRL = 0x0082;
	TMR1_OSC |= 0x20;
	TMR3_SCALE = 0x08;
	TMR3_OSC = 0;

	// Initialize volume
	AUD_CTRL &= 0xFC; // this is the default
	AUD_VOL = 2; // 50% volume

	// Generate square wave at A4, ~440 Hz
	TMR3_PRE = 4544;
	TMR3_PVT = 2272; // half of PRE = 50% pulse width

	// Enable timer
	TMR3_CTRL_L = 0x04;

	// Do nothing
	for (;;) {}
}
