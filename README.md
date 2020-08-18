<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# AVR128DB48 Using the Internal Opamp as Regulated Power Supply for MVIO
<!-- Put in figure here if needed
<p align="left">
  <img width=800px height=auto src="images/setup.png">
</p>
-->
<!-- This is where the introduction to the example goes, including mentioning the peripherals used -->
A new feature introduced in the AVR-DB is the Analog Signal Conditioning (OPAMP) peripheral. In this example, the OPAMP is used as an adjustable power supply. This eliminates the need for an external power supply for a second voltage domain. One op amp is configured as a voltage follower and code examples for four scenarios are presented:
1.	Voltage reference using the internal resistor ladder
2.	Voltage reference using an external resistor
3.	Voltage reference using the internal DAC
4.	Monitoring voltage level with the internal ADC


## Related Documentation

<!-- Any information about an application note or tech brief can be linked here. Use unbreakable links!
     In addition a link to the device family landing page and relevant peripheral pages as well:
     - [AN3381 - Brushless DC Fan Speed Control Using Temperature Input and Tachometer Feedback](https://microchip.com/00003381/)
     - [PIC18F-Q10 Family Product Page](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic18f-q10-product-family) -->
* [ANxxxx - AVR128DB48 Using the Internal OPAMP as Regulated Power Supply for MVIO](https://microchip.com/DSxxxxxxxxxx) <!--fill in DS number once it has been assigned-->
* [AVR128DB48 device page](https://www.microchip.com/wwwproducts/en/AVR128DB48)

## Software Used

<!-- All software used in this example must be listed here. Use unbreakable links!
     - MPLAB® X IDE 5.30 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
     - MPLAB® XC8 2.10 or a newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
     - MPLAB® Code Configurator (MCC) 3.95.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCUs [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - Microchip PIC18F-Q Series Device Support (1.4.109) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/) -->
* [Atmel Studio](https://www.microchip.com/mplab/avr-support/atmel-studio-7) 7.0.2397 or later
* Atmel Studio AVR-DB_DFP version 1.0.21 or later
## Hardware Used

<!-- All hardware used in this example must be listed here. Use unbreakable links!
     - PIC18F47Q10 Curiosity Nano [(DM182029)](https://www.microchip.com/Developmenttools/ProductDetails/DM182029)
     - Curiosity Nano Base for Click boards™ [(AC164162)](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
     - POT Click board™ [(MIKROE-3402)](https://www.mikroe.com/pot-click) -->
* [AVR128DB48 Curiosity Nano](https://www.microchip.com/wwwproducts/en/AVR128DB48) <!-- Not the correct link, fix when curiosity nano page exists-->
* Two resistors (values based on desired voltage level)


## Setup

<!-- Explain how to connect hardware and set up software. Depending on complexity, step-by-step instructions and/or tables and/or images can be used -->
* Enable MVIO powered by internal op-amps on the development board, see [application note](https://microchip.com/DSxxxxxxxxxx) for each respective scenario <!--fill in DS number once it has been assigned-->
* Enable Dual Supply mode in the System Configuration 1 (SYSCFG1) fuse

## Operation
* Connect the AVR128DB48 Curiosity Nano to a computer using a USB cable
* Download the zip file or clone the example to get the source code
* Open the .atsln with Atmel Studio
* Press *Start without debugging* or use CTRL+ALT+F5 hotkeys to run the application
<!-- Explain how to operate the example. Depending on complexity, step-by-step instructions and/or tables and/or images can be used -->

## Conclusion
After going through this example you should have a better understanding of how to set up the OPAMP peripheral as a regulated power supply.
<!-- Summarize what the example has shown -->
