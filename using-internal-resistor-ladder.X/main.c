/*
 * OPAMP as adjustable power supply.c
 *
 * Created: 17-Mar-20 12:17:50
 * Author : M19939
 */ 

#define F_CPU 4000000ul
#define CLK_PER 4000000ul
#define OPAMP_MAX_SETTLE_TIME 0x7F
#include <avr/io.h>
#include <math.h>

void op_amp_init();
void op_amp_setup_int_resistors(uint8_t MUXWIP_gc);

int main(void)
{

	op_amp_init();
	op_amp_setup_int_resistors(OPAMP_OP0RESMUX_MUXWIP_WIP4_gc);
    while (1) 
    {
		/*Your application goes here*/
    }
}


void op_amp_init()
{
	/*Disable input on op amp output pin*/
	PORTD.PIN2CTRL = PORT_ISC_INPUT_DISABLE_gc;
	
	/*Set up op amp*/
	OPAMP.CTRLA = OPAMP_ENABLE_bm;
	OPAMP.TIMEBASE = (uint8_t) ceil(CLK_PER*0.000001)-1; /*Number of peripheral clock cycles that amounts to 1us*/
	OPAMP.OP0CTRLA = OPAMP_RUNSTBY_bm | OPAMP_ALWAYSON_bm | OPAMP_OP0CTRLA_OUTMODE_NORMAL_gc;
    OPAMP.OP0SETTLE = OPAMP_MAX_SETTLE_TIME; //As the settle time is unknown, the maximums should be set
}

void op_amp_setup_int_resistors(OPAMP_OP0RESMUX_MUXWIP_t MUXWIP_gc)
{
	OPAMP.OP0INMUX = OPAMP_OP0INMUX_MUXNEG_OUT_gc | OPAMP_OP0INMUX_MUXPOS_WIP_gc;
	/* MUXWIP is the bit field that decides the output voltage of the op amp
	   With VDD at 5V you will get: 
	   OPAMP_OP0RESMUX_MUXWIP_WIP4_gc -> ~1.88V
	   OPAMP_OP0RESMUX_MUXWIP_WIP3_gc -> ~2.5V
	   OPAMP_OP0RESMUX_MUXWIP_WIP2_gc -> ~3.75V */
	OPAMP.OP0RESMUX = OPAMP_OP0RESMUX_MUXTOP_VDD_gc|OPAMP_OP0RESMUX_MUXBOT_GND_gc|MUXWIP_gc;
}
