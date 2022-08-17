 /*
  *	@(#)cstart.c	1.20
  *	SMC88 Startup code
  *	Default, exit code will loop forever.
  *
  *	DEFINES to tune this startup code:
  *
  *		COPY (default)	-> produce code to clear 'CLEAR' sections AND initialize 'INIT' sections,
  *				   'CLEAR' and 'INIT' segments do not have to be consecutive
  *
  *	On exit the program will fall into an endless loop.
  */

void			_exit	( int );
void			_start	( void );
extern int		main	( void );
extern void		_copytable( void );

_interrupt( 0x0000 )	/* Startup vector */
void _start_cpt( void )
{
	#pragma asm
	; /*
	GLOBAL	__START
__START:

	;==========================================================================
	;===================  system initialization  ==============================
	;==========================================================================

	LD	SP,#@DOFF(__lc_es-0100h)	; stack pointer initialize
	LD	BR,#020h					; BR register initialize to I/O area

	;--------------  bus and clock control  -----------------------------------
	LD	[BR:02h],#0
									; clock = OSC1
									; OSC3off
									; normal power mode

	EXTERN  (DATA,TINY)__lc_b_.tbss		;BR is used for tiny data
	LD	BR,#(@DOFF(__lc_b_.tbss) >> 8)

	; */
	#pragma endasm

	/* Use copy table to clear memory and intialize data */
	_copytable();		/* routine is found in library */

	_exit( main() );	/* Stops program in an endless loop */
}


void
_exit( int i )	/* 'i' is parameter in BA */
{
		i;
		do 
		{
			_slp();
		}
		while( 1 );	/* Program never stops */
}

#pragma asm
	; /*
JP_FAR  MACRO lbl
	LD NB,#@DPAG(lbl)
	JRL lbl
	ENDM

	DEFSECT	".comm_min", CODE AT 2100H
	SECT	".comm_min"
	ASCII	"MN"
	JP_FAR	__START

	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rtclock2Hz
	JP_FAR	_rtclock1Hz
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_inputport
	JP_FAR	_inputport
	JP_FAR	_inputport
	JP_FAR	_inputport
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete
	JP_FAR	_rete

	ASCII	"NINTENDO"
	ASCII	"HNKJ"
	DB	"NEKO",0,0,0,0,0,0,0,0
	ASCII	"2P"
	DB	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

_rete:
	RETE

	EXTERN  _rtclock2Hz
	EXTERN  _rtclock1Hz
	EXTERN  _inputport


	DEFSECT	".tbss", DATA, TINY, CLEAR
	SECT	".tbss"
	; */
#pragma endasm
