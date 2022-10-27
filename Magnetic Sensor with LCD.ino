#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  pinMode(A0, INPUT); //magnetic field sensor (reed switch)
  pinMode(8, OUTPUT);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Magnet?");
}

void loop() {
  

  float beep = analogRead(A0);
  beep = map(analogRead(A0), 0, 1023, 10, 500); //mapping sensor data onto a range of delay times aka speed of beeping

  float freq = analogRead(A0);
  freq = map(analogRead(A0), 0, 1023, 300, 600); //mapping sensor data onto a range of audible frequencies
  
  tone(8, freq);
  delay(300);
  noTone(8);
  delay(beep);


  lcd.setCursor(0, 1);
  lcd.print("Value:");
 

  if (analogRead(A0)<= 500)
  {
    lcd.setCursor(11, 0);
    lcd.print("Yes! ");

    lcd.setCursor(7, 1);
    lcd.print(analogRead(A0));
    lcd.setCursor(9, 1);
    lcd.print("  "); //trouble shooting: value may have less digits than if A0 > 500
  
  }

  else 
  {
    lcd.setCursor(11, 0);
    lcd.print("No :(");

    lcd.setCursor(7, 1);
    lcd.print(analogRead(A0));
  
  }

  
}