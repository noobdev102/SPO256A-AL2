/*
  Example for using the SPO256A library 
*/
#include <SoftwareSerial.h>
#include <avr/pgmspace.h>
#include <SPO256A.h>

SPO256A SPO256A(8, 9);     // where ALD and LRQ pins are connected

#define bufferlength 30
byte buffer[bufferlength];
unsigned long counter = 0;  // the number that is spoken by the spo chip

void setup() {
}

void loop(){
  Say();                          // try queue next number when queue is empty
  
  SPO256A.HandleSPO256AQueue();  // handle the queue
}

void Say(void){
  if (SPO256A.isEmpty()){
    SPO256A.SendToSPO256A(PA5); // a pause between numbers
    SayNumber(counter);      // queue next number
    counter++;
    return;
  } 
}

void SayNumber(unsigned long number){
  if(number > 999999999)
    return;
  if (number == 0){
    SayNumber(0);
    return;
  }
  number = SayLargeNumber(number, 1000000, 2); // say millions
  number = SayLargeNumber(number, 1000, 1); // say thousands
  SayHundreds(number); // hunders and the rest
}

unsigned long SayLargeNumber(unsigned long number, unsigned long offset, int index){
  if (number >= offset && number < offset * 1000){
    SayHundreds(number / offset);
    SayLarge(index); //million/thousand
    number = number % offset;    
  }
  return number;
}

// say number between 1 and 999
void SayHundreds(unsigned int number){
  if (number > 999)
    return;
  if (number > 99 ){          // say x hundred
    SaySmall(number / 100);
    SayLarge(0);              // hundred
    number = number % 100;
  }
  if (number == 0)
    return;
  if (number > 19){
    SaySmall((number / 10) + 18);  // twenty thru ninety
    number = number % 10;
  }
  if (number == 0)
    return;
  SaySmall(number);
}

void SayLarge(int index){
  memcpy_P(buffer, (byte *)pgm_read_word(&(largenumbers[index])),bufferlength);
  SayBuffer();
}

void SaySmall(int index){
  memcpy_P(buffer, (byte *)pgm_read_word(&(numbers[index])),bufferlength);
  SayBuffer();
}

void SayBuffer(void){
  int i=0;
  while(buffer[i] != 0x0FF){
    SPO256A.SendToSPO256A(buffer[i]);
    i++;
  }
}
