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

// This file is used only in the Reach, not the Core.
// You do not need to make any changes to this file for the Core

string getAIMoveString(const BuildingState& buildingState) {
    return "";
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
