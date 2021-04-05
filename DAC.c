// DAC.c
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// Implementation of the 4-bit digital to analog converter
// Daniel Valvano, Jonathan Valvano
// December 29, 2014
// Port B bits 3-0 have the 4-bit DAC

#include "DAC.h"
#include "..//tm4c123gh6pm.h"


// **************DAC_Init*********************
// Initialize 4-bit DAC 
// Input: none
// Output: none

// Port B bits 3-0 have the 4-bit DAC
// Port E bits 3-0 have 4 piano keys
void DAC_Init(void){
	//allow extra current GPIO_PORTB_DR8R_R |= 0x0F;
	unsigned long volatile delay;
	//SYSCTL_RCGC2_R |= 0x02; // activate port B
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // activate port B
  delay = SYSCTL_RCGC2_R;    // allow time to finish activating
  GPIO_PORTB_AMSEL_R &= ~0x3F; //all 6     // no analog
  GPIO_PORTB_PCTL_R &= ~0x00FFFFFF; // regular GPIO function
  GPIO_PORTB_DIR_R |= 0x0F;      // make PB6-0 out
  GPIO_PORTB_AFSEL_R &= ~0x3F;   // disable alt funct on PB2-0
  GPIO_PORTB_DEN_R |= 0x0F; 
  GPIO_PORTB_DR8R_R |= 0x0F;	// enable digital I/O on PB2-0
/* At least 4 DEN bits in PORTB should be high
 * At least 4 DIR bits in PORTB should be high
 *At least 4 DR8R bits in PORTB should be high */
	
	
}


// **************DAC_Out*********************
// output to DAC
// Input: 5-bit data, 1 to 32? NO ITS STILL 4BIT 
// Output: none
 //{8,9,11,12,13,14,14,15,15,15,14,14,13,12,11,9,8,7,5,4,3,2,2,1,1,1,2,2,3,4,5,7};
void DAC_Out(unsigned long data){
	//data = 0x15;
	GPIO_PORTB_DATA_R = data;
	//switch(data){
		//case 0x01: GPIO_PORTB_DATA_R = 0x01; break;
	//GPIO_PORTB_DATA_R = data;
  
//}
}