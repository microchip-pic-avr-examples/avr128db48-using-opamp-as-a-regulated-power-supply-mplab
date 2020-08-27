/**
 * \file main.c
 *
 * \brief Main source file.
 *
 (c) 2020 Microchip Technology Inc. and its subsidiaries.
    Subject to your compliance with these terms, you may use this software and
    any derivatives exclusively with Microchip products. It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

#define F_CPU 4000000ul
#define CLK_PER 4000000ul
#define OPAMP_MAX_SETTLE_TIME 0x7F
#include <avr/io.h>
#include <math.h>

#define VDD 5

void op_amp_init();
void op_amp_setup_dac();
void dac_init();
void dac_set_voltage(float v_out);

int main(void)
{
	dac_init();
	op_amp_init();
	/*Default voltage is set to 1.8V*/
	dac_set_voltage(1.8);
	while (1) 
    {
		/*Your application goes here*/
    }
}

void dac_set_voltage(float v_out)
{
	/*Ensure we set the output voltage within the limits of the OPAMP drive capabilities*/
	if (v_out>VDD-1)
	{
		v_out=VDD-1;
	}
	uint16_t data = (v_out/VDD)*1023;
	DAC0.DATA = data << DAC_DATA_gp;
}

void dac_init()
{
	/*Setting the reference for the DAC to VDD*/
	VREF.DAC0REF = VREF_REFSEL_VDD_gc;

	/*Enable DAC and enable the DAC output*/
	DAC0.CTRLA = DAC_ENABLE_bm | DAC_OUTEN_bm;
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
void op_amp_setup_dac()
{
	OPAMP.OP0INMUX = OPAMP_OP0INMUX_MUXNEG_OUT_gc | OPAMP_OP0INMUX_MUXPOS_DAC_gc;
}
