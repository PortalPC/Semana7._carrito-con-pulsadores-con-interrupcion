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

ISR(PCINT_vect){
  if(!(PIND & (1<<PD2))){
    motorEstado = 1;

  }else if (!(PIND &(1<<PD3))){
motorEstado = 2;

  }else if (!(PIND &(1<<PD4))){
    motorEstado = 3;
  }else if (!(PIND &(1<<PD5))){
    motorEstado = 4;

  }else if (!(PIND &(1<<PD6))){

    motorEstado = 5;
  }else if (!(PIND &(1<<PD7))){

    motorEstado = 6;
  }else{
    motorEstado = 0;
  }

  _delay_ms(50);
}