
#include "micromouseserver.h"
#define myTurnLeft() turnLeft(); dir = (dir+3)%4;
#define myTurnRight() turnRight(); dir = (dir+1)%4;
#include <iostream>


int rCount = 0;
int lCount = 0;

//array with data on how much each square has been checked
int checked[20][20];
bool firstRun = true;

int xc = 0; int yc = 0;

//dir: 0 -> north, 1-> east, 2->south, 3 -> west,
int dir = 0;
void microMouseServer::studentAI()
{
    //fills array with zeros
    if (firstRun == true) {
        for (int i = 0; i < 20; i++) {
            for (int j =0; j<20; j++) {
                checked[i][j] = 0;
            }
        }
        firstRun = false;
    }

    //for 180s
    if (isWallRight() && isWallLeft() && isWallForward()) {
        myTurnRight();
        myTurnRight();
        rCount = 0;
        lCount = 0;
        return;
    }

    //keeps track of how many times the squares around mouse has been checked using dir
    int left = 0; int right = 0; int forward = 0;
    if (dir == 0) {
        if (isWallLeft()) {
            left = 9999;
        }
        else {
            left = checked[xc-1][yc];
        }
        if (isWallRight()) {
            right = 9999;
        }
        else {
            right = checked[xc+1][yc];
        }
        if (isWallForward()) {
            forward = 9999;
        }
        else {
            forward = checked[xc][yc+1];
        }
    } else if (dir == 1) {
        if (isWallLeft()) {
            left = 9999;
        }
        else {
            left = checked[xc][yc+1];
        }
        if (isWallRight()) {
            right = 9999;
        }
        else {
            right = checked[xc][yc-1];
        }
        if (isWallForward()) {
            forward = 9999;
        }
        else {
            forward = checked[xc+1][yc];
        }
    } else if (dir == 2) {
        if (isWallLeft()) {
            left = 9999;
        }
        else {
            left = checked[xc+1][yc];
        }
        if (isWallRight()) {
            right = 9999;
        }
        else {
            right = checked[xc-1][yc];
        }
        if (isWallForward()) {
            forward = 9999;
        }
        else {
            forward = checked[xc][yc-1];
        }
    } else if (dir == 3) {
        if (isWallLeft()) {
            left = 9999;
        }
        else {
            left = checked[xc][yc+1];
        }
        if (isWallRight()) {
            right = 9999;
        }
        else {
            right = checked[xc][yc-1];
        }
        if (isWallForward()) {
            forward = 9999;
        }
        else {
            forward = checked[xc-1][yc];
        }
    }

    //uses the numbers from earlier to find which square has been checked the least (modified right hand rule)
    if (left < forward and left < right) {
        myTurnLeft();
        lCount++;
        rCount = 0;
    } else if (forward < right) {
        rCount = 0;
        lCount = 0;
    } else {
        myTurnRight();
        rCount++;
        lCount = 0;
    }
    moveForward();

    //updates the coordinates after movement
    if (dir == 0) {
        yc++;
    } else if (dir == 2) {
        yc--;
    } else if (dir == 1) {
        xc++;
    } else if (dir == 3) {
        xc--;
    }

    //updates checked count of each square
    checked[xc][yc] += 1;

    //going through a 2x2 square should result in 3 right turns, so this checks for that situation and marks the finish
    if ((rCount == 3) || (lCount == 3)) {
        foundFinish();
        return;
    }
}
