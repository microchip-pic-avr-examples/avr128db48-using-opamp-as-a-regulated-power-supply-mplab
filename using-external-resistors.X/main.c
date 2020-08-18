/*
 * Using External Resistors.c
 *
 * Created: 02-Apr-20 14:00:53
 * Author : M19939
 */ 

#define F_CPU 4000000ul
#define CLK_PER 4000000ul
#include <avr/io.h>
#include <math.h>


void op_amp_setup_ext_resistors();
void op_amp_init();

int main(void)
{
	op_amp_init();
	op_amp_setup_ext_resistors();
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
	OPAMP.OP1CTRLA = OPAMP_RUNSTBY_bm | OPAMP_ALWAYSON_bm | OPAMP_OP1CTRLA_OUTMODE_NORMAL_gc;
}

void op_amp_setup_ext_resistors()
{
	OPAMP.OP0INMUX = OPAMP_OP0INMUX_MUXNEG_OUT_gc | OPAMP_OP0INMUX_MUXPOS_INP_gc;
}