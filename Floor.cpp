/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Floor.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */


#include "Floor.h"
#include <algorithm>

using namespace std;

int Floor::tick(int currentTime) {
	int explodedCounter = 0;
	int temp[MAX_PEOPLE_PER_FLOOR] = { };
	for (int i = 0; i < numPeople; i++) {
		if (getPersonByIndex(i).tick(currentTime)) {
			temp[explodedCounter] = i;
			explodedCounter += 1;
		}
	}
	removePeople(temp, explodedCounter);
	return explodedCounter;
}
void Floor::addPerson(Person newPerson, int request) {
    if (numPeople < MAX_PEOPLE_PER_FLOOR){
        people[numPeople] = newPerson;
        numPeople += 1;
        }
    if (request > 0){
    hasUpRequest = true;
    }
    else {
    hasDownRequest = true;
    }
}

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], int numPeopleToRemove) {
    	//copy indicesToRemove into new array
	int newArray[MAX_PEOPLE_PER_FLOOR];
	int size = numPeopleToRemove;
	copy(indicesToRemove, indicesToRemove + size, newArray);
	//start by sorting indicesToRemove
	sort(newArray, newArray + numPeopleToRemove);
	//we want to carry out the removal operation
	//for each element in the indicesToRemove array
	for (int i = 0; i < numPeopleToRemove; i++) {
		//this represents the index of the person we need to remove
		int personToRemove = newArray[i];
		for (int j = personToRemove; j < numPeople - 1; j++) {
			//so we shift everything down by one
			//but the last index is repeated
			people[j] = people[j + 1];
		}
		//to remove the trailing element, we adjust the size 
		//of the array
		numPeople -= 1;
		//because array shifted back by one
		//all of the indicesToRemove need to be
		//decremented by one
		for (int z = 0; z < numPeopleToRemove; z++) {
			newArray[z] -= 1;
		}

	}
	//resets requests
	resetRequests();
}

void Floor::resetRequests() {
	setHasDownRequest(false);
	setHasUpRequest(false);
	for (int i = 0; i < numPeople; i++) {
		int current = 0;
		int target = 0;
		current = people[i].getCurrentFloor();
		target = people[i].getTargetFloor();
		if (current > target) {
			setHasDownRequest(true);
		}
		else if (current < target) {
			setHasUpRequest(true);
		}
	}
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
	string up = "U";
	outs << (hasUpRequest ? up : " ") << " ";
	for (int i = 0; i < numPeople; ++i){
		outs << people[i].getAngerLevel();
		outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
	}
	outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
	string down = "D";
	outs << (hasDownRequest ? down : " ") << " ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "o   ";
	}
	outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
	cout << endl;
	outs << "Select People to Load by Index" << endl;
	outs << "All people must be going in same direction!";
	/*  O   O
	// -|- -|-
	//  |   |
	// / \ / \  */
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " O   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "-|-  ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " |   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "/ \\  ";
	}
	outs << endl << "INDEX:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << i << "   ";
	}
	outs << endl << "ANGER:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getAngerLevel() << "   ";
	}
	outs << endl << "TARGET FLOOR: ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getTargetFloor() << "   ";
	}
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
	return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
	return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
