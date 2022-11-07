/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Elevator.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "Elevator.h"
#include <iostream>

using namespace std;

void Elevator::tick(int currentTime) {
    //remainder is zero if TICKS_PER_ELEVATOR_MOVE
    //divides currentTime
    if (currentTime % TICKS_PER_ELEVATOR_MOVE == 0) {
        //currentFloor is above targetFloor so decrement
        if (currentFloor > targetFloor) {
            currentFloor -= 1;
        }
        //currentFloor is below targetFloor so increment
        else if (targetFloor > currentFloor) {
            currentFloor += 1;
        }
        //servicing set to false if current is target
        if (currentFloor == targetFloor) {
            servicing = false;
        }
    }
}

void Elevator::serviceRequest(int floorNum) {
    //the targetFloor is set to the parameter
    targetFloor = floorNum;
    //the elevator is servicing now
    servicing = true;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

void Elevator::print(ostream &outs) {
    outs << currentFloor;
    if (!servicing){
        outs << "w";
    } else {
        outs << "s" << targetFloor;
    }
}

Elevator::Elevator() {
    currentFloor = 0;
    servicing = false;
	targetFloor = 0;
}

void Elevator::setCurrentFloor(int currentFloorIn) {
    currentFloor = currentFloorIn;
}

bool Elevator::isServicing() const {
	return servicing;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

int Elevator::getTargetFloor() const {
    return targetFloor;
}
