#include <Wire.h>


const int buttonPin2 = 2;  
const int buttonPin3 = 3;
const int buttonPin4 = 4;
const int buttonPin5 = 5;
const int buttonPin6 = 6;
const int buttonPin7 = 7;
const int buttonPin8 = 8;
const int buttonPin9 = 9;
const int buttonPin10 = 10;
int ok = 0;

int buttonState2 = 0;  
int buttonState3 = 0; 
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int buttonState9 = 0;
int buttonState10 = 0;
byte response;

void setup() {

  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(buttonPin9, INPUT_PULLUP);
  pinMode(buttonPin10, INPUT_PULLUP);

  Wire.begin(8);
  
  Serial.begin(9600);
  
}

//In functie de alegerea lui PLAYER2(butonul apasat)
//se trimite pe I2C informatia pentru a se aprinde
//LED-ul corespunzator.

void loop() {

  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  buttonState8 = digitalRead(buttonPin8);
  buttonState9 = digitalRead(buttonPin9);
  buttonState10 = digitalRead(buttonPin10);
  
  if (buttonState2 == LOW && ok ==0) 
    { 
      response = '1';
      ok = 1;
   }

   if (buttonState3 == LOW && ok == 0) 
   {
      response = '2';
      ok = 1;
     
   }
   if (buttonState4 == LOW && ok == 0) 
    {
       response = '3';
       ok = 1;
     }

   if (buttonState5 == LOW && ok == 0) 
    {
      response = '4';
      ok = 1;
    }

   if (buttonState6 == LOW && ok == 0) 
    {
      response = '5';
      ok = 1;
   }

   if (buttonState7 == LOW && ok == 0) 
    {
      response = '6';
      ok = 1;
   }

    if (buttonState8 == LOW && ok == 0) 
    {
      response = '7';
      ok = 1;
    }
    
    if (buttonState9 == LOW && ok == 0) 
    {
      response = '8';
      ok = 1;
   }

  if(buttonState10 == LOW && ok == 0) 
    {
      response = '9';
      ok = 1;
    }

  if ( ok == 1 )
     {
      Wire.beginTransmission(9);
      mutareJucator2();
      Wire.endTransmission();
      ok = 0;
     }
}

void mutareJucator2() {
 
  Wire.write(response);
  Serial.println("Sunt JUCATOR 2 si am trimis alegerea catre JUCATOR 1!");
  
}
