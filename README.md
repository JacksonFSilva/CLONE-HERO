# CLONE HERO - GUITAR HERO PC ARDUINO AS GUITAR GAMEPAD
Hi everyone, 
This is something that I made for fun. 
I had a broke guitar hero controller and wanted to play Clone hero  / Guitar Hero 3 on PC and had an Arduino Leonardo, so I planned to make it work together and it's working very fine e very responsive. 
I'll add some photos and details about it soon, for while here it is the code. 


// Guitar Hero / Clone Hero guitar controller to PC ZERO DELAY.
// Use it with Arduino Leonardo.
// If you want to use t with ProMicro or another board based on Atmega32u4 you'll have to redefine ports.
// PINS 2 to 9 are Buttons, being 2 to 6 (green, red, yellow, blue and orange)
// And 7 to 9 (start, select and share / home) buttons. 
// PINS 10 to 13 are DPAD buttons, being 10 to 13 (up, down, left, right). 
// PIN A3 it's where is connected the whammy bar, use B10k POTS, same as Guitar Hero's guitars POTS original value.
// By Jackson F. da Silva, 02/18/2020, Brazil.    

/* After testing several times, instead of using pinMode to map Arduino's board PINS,
I realized that defining the ports improved the joystick responsiveness,
and I didn't have to use a delay at the end of the loop. */

// PINS 2 to 13 in Arduino Board. A3 Whammy Bar's PIN. 
#include <Joystick.h>
#define Bt1 2 
#define Bt2 3 
#define Bt3 4 
#define Bt4 5 
#define Bt5 6 
#define Bt6 7 
#define Bt7 8 
#define Bt8 9 
#define DpUp 10 
#define DpDown 11 
#define DpLeft 12 
#define DpRight 13
#define Whammy A3 

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  8, 1,                  // Button Count, Hat Switch Count
  false, false, true,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering
  
  

  int WhammyBarValue = 0;
  int WhammyBarValueByte = 0;
  int Dpad;

void setup(){
  
      // D-PADS BUTTONS
    pinMode(DpUp, INPUT_PULLUP);
    pinMode(DpDown, INPUT_PULLUP);
    pinMode(DpLeft, INPUT_PULLUP);
    pinMode(DpRight, INPUT_PULLUP);
    
    //BUTTONS
    pinMode(Bt1, INPUT_PULLUP); 
    pinMode(Bt2, INPUT_PULLUP);
    pinMode(Bt3, INPUT_PULLUP);
    pinMode(Bt4, INPUT_PULLUP);
    pinMode(Bt5, INPUT_PULLUP);
    pinMode(Bt6, INPUT_PULLUP);
    pinMode(Bt7, INPUT_PULLUP);
    pinMode(Bt8, INPUT_PULLUP);
  

  Joystick.begin();
}
void loop() {
 // WHAMMY BAR
   
   WhammyBarValue = analogRead(Whammy);
   
   if (WhammyBarValue >= 1) {
  WhammyBarValueByte = WhammyBarValue *1;
   } else {
    WhammyBarValueByte = 0;
    }
   Joystick.setZAxis(WhammyBarValueByte);
   
// READ D-PADS
 
if (digitalRead(DpLeft) == LOW) // LEFT
{
    Joystick.setHatSwitch(Dpad,270);
}  
else if (digitalRead(DpRight) == LOW) //RIGHT
{
    Joystick.setHatSwitch(Dpad,90);

} 
else if (digitalRead(DpDown) == LOW) //DOWN
{
    Joystick.setHatSwitch(Dpad,180);
}
else if (digitalRead(DpUp) == LOW) //UP
{
    Joystick.setHatSwitch(Dpad,0);
}
else {
  Joystick.setHatSwitch(Dpad, JOYSTICK_HATSWITCH_RELEASE);
}
   
   

   // Buttons
  if (digitalRead(Bt1) == LOW) //Joystick Button 1
{
    Joystick.pressButton(0);
} else {
  Joystick.releaseButton(0);           
  }    

if (digitalRead(Bt2) == LOW) // Joystick Button 2
{
    Joystick.pressButton(1);
} else {
  Joystick.releaseButton(1);
  } 
   
if (digitalRead(Bt3) == LOW) //Joystick Button 3
{
    Joystick.pressButton(2);
} else {
  Joystick.releaseButton(2);
  } 

  
if (digitalRead(Bt4) == LOW) //Joystick Button 4
{
    Joystick.pressButton(3);
} else {
  Joystick.releaseButton(3);
  } 

  
if (digitalRead(Bt5) == LOW) //Joystick Button 5
{
    Joystick.pressButton(4);
} else {
  Joystick.releaseButton(4);
  }

if (digitalRead(Bt6) == LOW) //Joystick Button 6
{
    Joystick.pressButton(5);
} else {
  Joystick.releaseButton(5);
  }

if (digitalRead(Bt7) == LOW) //Joystick Button 7
{
    Joystick.pressButton(6);
} else {
  Joystick.releaseButton(6);
  } 

if (digitalRead(Bt8) == LOW) //Joystick Button 8
{
    Joystick.pressButton(7);
} else {
  Joystick.releaseButton(7);
  } 
  

}
