/*	Author: akim106
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 8  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

// Max = 1000111111 = 0x023F
// Div/8 = 1000111 = 0x0047 (71)

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

    ADC_init();

    unsigned short input;
    //unsigned short div8 = 0x0047;
    unsigned char output;

    while (1) {
      output = 0x00;
      input = ADC;
      if (input >= 0x0047) { //First div8
        output = output | 0x01;
      }
      if (input >= 0x008E) { //Second div8
        output = output | 0x02;
      }
      if (input >= 0x00D5) { //Third div8
        output = output | 0x04;
      }
      if (input >= 0x011C) { //Fourth div8
        output = output | 0x08;
      }
      if (input >= 0x0163) { //Fifth div8
        output = output | 0x10;
      }
      if (input >= 0x01AA) { //Sixth div8
        output = output | 0x20;
      }
      if (input >= 0x01F1) { //Seventh div8
        output = output | 0x40;
      }
      if (input >= 0x0238) { //Eighth div8
        output = output | 0x80;
      }
      PORTB = output;
    }
    return 1;
}
