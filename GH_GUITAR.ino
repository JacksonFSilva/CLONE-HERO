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
#define Bt1 (INPUT_PULLUP,2)
#define Bt2 (INPUT_PULLUP,3) 
#define Bt3 (INPUT_PULLUP,4) 
#define Bt4 (INPUT_PULLUP,5) 
#define Bt5 (INPUT_PULLUP,6) 
#define Bt6 (INPUT_PULLUP,7) 
#define Bt7 (INPUT_PULLUP,8) 
#define Bt8 (INPUT_PULLUP,9) 
#define DpUp (INPUT_PULLUP,10) 
#define DpDown (INPUT_PULLUP,11) 
#define DpLeft (INPUT_PULLUP,12) 
#define DpRight (INPUT_PULLUP,13)
#define Whammy A3 

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  8, 1,                     // Button Count, Hat Switch Count
  false, false, true,      //No X and Y, only Z Axis
  false, false, false,    // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false); // No accelerator, brake, or steering
  
  

  int WhammyBarValue = 0;
  int WhammyBarValueByte = 0;
  int Dpad;
  int period = 5;
  unsigned long time_now = 0;

void setup(){
      
  Joystick.begin();
}
void loop() {

  // Make Loop Faster
  while(true){
    
 
 // WHAMMY BAR
   
   WhammyBarValue = analogRead(Whammy);
   
   if (WhammyBarValue >= 1) {
  WhammyBarValueByte = WhammyBarValue *1;
   } else {
    WhammyBarValueByte = 0;
    }
   Joystick.setZAxis(WhammyBarValueByte);
   
// READ D-PADS

        time_now += period;
        
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
    while(millis() < time_now + period){
        //wait approx. [period] ms
    }
 }
}
