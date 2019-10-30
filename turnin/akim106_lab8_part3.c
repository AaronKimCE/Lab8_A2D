/*	Author: akim106
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 8  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

// Max = 1000111111 = 0x023F
// Div/2 = 0100011111 = 0x011F

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; //Inputs
    DDRB = 0xFF; PORTB = 0x00; //Outputs
    DDRD = 0xFF; PORTD = 0x00; //Outputs

    ADC_init();

    unsigned short input;
    unsigned short max_light = 0x011F;
    unsigned char bottom_8 = 0xFF;
    unsigned char top_2 = 0x03;
    

    while (1) {
      input = ADC;
      if (input >= max_light) {
        PORTB = bottom_8;
        PORTD = top_2;   
      } else {
        PORTB = 0x00;
        PORTD = 0x00;
      }
    }
    return 1;
}
