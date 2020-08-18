/*
 * Monitoring OPAMP output with ADC.c
 *
 * Created: 02-Apr-20 14:02:50
 * Author : M19939
 */ 

#define F_CPU 4000000ul
#define CLK_PER 4000000ul
#include <avr/io.h>
#include <math.h>

uint16_t adc_sample();
void adc_init();
void op_amp_init();
void op_amp_setup_int_resistors(uint8_t MUXWIP_gc);

int main(void)
{
	adc_init();
	op_amp_init();
	op_amp_setup_int_resistors(OPAMP_OP0RESMUX_MUXWIP_WIP4_gc);
    while (1) 
    {
		/*In this example we have output voltage of ~1.88V, check that we are within 0.1V of that, LSB of result is 1mV*/
		uint16_t OP_out = adc_sample();
		if ((1780<OP_out) & (OP_out<1980))
		{
			/*Your code goes here*/
		}
    }
}


uint16_t adc_sample()
{
	uint16_t res;
	ADC0.COMMAND = ADC_STCONV_bm;
	while(!(ADC0.INTFLAGS & ADC_RESRDY_bm));
	/*Right shift result by 4 due to 16 over samples*/
	res=ADC0.RES>>4;
	return res;
}

void adc_init()
{
	VREF.ADC0REF = VREF_REFSEL_4V096_gc;
	ADC0.MUXPOS = ADC_MUXPOS_AIN2_gc;
	ADC0.CTRLB= ADC_SAMPNUM_ACC16_gc;
	ADC0.CTRLA= ADC_ENABLE_bm;
}

void op_amp_init()
{
	/*Disable input on op amp output pin*/
	PORTD.PIN2CTRL = PORT_ISC_INPUT_DISABLE_gc;
	
	/*Set up op amp*/
	OPAMP.CTRLA = OPAMP_ENABLE_bm;
	OPAMP.TIMEBASE = (uint8_t) ceil(CLK_PER*0.000001)-1; /*Number of peripheral clock cycles that amounts to 1us*/
	OPAMP.OP0CTRLA = OPAMP_RUNSTBY_bm | OPAMP_ALWAYSON_bm | OPAMP_OP0CTRLA_OUTMODE_NORMAL_gc;
}

void op_amp_setup_int_resistors(uint8_t MUXWIP_gc)
{
	OPAMP.OP0INMUX = OPAMP_OP0INMUX_MUXNEG_OUT_gc | OPAMP_OP0INMUX_MUXPOS_WIP_gc;
	/* MUXWIP is the bit field that decides the output voltage of the op amp
	   With VDD at 5V you will get: 
	   OPAMP_OP0RESMUX_MUXWIP_WIP4_gc -> ~1.88V
	   OPAMP_OP0RESMUX_MUXWIP_WIP3_gc -> ~2.5V
	   OPAMP_OP0RESMUX_MUXWIP_WIP2_gc -> ~3.75V */
	OPAMP.OP0RESMUX = OPAMP_OP0RESMUX_MUXTOP_VDD_gc|OPAMP_OP0RESMUX_MUXBOT_GND_gc|MUXWIP_gc;
}