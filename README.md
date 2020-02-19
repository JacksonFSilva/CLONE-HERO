# CLONE HERO - GUITAR HERO PC ARDUINO AS GUITAR GAMEPAD
Hi everyone, 
This is something that I made for fun. 
I had a broke guitar hero controller and wanted to play Clone hero  / Guitar Hero 3 on PC and had an Arduino Leonardo, so I planned to make it work together and it's working very fine and very responsive.
I've used this library for the job and it's great. https://github.com/MHeironimus/ArduinoJoystickLibrary
I realized that using #define to define ports I had way better responsiveness instead of using pinMode to map it and didn't have to use a delay at the end of the loop. 
If you want to use another Arduino board based on AtMega32u4  like ProMicro, you'll have to redefine the ports.
I tested it compared with a cheap USB joystick that I have and was obviously way more responsive, especially when you have to activate two or more buttons at the same time.
I'll add some photos and details about it soon, for while here it is the code. 


