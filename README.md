# MicroMouse-Simulator
Micro-mouse sim software for SFHS robotics team.

## Overview
This is the Micro Mouse programming challenge for students interested in programming at Lancer Robotics. The goal of this isn't to teach students how to program an entire robot, but rather provide a challenge to teach some programming pricniples and help members get to the level where they can proficiently program the competition robot.

## Instructions
Open the MicroMouse-Simulator\microMouseServer\microMouseServer folder and access the studentai.cpp file. This is the file that you will edit to write your maze solving algorithm. Specific instructions on what you can and cannot do are in the comments of the studentai.cpp file but they are also written below as a reference.

* The following are the eight functions that you can call. Feel free to create your own fuctions as well. Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 
- The following functions return if there is a wall in their respective directions

```cpp
bool isWallLeft();
bool isWallRight();
bool isWallForward();
```

 - The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
```cpp
bool moveForward();
void turnLeft();
void turnRight();
```

  - The following functions are called when you need to output something to the UI or when you have finished the maze
```cpp
void foundFinish();
void printUI(const char *mesg);
```
