
#include "micromouseserver.h"
int rCount = 0;
int lCount = 0;
void microMouseServer::studentAI()
{
    //180 turn around
    if (isWallRight() && isWallLeft() && isWallForward()) {
        turnRight();
        turnRight();
        moveForward();
        rCount = 0;
        lCount = 0;
    }
    //needs to go right
    else if (!isWallRight()) {
        turnRight();
        moveForward();
        rCount++;
        lCount = 0;
    }
    //needs to go left
    else if (isWallRight() && isWallForward()) {
        turnLeft();
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
