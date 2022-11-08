/*
 * Copyright 2022 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

void elevator_tests();

using namespace std;

// declare your test functions here

void start_tests() {
    elevator_tests();
    
    return;
}

// write test functions here
void elevator_tests() {

    //testing tick
    Elevator elevator1;
    elevator1.setCurrentFloor(4);
    elevator1.serviceRequest(1);
    int currentTime1 = 1;
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    elevator1.tick(currentTime1);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    


    int currentTime2 = 0;
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    elevator1.tick(currentTime2);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;

    double currentTime3 = 2.5;
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    elevator1.tick(currentTime3);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    
    Elevator elevator2;
    elevator2.setCurrentFloor(3);
    elevator2.serviceRequest(3);
    int currentTime4 = 2;
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    elevator2.tick(currentTime4);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;

    elevator2.setCurrentFloor(0);
    elevator2.serviceRequest(3);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    elevator2.tick(currentTime4);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;

    elevator2.setCurrentFloor(5);
    elevator2.serviceRequest(0);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    elevator2.tick(currentTime4);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;

    int currentTime5 = 2;
    elevator2.setCurrentFloor(0);
    elevator2.serviceRequest(0);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
    elevator2.tick(currentTime5);
    cout << elevator1.getCurrentFloor() << endl;
    cout << elevator1.getTargetFloor() << endl;
}
