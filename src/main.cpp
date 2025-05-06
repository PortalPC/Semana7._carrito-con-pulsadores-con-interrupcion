#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL


volatile uint8_t motorEstado = 0;

int main(void){

  DDRB |= 0x0F;
  PORTB = 0x00;

  DDRD &= ~0XFC;
  PORTD |= 0xFC;

  PCICR |= (1<<PCIE2);
  PCMSK2 |= 0xFC;

  sei();

  while(1){

    switch(motorEstado){
      case 0:
      PORTB = 0x00;
      break;
      case 1:
      PORTB = 0b00000101;
      break;
      case 2:
      PORTB = 0B00001010;
      break;
      case 3:
      PORTB = 0b00001001;
      break;

      case 4:
      PORTB = 0b00000110;
      break;

      case 5:
      PORTB = 0b00000001;
      break;

      case 6:
      PORTB = 0b00000100;
      break;
    }
  
  }}

