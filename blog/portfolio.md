---
layout: article
title: Favorite projects
article_header:
  type: overlay
  theme: dark
  background_color: '#203028'
  background_image:
    gradient: 'linear-gradient(135deg, rgba(34, 139, 87 , .4), rgba(139, 34, 139, .4))'
    src: /blog/assets/lights.jpg
aside:
  toc: true
---

<!--more-->

# Some of My Favorite Projects


## Pick & Place Programming with FactoryIO

<div align="justify" markdown="1">
This is a simulation of a workcell focusing on moving pieces from one conveyor band to another one. The project was done using FactoryIO's Function Block Diagram (FBD). The main purpose of this team project was managing multiple actuators and sensors at the same time resulting in a combinational system of Industrial Automation.
</div>

<div>{%- include extensions/youtube.html id='acuhO93_mGA' -%}</div>

### Connections Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image1.png)
</div>

### Actuators Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image2.png)
</div>

### Movement Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image3.png)
</div>

### FBD Inputs and Outputs from the scene
<div align="center" markdown="1">
![](/blog/assets/portfolio/image4.png)
</div>


## Robot Operating System (ROS) MoveIt and CoppeliaSim interaction

<div align="justify" markdown="1">
This team project was an effort from a team of 4 in the development of a methodology for the implementation of ROS with existing lab equipment including the UR5e, and some of the work cells that were available on the Automation and Industrial Manufacturing Lab from Universidad Anahuac. Different simulations were performed with different parameters, sensors, and different data was transmitted. The framework allowed the connection of ROS with the physical Robot and a virtual twin. An extra effort was given in the complete documentation of the whole process for future reference by the lab administrators. Data could be sent and read from the robot using ROS allowing the creation of more complex work cells in the future.
</div>

### Robot Simulation TEST
<div>{%- include extensions/youtube.html id='OIKJ00NP7Y8' -%}</div>

### Robot Communication TEST with Camera
<div>{%- include extensions/youtube.html id='Y9mHyb7ZBSk' -%}</div>

### Robot Communication with MoveIt 1
<div>{%- include extensions/youtube.html id='GqB0OjLg4gY' -%}</div>

### Robot Communication with MoveIt 2
<div>{%- include extensions/youtube.html id='b1qA0fOFD84' -%}</div>


## Pick & Place XYZ

<div align="justify" markdown="1">
This is a simulation of a workcell focusing on stacking boxes on groups 3 in a pallet. One of the actuators used in the workcell is a pick & place actuator with 3 axis and a analog configuration, that's the challenge of this workcell. The project was done using FactoryIO's Function Block Diagram (FBD). The main purpose of this team project was managing multiple bands counters and sensors at the same time and the analog actuators in a combinational system of Industrial Automation.
</div>

<div>{%- include extensions/youtube.html id='f_OAJ-TJJTs' -%}</div>

### Connections Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image5.png)
</div>

### Actuators Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image6.png)
</div>

### Movement Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image7.png)
</div>

### FBD Inputs and Outputs from the scene
<div align="center" markdown="1">
![](/blog/assets/portfolio/image8.png)
</div>


## Mandible 3D scan and print

### Introduction
Through the use of a tomography, the aim is to create a three-dimensional model of a jaw, in order to help dentists to be able to perform dental surgeries before carrying them out on real patients, in addition to the creation and analysis of jaw prostheses. .

### Objective
• Printing of the 3D model of the jaw for practice and help in operating techniques.
• Improvements in prototyping material and application to prostheses.

### Methodology

<div align="center" markdown="1">

```mermaid
graph TB;
    A001[Computed tomography of patients.]
    A002[Image processing for 3D model creation.]
    A003[Noise removal in the three-dimensional model.]
    A004[Conversion to STL format of the model.]
    A005[Mechanical simulations on the model.]
    A006[3D model printing.]
    A007[Mechanical analysis of the model.]
    A008[Use of model by dentists.]
    A009[Improvements in the manufacture of jaws and plates for prostheses of these.]
    A001-->A002;
    A002-->A003;
    A003-->A004;
    A004-->A005;
    A005-->A006;
    A006-->A007;
    A007-->A008;
    A008-->A009;

```
</div>

### Results
<div align="center" markdown="1">
![](/blog/assets/portfolio/image19.png)
</div>
<div align="center" markdown="1">
![](/blog/assets/portfolio/image20.png)
</div>

### STL
<div align="center" markdown="1">
![](/blog/assets/portfolio/image21.png)
</div>

## Assembler

<div align="justify" markdown="1">
This is a simulation of a workcell focusing on assembling a piece, made up of a lid and a base. The conveyor bands work in an asynchronous manner, so sensors must be used and programmed to determine the correct time the lid should be picked and placed on the base. A counter of the amount of items assembled is also part of the workcell. The amount of pieces can be limited just by changing a variable in the program, and the process can be stopped in case of an emergency. If no problem arises the process may continue indefinitely. This cell was programmed both with FactoryIO FBD and with the LOGO! FBD.
</div>

<div>{%- include extensions/youtube.html id='1EAT1iBKzL0' -%}</div>

### Connections Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image9.png)
</div>

### Actuators Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image10.png)
</div>

### Movement Diagram
<div align="center" markdown="1">
![](/blog/assets/portfolio/image11.png)
</div>

### FBD Inputs and Outputs from the scene
<div align="center" markdown="1">
![](/blog/assets/portfolio/image12.png)
</div>

### FactoryIO FBD Code Example

<div align="center" markdown="1">
STEP 1 <br>
![](/blog/assets/portfolio/image13.png)
</div>

<div align="center" markdown="1">
LIDS Conveyor <br>
![](/blog/assets/portfolio/image14.png)
</div>

<div align="center" markdown="1">
Emergency Stop <br>
![](/blog/assets/portfolio/image15.png)
</div>

### LOGO! FBD Code Example
<div align="center" markdown="1">
STEP 1 <br>
![](/blog/assets/portfolio/image16.png)
</div>

<div align="center" markdown="1">
LIDS Conveyor <br>
![](/blog/assets/portfolio/image17.png)
</div>

<div align="center" markdown="1">
Emergency Stop <br>
![](/blog/assets/portfolio/image18.png)
</div>

## Full Robotics Flexible Workcell

<div align="justify" markdown="1">
In this project a team of 3 worked in programming a manual flexible workcell using the MRL programming language.
By receiving a different input a different output for the Robot was generated. Depending on the previous steps and state only some actions can be done.
Upon advancing the manufacturing of the work piece different flags are activated showing a led indicator. The idea of this project was allowing the usage of HMIs in conjunction with a robot.
</div>

<div>{%- include extensions/youtube.html id='cYJgi3GVhAI' -%}</div>

[More Projects Videos on Youtube](https://www.youtube.com/channel/UCiZ_cD1wZ4FmyN7xW8ATx2g)
[Other Projects](https://cesar514.github.io/blog/archive.html)
<!-- [More Automation Click Here](2016/05/16/memorama-the-game.html) <br> -->
<!-- [More Robots and workcells Click Here](2016/05/16/memorama-the-game.html) <br> -->
<!-- [More CAD Click Here](2016/05/16/memorama-the-game.html) <br> -->
