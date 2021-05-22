---
layout: article
title: AR with Vuforia in Unity
tags: Programming
article_header:
  type: overlay
  theme: dark
  background_color: '#203028'
  background_image:
    gradient: 'linear-gradient(135deg, rgba(34, 139, 87 , .4), rgba(139, 34, 139, .4))'
    src: /blog/assets/2019-05-21/image11.png
aside:
  toc: true
author: true
license: false
---
AR Project for the lab.

<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image1.png)
</div>

<!--more-->
## Idea
<div align="justify" markdown="1">
The idea is an application that allows scanning images of different electronic components. These components when scanned will display a 3D model of the component and a button which when pressed will start the reproduction of an audio or video explaining a little more about the component, this in order to help the career of Mechatronic Engineering in the part training and education.
By having a short description of the components, students, technicians or employees of a factory or school will be able to have a better view of the elements that are being used.
</div>


## Challenge
<div align="justify" markdown="1">
The biggest challenge in the application is finding a way to interactively present the audio or video with the description of the selected component.
Another challenge is to come up with a way in which multiple images can be read at the same time, as well as being able to only interactively activate 1 of the components if many images are present.
Finally, modifying some scripts so that the application works properly under the expected needs.
</div>

### Multitargets
<div align="justify" markdown="1">
To do this, I just create a new database with a cube in Vuforia, this cube had to present the appropriate measurements and individually put each image on each face. In Unity, only a new target is added, and the multitarget is set for the cube.
</div>

### Simultaneous images
<div align="justify" markdown="1">
For this, in the vuforia configuration, the number of simultaneous detection is increased.
</div>

<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image2.png)
</div>


### Animation
<div align="justify" markdown="1">
To animate a model it is necessary to enter the animation menu, select a figure and start its movements.
</div>

<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image3.png)
</div>

### Touch Screen
<div align="justify" markdown="1">
To interact with the touch screen, you need to create scripts that use the touch input function.
</div>

<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image4.png)
</div>


### Multi sound
<div align="justify" markdown="1">
For this it is important to create an audio matrix, which will contain the different audios that are wanted in the image.
</div>

<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image5.png)
![](/blog/assets/2019-05-21/image6.png)
</div>

### Interactive Video
<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image7.png)
</div>

### Animated Textures
<div align="justify" markdown="1">
For this you can add a video player to a specific figure, and make it repeat the animation over and over again, in this way you will have a continuous texture animation.
</div>

<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image8.png)
</div>

## Used Models

<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image9.png)
![](/blog/assets/2019-05-21/image10.png)
![](/blog/assets/2019-05-21/image11.png)
![](/blog/assets/2019-05-21/image12.png)
![](/blog/assets/2019-05-21/image13.png)
![](/blog/assets/2019-05-21/image14.png)
</div>

## Results

<div align="center" markdown="1">
![](/blog/assets/2019-05-21/image15.jpg)
![](/blog/assets/2019-05-21/image16.jpg)
![](/blog/assets/2019-05-21/image17.jpg)
![](/blog/assets/2019-05-21/image18.jpg)
![](/blog/assets/2019-05-21/image19.jpg)
![](/blog/assets/2019-05-21/image20.jpg)
</div>

----
<br>
