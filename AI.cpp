/*
 * Copyright 2022 University of Michigan EECS183
 *
 * AI.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "AI.h"
#include <cassert>




//Questions:
//How do all the functions fit together
//How do we access classes that aren't listed as parameters or are we only supposed to use what is listed as parameters for the two functions given?
//How can we use BuildingState to determine a move string?
//Can we get an overview of how everything should fit together?
//How can we access the elevators and floors in building state?









// this function determines the floor with the highest anger level, and sends an empty elevator to that floor 
string sendLowestSatisfaction(BuildingState building){
    int highestAnger = 0;
    int totalFloorSatisfaction = 0;
    string moveString =  "";
    
    //1. iterate over the 10 floors
    for (int currFloor = 0; currFloor < NUM_FLOORS; currFloor++){
        //acsesses floor object of current floor
        _Floor floor = building.floors[currFloor];
        //2a. iterate over people on the floor and sum their anger level
        for (int j = 0; j < floor.numPeople; ++j) {
            _Person littleMan = floor.people[j];
            totalFloorSatisfaction += littleMan.angerLevel;
        }
        //find floor with highest anger level
        if (totalFloorSatisfaction > highestAnger){
            highestAnger = totalFloorSatisfaction;
        }
        for (int i = 0; i < NUM_ELEVATORS; ++i) {
            _Elevator elevator = building.elevators[i];
            if (!elevator.isServicing) {
                string moveString = "e" + to_string(i) + "f" + to_string(currFloor);
            }
            else{
                string moveString = "e" + to_string(i) + "p";
            }
        }
    }
    return moveString;
}





// This file is used only in the Reach, not the Core.
// You do not need to make any changes to this file for the Core

string getAIMoveString(const BuildingState& buildingState) {
        string passMove(Move& move);
    int notServicing = 0;
    for (int i = 0; i < 3; i++) {
    if (!buildingState.elevators[i].isServicing) {
        notServicing++;
    }
    if (notServicing == 3) {
        return "";
    }
}

string getAIPickupList(const Move& move, const BuildingState& buildingState, 
                       const Floor& floorToPickup) {
    return "";
}

//returns "up" if elevator should go up
//returns "down" if elevator should go down
string goUpOrDown(Floor& floor) {
    //we get number of people on the floor in question
    int numPeopleOnFloor = floor.getNumPeople();
    //by the end this should be a positive or negative value
    int sum = 0;

    for (int i = 0; i < numPeopleOnFloor; i++) {
        //we get the person at each index
        Person person = floor.getPersonByIndex(i);
        //points will be positive if they are going up and negative if going down
        int points = person.getTargetFloor() - person.getCurrentFloor();
        //add it to sum
        sum += points;
    }
    //if sum is greater than 0 there are more points to be earned by going up
    //so we return an up command
    if (sum >= 0) {
        return "up";
    }
    //if sum is less than 0 there are more points to be earned by going down
    //so we return a down command
    else {
        return "down";
    }
}

string decideBetweenTwo(const BuildingState& buildingState) {
    //first checking the servicing state of an elevator, storing elevators that aren't servicing in a temp array and storing their current floor
    int counter = 0;
    int tempElevatorsServicing[NUM_ELEVATORS] = { };
    int tempElevatorFloors[NUM_ELEVATORS] = { };
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (!buildingState.elevators[i].isServicing) {
            tempElevatorsServicing[counter] = i;
            tempElevatorFloors[counter] = buildingState.elevators[i].currentFloor;
            counter++;
        }
    }
    if (counter >= 2) {
        //then looking for floors with up/down requests
        int tempFloors[NUM_FLOORS] = { };
        int counterTwo = 0;
        for (int j = 0; j < NUM_FLOORS; j++) {
            if (buildingState.floors[j].hasUpRequest || buildingState.floors[j].hasDownRequest) {
                tempFloors[counterTwo] = j;
                counterTwo++;
            }
        }
        //now calculating distances to determine which floor to send elevators to
        string serviceMove = "ezfz";
        int floorOptions[NUM_FLOORS] = { };
        for (int k = 0; k < counterTwo; k++) {
            for (int f = 0; f < (counter - 1); f++) {
                if (abs(tempElevatorFloors[f] - tempFloors[k]) <= (abs(tempElevatorFloors[f + 1] - tempFloors[k]))) {
                    floorOptions[k] = (abs(tempElevatorFloors[f] - tempFloors[k]));
                }
                for (int h = 0; h < (counterTwo - 1); h++) {
                    if (floorOptions[h] <= floorOptions[h + 1] && tempFloors[k] != buildingState.elevators[f].currentFloor) {
                        serviceMove[1] = '0' + tempElevatorsServicing[f];
                        serviceMove[3] = '0' + tempFloors[k];
                        return serviceMove;
                    }
                }
            }
        }
    }
    return "";
}
