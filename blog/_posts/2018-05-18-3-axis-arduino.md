---
layout: article
title:    3-axis robotic arm programming with Arduino.
tags: Programming
article_header:
  type: overlay
  theme: dark
  background_color: '#203028'
  background_image:
    gradient: 'linear-gradient(135deg, rgba(34, 139, 87 , .4), rgba(139, 34, 139, .4))'
    src: /blog/assets/2018-05-18/dobot1.png
aside:
  toc: true
author: true
---
Structured Programming with Microcontrollers Class project

<div align="center" markdown="1">
![](/blog/assets/2018-05-18/dobot1.png)
</div>

<!--more-->
## Instructions
<div align="justify" markdown="1">
1. The stepper motor (M1) of the base, which performs the rotation indicated by q1, must be able to move 360 ° to make complete revolutions through its axis.
2. The stepper motor (M2) that performs the rotation in q2, must be able to move through a 180 ° arc that begins on the positive side of the X axis, this because it has physical limitations due to its position.
3. The stepper motor (M3) that performs the q3 turn, should only be able to get in line with the previous link and make a downward turn with a maximum angle of 150 °.
4. M2 and M3 motors must have sensors that indicate the start and end of the stroke to avoid damage to the equipment. If the system detects that one of the limit sensors has been activated, then it must stop and warn that it has reached the end through one of 4 LEDs.
5. The system must include a method to select from the computer screen and through serial communication, which motor we want to move.
6. Once the motor is selected, it must be moved back and forth through 2 computer keys (F and B) in pulse-to-pulse format (Jogging), also through serial communication.
7. The data of which motor is moving (Motor #) and the angle value (Angle =) should be displayed on the LCD screen connected to the AVR microcontroller.
8. Once this system allows the proper movement of the 3 motors, the motors will be moved to a specific point.
9. When the system reaches the desired position for each of the 3 links, it should be permanently stored in the microcontroller memory, the AVR's EEPROM memory.
10. A total of 10 positions must be stored.
11. The program must return to the origin to carry out the next point of the statement 12. The system must have a button that can execute (RUN) the movement of the 3 links in sequence according to the points learned and finally return the system to the beginning once you finish going through all the points.
13. Additional elements may be included to improve the functionality of the system.
14. An AVR ATMEGA 2560 microcontroller or ARDUINO MEGA 2560 board must be used with programming at any level, assembler or C language.
</div>

## Problem Statement
<div align="justify" markdown="1">
You want to make a robotic arm with 3 servomotors, the first must work 360 degrees, the second has a limit of 180 degrees in one direction and the third must be able to move 150 degrees from the position of the previous one. You should be able to do all of this using the terminal. The terminal must receive data and send data directly to the microcontroller. To solve the problem, what is done is to divide the actions of the terminals into cases and when receiving information the modification of variables, which allow certain functions to be carried out in certain subroutines. Each motor must enter a different function and be limited by pulses. You must perform a function that allows you to save data and another that prints it by using FOR.
*This is a simplified dynamics model, so only basic dynamic equations were used.
</div>



## Results
In order to carry out a much more approximate analysis of the real behavior of the structure, more parameters must be taken into account to have a model closer to reality. Additionally, the structure could be improved by changing the type of materials used for construction, for ones that resemble the behavior of the structure to be modeled.

<div align="center" markdown="1">
### Proteus Schematic
![](/blog/assets/2018-05-18/dobot2.png)
</div>

<div align="center" markdown="1">
### Serial Terminal with stored positions
![](/blog/assets/2018-05-18/dobot3.png)
</div>

<div align="center" markdown="1">
### LCD with motor position
![](/blog/assets/2018-05-18/dobot4.png)
</div>

----
<div align="right" markdown="1">
[Download Arduino Code](/blog/assets/2018-05-18/BrazoRobotico1.ino) <br>
[Download Proteus Schematic](/blog/assets/2018-05-18/BrazoRobotico.pdsprj) <br>
</div>
----
<br>
