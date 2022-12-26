
#include "micromouseserver.h"
#define myTurnLeft() turnLeft(); dir = (dir+3)%4;
#define myTurnRight() turnRight(); dir = (dir+1)%4;
#include <iostream>
//dir: 0 -> north, 1-> right, 2->down, 3 -> left,
int rCount = 0;
int lCount = 0;
int checked[20][20];
bool firstRun = true;
int x = 0; int y = 0;
int dir = 0;
void microMouseServer::studentAI()
{
    if(dir == 0){
        printUI("0");
    } else if (dir == 1) {
        printUI("1");
    } else if (dir == 2) {
        printUI("2");
    } else if (dir == 3) {
        printUI("3");
    } else {
        printUI("no");
    }
    if (firstRun == true) {
        for (int i = 0; i < 20; i++) {
            for (int j =0; j<20; j++) {
                checked[i][j] = 0;
            }
        }
        firstRun = false;
    }
    if (isWallRight() && isWallLeft() && isWallForward()) {
        myTurnRight();
        myTurnRight();
        moveForward();
        rCount = 0;
        lCount = 0;
    }
    //needs to go right
    else if (!isWallRight()) {
        myTurnRight();
        moveForward();
        rCount++;
        lCount = 0;
    }
    //needs to go left
    else if (isWallRight() && isWallForward()) {
        myTurnLeft();
        moveForward();
        lCount++;
        rCount = 0;
    }
    //needs to go forward
    else {
        moveForward();
        lCount = 0;
        rCount = 0;
    }
    if ((rCount == 3) || (lCount == 3)) {
        foundFinish();
        return;
    }
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/

}
