#include "lib_ssd1306NoBuff.h"
#include <SPI.h>




SSD1306_DisplayNB *display;

void setup() {

  
  
  SPI.begin();
  
   pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  
  display = new SSD1306_DisplayNB;

  delay(100);

}

void print(char *m)
{
  while  (*m != 0)
  {
    // //Serial.print((char)*m);
    display->printCharX2(*m);
    m++;
  }
  ////Serial.println("-");
}

unsigned long  ms = 0;
unsigned int x = 11, y = 29;
int dx = 1, dy = 1;

void loop() {
  
  
    digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
  delay(100);          

  char buff[10];


  //DateTime now = rtc.now();
  unsigned int h = 10;
  unsigned int m = 11;
  unsigned int s = 12;

  display->setCursor(0, 0);
  display->clear_display();

  print(itoa(h, buff, 10));
  print(":");
  if (m < 10)
    print("0");
  print(itoa(m, buff, 10));
  print(":");
  if (s < 10)
    print("0");
  print(itoa(s, buff, 10));

  delay(1000);
  //display->display_buffer();

}
