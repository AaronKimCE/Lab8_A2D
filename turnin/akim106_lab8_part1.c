/*	Author: akim106
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 8  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
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
    unsigned char bottom_8;
    unsigned char top_2;

    while (1) {
      input = ADC;
      bottom_8 = (char)input;
      top_2 = (char)(input >> 8);
      PORTB = bottom_8;
      PORTD = top_2;   
    }
    return 1;
}
