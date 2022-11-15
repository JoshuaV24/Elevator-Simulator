/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Move.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */
 
#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    //if the command string is empty
    //the user has selected a pass move
    if (commandString == "") {
        isPass = true;
        return;
    }
    //if the command string's first letter is s
    //then it is a save game
    else if (commandString[0] == 's'
        || commandString[0] == 'S') {
        isSave = true;
        return;
    }
    //if the command string's first letter is q
    //it is a quit game command
    else if (commandString[0] == 'q' ||
        commandString[0] == 'Q') {
        isQuit = true;
        return;
    }
    //if the first letter of the command
    //string is e, then it is a service move
    //or a pickup move
    else if (commandString[0] == 'e') {
        elevatorId = commandString[1];
        if (commandString[2] == 'p') {
            isPickup = true;
            return;
        }
        else if (commandString[2] == 'f') {
            targetFloor = commandString[3];
            return;
        }
    }
}

bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    if (isPass || isQuit || isSave) {
        return true;
    }
    else if (isPickup && 0 <= getElevatorId() && getElevatorId() < NUM_ELEVATORS 
             && &Elevator::isServicing) {
        return true;
    }
    else if (0 <= targetFloor && targetFloor < NUM_FLOORS 
             && getTargetFloor() != elevators->getCurrentFloor()) {
        return true;
    }
}

void Move::setPeopleToPickup(const string& pickupList, const int currentFloor, const Floor& pickupFloor) {
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    int copy[MAX_PEOPLE_PER_FLOOR] = { };

    // reads in each number from pickupList to peopleToPickup
    for (int i = 0; i < pickupList.length(); i++) {
        copy[i] = pickupList[i];
        numPeopleToPickup += 1;
        // setting satisfaction level
        Person anger[MAX_PEOPLE_PER_FLOOR] = { };
        int angerLevel = anger[i].getAngerLevel();
        totalSatisfaction += (MAX_ANGER - angerLevel);
    }
    //copying over pickupList to peopleToPickup
    copyListOfPeopleToPickup(copy);
    
    // calculating targetFloor
    for (int j = 0; j < (pickupList.length() -  1); j++) {
        Move target[MAX_PEOPLE_PER_FLOOR] = { };
        int tempTarget = 0;
        if (abs(target[j].getTargetFloor() - currentFloor) > abs(target[j + 1].getTargetFloor() - currentFloor)) {
            setTargetFloor(target[j].getTargetFloor());
        }
    }
} 

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
	isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
	return isPass;
}

bool Move::isSaveMove() const {
	return isSave;
}

bool Move::isQuitMove() const {
	return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
