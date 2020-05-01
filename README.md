# CLONE HERO - GUITAR HERO PC ARDUINO AS GUITAR GAMEPAD
Hi everyone, 

This is something that I made for fun. 
I had a broke Guitar Hero controller and wanted to play Clone hero / Guitar Hero 3 on PC and had an Arduino Leonardo, so I planned to make it work together and it's working very fine and very responsive.

I've used this library for the job and it's great. 

https://github.com/MHeironimus/ArduinoJoystickLibrary

I realized that using #define to define ports I had way better responsiveness instead of using pinMode to map it and didn't have to use a delay at the end of the loop.  

If you want to use another Arduino board based on AtMega32u4  like ProMicro, you'll have to redefine the ports, I've wrote some commnents on the code explaining it. 

If you guys want to make something like it and wanna know more details about it send me a message on reddit.
https://www.reddit.com/user/Jackson_FS



