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
#include <string>




//Questions:
//How do all the functions fit together
//How do we access classes that aren't listed as parameters or are we only supposed to use what is listed as parameters for the two functions given?
//How can we use BuildingState to determine a move string?
//Can we get an overview of how everything should fit together?
//How can we access the elevators and floors in building state?









// this function determines the floor with the highest anger level, and sends an empty elevator to that floor 
/*
string getAIMoveString(const BuildingState& buildingState) {

    int floor0Satisfaction = 0;
    int floor1Satisfaction = 0;
    int floor2Satisfaction = 0;
    int floor3Satisfaction = 0;
    int floor4Satisfaction = 0;
    int floor5Satisfaction = 0;
    int floor6Satisfaction = 0;
    int floor7Satisfaction = 0;
    int floor8Satisfaction = 0;
    int floor9Satisfaction = 0;
    string myMove = "";
    
    _Elevator elevatorZero = buildingState.elevators[0];
    _Elevator elevatorOne = buildingState.elevators[1];
    _Elevator elevatorTwo = buildingState.elevators[2];
    
    if (elevatorZero.isServicing && elevatorOne.isServicing && elevatorTwo.isServicing){
        return "";
    }
    
    else{

    
    _Floor floor = buildingState.floors[0];
    //int numPeople = buildingState.floors[0].numPeople;
    for (int j = 0; j < floor.numPeople; ++j) {
        _Person littleMan = floor.people[j];
        floor0Satisfaction += littleMan.angerLevel;
    }
    cout << "the anger level of floor 0 is " << floor0Satisfaction  << endl;
    
    
    _Floor floor1 = buildingState.floors[1];
    //int numPeople1 = buildingState.floors[1].numPeople;
    for (int j = 0; j < floor1.numPeople; ++j) {
        _Person littleMan1 = floor1.people[j];
        floor1Satisfaction += littleMan1.angerLevel;
    }
    cout << "the anger level of floor 1 is " << floor1Satisfaction  << endl;
    
    _Floor floor2 = buildingState.floors[2];
    //int numPeople2 = buildingState.floors[2].numPeople;
    for (int j = 0; j < floor2.numPeople; ++j) {
        _Person littleMan2 = floor2.people[j];
        floor2Satisfaction += littleMan2.angerLevel;
    }
    cout << "the anger level of floor 2 is " << floor2Satisfaction  << endl;
    
    _Floor floor3 = buildingState.floors[3];
    //int numPeople3 = buildingState.floors[3].numPeople;
    for (int j = 0; j < floor3.numPeople; ++j) {
        _Person littleMan3 = floor3.people[j];
        floor3Satisfaction += littleMan3.angerLevel;
    }
    cout << "the anger level of floor 3 is " << floor3Satisfaction  << endl;
    
    _Floor floor4 = buildingState.floors[4];
    //int numPeople4 = buildingState.floors[4].numPeople;
    for (int j = 0; j < floor4.numPeople; ++j) {
        _Person littleMan4 = floor4.people[j];
        floor4Satisfaction += littleMan4.angerLevel;
    }
    cout << "the anger level of floor 4 is " << floor4Satisfaction  << endl;
    
    _Floor floor5 = buildingState.floors[5];
    //int numPeople5 = buildingState.floors[5].numPeople;
    for (int j = 0; j < floor4.numPeople; ++j) {
        _Person littleMan5 = floor5.people[j];
        floor5Satisfaction += littleMan5.angerLevel;
    }
    cout << "the anger level of floor 5 is " << floor5Satisfaction  << endl;
    
    _Floor floor6 = buildingState.floors[6];
    //int numPeople6 = buildingState.floors[6].numPeople;
    for (int j = 0; j < floor6.numPeople; ++j) {
        _Person littleMan6 = floor6.people[j];
        floor6Satisfaction += littleMan6.angerLevel;
    }
    cout << "the anger level of floor 6 is " << floor6Satisfaction  << endl;
    
    _Floor floor7 = buildingState.floors[7];
    //int numPeople7 = buildingState.floors[7].numPeople;
    for (int j = 0; j < floor7.numPeople; ++j) {
        _Person littleMan7 = floor7.people[j];
        floor7Satisfaction += littleMan7.angerLevel;
    }
    cout << "the anger level of floor 7 is " << floor7Satisfaction  << endl;

    _Floor floor8 = buildingState.floors[8];
    //int numPeople8 = buildingState.floors[8].numPeople;
    for (int j = 0; j < floor8.numPeople; ++j) {
        _Person littleMan8 = floor8.people[j];
        floor8Satisfaction += littleMan8.angerLevel;
    }
    cout << "the anger level of floor 8 is " << floor8Satisfaction  << endl;
    
    _Floor floor9 = buildingState.floors[9];
    //int numPeople9 = buildingState.floors[9].numPeople;
    for (int j = 0; j < floor9.numPeople; ++j) {
        _Person littleMan9 = floor9.people[j];
        floor9Satisfaction += littleMan9.angerLevel;
    }
    cout << "the anger level of floor 9 is " << floor9Satisfaction  << endl;
    
    int angerFloor[NUM_FLOORS] = {floor0Satisfaction, floor1Satisfaction, floor2Satisfaction, floor3Satisfaction, floor4Satisfaction, floor5Satisfaction, floor6Satisfaction, floor7Satisfaction, floor8Satisfaction, floor9Satisfaction};
    int anger = 0;
    int angriestFloor = 0;
 
    for (int i = 0; i < NUM_FLOORS; i ++){
        if (angerFloor[i] > anger){
            anger = angerFloor[i];
            angriestFloor = i;
        }
    }
    cout << "The angriest floor is floor " << angriestFloor << " with anger " << anger << endl;
        
        for (int i = 0; i < NUM_ELEVATORS; ++i) {
            _Elevator elevator = buildingState.elevators[i];
            if (!elevator.isServicing &&
                elevator.currentFloor != angriestFloor &&
                //TARGET FLOOR ISSUE
                angriestFloor != elevatorZero.targetFloor && angriestFloor != elevatorOne.targetFloor && angriestFloor != elevatorTwo.targetFloor) {
                string myMove = "e" + to_string(i) + "f" + to_string(angriestFloor);
                return myMove;
            }
        }
    }
    return   "";
}
*/ 





