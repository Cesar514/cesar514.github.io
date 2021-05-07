---
layout: article
title:  MEMORAMA THE GAME
tags: Programming
article_header:
  type: overlay
  theme: dark
  background_color: '#203028'
  background_image:
    gradient: 'linear-gradient(135deg, rgba(34, 139, 87 , .4), rgba(139, 34, 139, .4))'
    src: /blog/assets/2016-05-16/startscreen.png
aside:
  toc: true
author: true
---
Algorithms and Programming Class Project
<div align="center" markdown="1">
![](/blog/assets/2016-05-16/mem1.png)
</div>
<!--more-->
## Objective

<div align="justify" markdown="1">

Make a Memorama game with the knowledge acquired throughout the school year, programming it with GAMBAS which will allow a broad demonstration of the student's abilities. A mix of all the acquired knowledge and a way of showing how programming can be used for practical purposes.

</div>

## Problem Statement

<div align="justify" markdown="1">
The number of players is requested, starting with player 1, then 2 and so on until the last player.
Each player has 2 movements per turn, if the player turns over 2 even cards, then the player has another turn, his score increases and these cards leave the game, if the cards are different, it's the next player's turn. The game will continue until all cards have been eliminated with their pairs. The player with the highest number of pairs revealed is the winner. In the event of a tie, the winner is the first to obtain the maximum score. There are secrets in the game that must be discovered.
</div>

*A little bit of the code*:

```
Public Sub Form_Open()
  Dim num As Byte
  num = Jugadores.numjugadores
  Print num
  If num > 1 Then
    label1.visible = True
    label2.visible = True
    textbox1.visible = True
    textbox2.visible = True
  Endif
  If num > 2 Then
    label3.visible = True
    textbox3.visible = True
  Endif
  If num > 3 Then
    label4.visible = True
    textbox4.visible = True
  Endif
  If num > 4 Then
    label5.visible = True
    textbox5.visible = True
  Endif
  If num > 5 Then
    label6.visible = True
    textbox6.visible = True
  Endif
End
```

## Game Screens
<!-- Here are some images of the project -->
<div align="center" markdown="1">
### **Start Screen**
![](/blog/assets/2016-05-16/startscreen.png)
</div>


<div align="center" markdown="1">
### **Player Screen**
![](/blog/assets/2016-05-16/playerscreen.png)
</div>


<div align="center" markdown="1">
### **Game Screen #1**
![](/blog/assets/2016-05-16/gamescreen_1.png)
</div>


<div align="center" markdown="1">
### **Game Screen #2**
![](/blog/assets/2016-05-16/gamescreen_2.png)
</div>


<div align="center" markdown="1">
### **End Screen**
![](/blog/assets/2016-05-16/endscreen.png)
</div>


<div align="center" markdown="1">
### **Winner Screen**
![](/blog/assets/2016-05-16/winnerscreen.png)
</div>


## Conclusions
<div align="justify" markdown="1">
A video game is a set of algorithms that when used simultaneously generates fun for the user. The conditions, cycles and each of the arguments that are part of it give it a little more emotion.
Hundreds of different programs and games can be achieved, with different combinations. Throughout the school year, the use and management of a logical structure was learned, and it was applied through GAMBAS programming language.
</div>

----
<br>
