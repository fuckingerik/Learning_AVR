#define F_CPU 1000000UL // tell the compiler about the clock frequency
#include <avr/io.h> // defines all macros and symbols
#include <util/delay.h> // defines time delay functions

/*
 *Define symbols
 */
#define ZERO 0b11101011
#define ONE 0b00101000
#define TWO 0b10110011
#define THREE 0b10111010
#define FOUR 0b01111000
#define FIVE 0b11011010
#define SIX 0b11011011
#define SEVEN 0b10101000
#define EIGHT 0b11111011
#define NINE 0b11111000

//define letters
#define A 0b11111001
#define R 0b00010001
#define N 0b00011001
#define O 0b00011011
#define L 0b01000011
#define D 0b00111011

void BOOB(){
  int digit[4] = {0b11111110, 0b11111101, 0b11111011, 0b11110111};
  int boob[4] = {EIGHT,ZERO,ZERO,EIGHT};
  int i;
  for (i = 0; i < 4; i++){
    PORTD = digit[i];
    PORTB = boob[i];
    _delay_ms(1);
    PORTD = 0b11111111;
  }
}

void ARNOLD(int j){
  int digit[4] = {0b11111110, 0b11111101, 0b11111011, 0b11110111};
  int letters[6] = {A,R,N,O,L,D};
  int i;
  for (i = 0; i < 4; i++){
    PORTD = digit[i];
    PORTB = letters[i];
    _delay_ms(1);
    PORTD = 0b11111111;
  }
}

void count(){
  int numbers[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
  int i;
  for (i = 0; i < 10; i++){
    //PORTD = 0x40;
    PORTD = 0b11111110;
    PORTB = numbers[i];
    _delay_ms(1000);
  }
}

/*
 * First clock not using any timer
 */
void firstClock(int *digits){
  int numbers[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
  int digit[4] = {0b11111110, 0b11111101, 0b11111011, 0b11110111};
  //  int dig_1 = cnt / 1000;
  //  int dig_2 = (cnt % 1000)/100;
  //  int dig_3 = (cnt % 100)/10;
  //  int dig_4 = cnt % 10;
  //  int digits[4] = {dig_1, dig_2, dig_3, dig_4};
  int clkNum[4] = {numbers[digits[0]], numbers[digits[1]], numbers[digits[2]], numbers[digits[3]]};
  int i;
  for (i = 0; i < 4; i++){
    PORTB = clkNum[i];
    PORTD = digit[i];
    _delay_ms(1);
    PORTD = 0b11111111;
  }
}

void firstClock_v2(int cnt){
  int numbers[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
  int digit[4] = {0b11111110, 0b11111101, 0b11111011, 0b11110111};
  int dig_1 = cnt / 1000;
  int dig_2 = (cnt % 1000)/100;
  int dig_3 = (cnt % 100)/10;
  int dig_4 = cnt % 10;
  int digits[4] = {dig_1, dig_2, dig_3, dig_4};
  int clkNum[4] = {numbers[digits[0]], numbers[digits[1]], numbers[digits[2]], numbers[digits[3]]};
  int i;
  for (i = 0; i < 4; i++){
    PORTB = clkNum[i];
    PORTD = digit[i];
    _delay_ms(1);
    PORTD = 0b11111111;
  }
}

void multiplex(){
  int numbers[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
  int digit[4] = {0b11111110, 0b11111101, 0b11111011, 0b11110111};
  int values[4] = {ZERO,TWO,ONE,FOUR}; //Set start time
  int i;
  for (i = 0; i < 4; i++){
    PORTB = values[i];
    PORTD = digit[i];
    _delay_ms(1);
    PORTD = 0b11111111;
  }
}

void calcDigits(int *digits, int cnt){
  int dig_1 = cnt / 1000;
  int dig_2 = (cnt % 1000)/100;
  int dig_3 = (cnt % 100)/10;
  int dig_4 = cnt % 10;
  digits[0] = dig_1;
  digits[1] = dig_2;
  digits[2] = dig_3;
  digits[3] = dig_4;
}

int main (void)
{
  int numbers[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
  DDRD = 0b11001111;
  DDRB = 0b11111111;
  // pin 0 of PORTB as output
  int i;
  int cnt = 0;
  int *digits;
  while (1)
    {
      /*
	PORTD = 0b00000000;
      PORTB = ZERO;
      _delay_ms (500);
      PORTD = 0x00;
      PORTB = 0x00;
      _delay_ms (500);
      *
  
      *
      for (i = 0; i < 4; i++){
	PORTD<<1
	}*/
      //count();
      //multiplex();
      //_delay_ms(500);
      //BOOB();
      //ARNOLD(1);
      //    calcDigits(digits, cnt);
      cnt = cnt + 1;
      cnt = cnt % 10000;
      int i;
      for (i = 0; i < 2; i++){
	//	firstClock(digits);
	firstClock_v2(cnt);
      }
    }
}