// This file is used only in the Reach, not the Core.
// You do not need to make any changes to this file for the Core

string getAIMoveString(const BuildingState& buildingState) {

//this function will determine who to pick up based on which direction we can score the most points in 
//We pick up everyone on going in the direction that will earn us more points
string getAIPickupList(const Move& move, const BuildingState& buildingState, 
                       const Floor& floorToPickup) {
    //number of people on the given floor
    int numPeopleOnFloor = floorToPickup.getNumPeople();
    //first we need to check if theres actually people to pick up
    if (numPeopleOnFloor > 0) {
        //we do this just to find the index of the floor we're working with
        int floorIndex = floorToPickup.getPersonByIndex(0).getCurrentFloor();
        int sum = 0;
        //loop through people on floor
        //add to sum the differernce between target floor and current floor
        for (int i = 0; i < numPeopleOnFloor; i++) {
            Person person = floorToPickup.getPersonByIndex(i);
            int points = person.getTargetFloor() - person.getCurrentFloor();
            sum += points;
        }
        //to be returned at end
        string result = "";
        if (sum >= 0) {
            for (int i = 0; i < numPeopleOnFloor; i++) 
                //unsure about format of return string
                //also do i need to static cast i to string
                if (floorToPickup.getPersonByIndex(i).getTargetFloor() > floorIndex) {
                    result += to_string(i);
                }
            }
        else if (sum < 0) {
            for (int i = 0; i < numPeopleOnFloor; i++) {
                //unsure about format of return string
                //also do i need to static cast i to string
                if (floorToPickup.getPersonByIndex(i).getTargetFloor() < floorIndex) {
                    result += to_string(i);
                }
            }
        }
        return result;
    }
    else {
        return "";
    }
    
}

    string passMove(Move& move) {
        int notServicing = 0;
        for (int i = 0; i < 3; i++) {
            if (!buildingState.elevators[i].isServicing) {
                notServicing++;
            }
        }
        if (notServicing == 3) {
            return "";
        }
    }

    string prioritizeTopBottom(Move& move) {
       int floorAngerTop = 0;
        int floorAngerBottom = 0;
        string userMove;
            for (int i = 0; i < buildingState.floors[9].numPeople; i++) {
                floorAngerTop += buildingState.floors[9].people[i].angerLevel;
            }
            for (int i = 0; i < buildingState.floors[0].numPeople; i++) {
                floorAngerBottom += buildingState.floors[0].people[i].angerLevel;
            }

                for (int i = 0; i < 3; i++) {
                    if (!buildingState.elevators[i].isServicing) {
                        if (floorAngerTop > floorAngerBottom) {
                        userMove = "e" + to_string(i) + "f9";
                        }
                        if (floorAnherBottom > floorAngerTop) {
                        userMove = "e" + to_string(i) + "f0";
                        }
                    }
                }
        return userMove;
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
    
    
string makePickupMove(const BuildingState& buildingState) {
    for (int i = 0; i < 3; i++) {
        if (buildingState.elevators[i].currentFloor == buildingState.elevators[i].targetFloor
            && buildingState.elevators[i].isServicing == false) {
            string result = "e" + to_string(buildingState.elevators[i].currentFloor) + "p";
            return result;
        }
    }
}
