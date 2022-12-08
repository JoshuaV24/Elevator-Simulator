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

 //Questions:
 //How do all the functions fit together
 //How do we access classes that aren't listed as parameters or are we only supposed to use what is listed as parameters for the two functions given?
 //How can we use BuildingState to determine a move string?
 //Can we get an overview of how everything should fit together?
 //How can we access the elevators and floors in building state?



#include "AI.h"
#include <cassert>
#include <string>

// This file is used only in the Reach, not the Core.
// You do not need to make any changes to this file for the Core


string makePickupMove(const BuildingState& buildingState) {
    string result;

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (buildingState.elevators[i].currentFloor == buildingState.elevators[i].targetFloor &&
            buildingState.elevators[i].isServicing == false &&
            !(buildingState.floors[buildingState.elevators[i].currentFloor].hasUpRequest && buildingState.floors[buildingState.elevators[i].currentFloor].hasDownRequest)) {
            result = "e" + to_string(i) + "p";
            int currFloor = buildingState.elevators[i].currentFloor;
            int targetFloor = buildingState.elevators[i].targetFloor;
            cout << "For elevator " << i << " CF: " << currFloor << " TF: " << targetFloor << " IS: " << buildingState.elevators[i].isServicing << endl;
            return result;
        }
    }
    return result;
}



bool isTherePickupMove(const BuildingState& buildingState) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (buildingState.elevators[i].currentFloor == buildingState.elevators[i].targetFloor &&
            buildingState.elevators[i].isServicing == false &&
            (buildingState.floors[buildingState.elevators[i].currentFloor].numPeople >= 1)) {
            int targetFloor = buildingState.elevators[i].targetFloor;
            int currFloor = buildingState.elevators[i].currentFloor;
            cout << "IPM: For elevator " << i << " CF: " << currFloor << " TF: " << targetFloor << " IS: " << buildingState.elevators[i].isServicing << endl;
            cout << "there is pickup move" << endl;
            return true;
        }
    }
    cout << "no pickup move" << endl;
    return false;
}

string pickupTime(const BuildingState& buildingState) {
    string result;

    for (int i = 0; i < 3; i++) {
        if (buildingState.elevators[i].currentFloor == buildingState.elevators[i].targetFloor &&
            buildingState.elevators[i].isServicing == false &&
            (buildingState.floors[buildingState.elevators[i].currentFloor].numPeople >= 1)) {
            result = "e" + to_string(i) + "p";
            int targetFloor = buildingState.elevators[i].targetFloor;
            int currFloor = buildingState.elevators[i].currentFloor;
            cout << "PT: For elevator " << i << " CF: " << currFloor << " TF: " << targetFloor << " IS: " << buildingState.elevators[i].isServicing << endl;
            cout << "there is pickup move" << endl;
            return result;
        }
    }
    cout << "no pickup move" << endl;
    return result;

}


bool isFloorOneOrNine(const BuildingState& buildingState) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (buildingState.elevators[i].currentFloor == 8 ||
            buildingState.elevators[i].currentFloor == 1) {
            cout << "F1or9" << endl;
            return true;
        }
    }
    cout << "no 1 or 9" << endl;
    return false;
}


string getAIMoveString(const BuildingState& buildingState) {

    //pickupTime(buildingState);

    // make pass move if all elevators are servicing
    if (buildingState.elevators[0].isServicing &&
        buildingState.elevators[1].isServicing &&
        buildingState.elevators[2].isServicing) {
        cout << "making pass move" << endl;
        return "";
    }

    //if target floor = current floor, make pickup



    /*if (isTherePickupMove(buildingState)){
        return makePickupMove(buildingState);
    }*/

    // else, continue with game:
    /*else if (isFloorOneOrNine(buildingState)){
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
                         if (floorAngerBottom > floorAngerTop) {
                         userMove = "e" + to_string(i) + "f0";
                         }
                     }
                 }
        cout << "moving to f1or9" << endl;
         return userMove;
    }*/

    else {
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

        if (elevatorZero.isServicing && elevatorOne.isServicing && elevatorTwo.isServicing) {
            return "";
        }

        else {


            _Floor floor = buildingState.floors[0];
            //int numPeople = buildingState.floors[0].numPeople;
            for (int j = 0; j < floor.numPeople; ++j) {
                _Person littleMan = floor.people[j];
                floor0Satisfaction += littleMan.angerLevel;
            }
            cout << "the anger level of floor 0 is " << floor0Satisfaction << endl;


            _Floor floor1 = buildingState.floors[1];
            //int numPeople1 = buildingState.floors[1].numPeople;
            for (int j = 0; j < floor1.numPeople; ++j) {
                _Person littleMan1 = floor1.people[j];
                floor1Satisfaction += littleMan1.angerLevel;
            }
            cout << "the anger level of floor 1 is " << floor1Satisfaction << endl;

            _Floor floor2 = buildingState.floors[2];
            //int numPeople2 = buildingState.floors[2].numPeople;
            for (int j = 0; j < floor2.numPeople; ++j) {
                _Person littleMan2 = floor2.people[j];
                floor2Satisfaction += littleMan2.angerLevel;
            }
            cout << "the anger level of floor 2 is " << floor2Satisfaction << endl;

            _Floor floor3 = buildingState.floors[3];
            //int numPeople3 = buildingState.floors[3].numPeople;
            for (int j = 0; j < floor3.numPeople; ++j) {
                _Person littleMan3 = floor3.people[j];
                floor3Satisfaction += littleMan3.angerLevel;
            }
            cout << "the anger level of floor 3 is " << floor3Satisfaction << endl;

            _Floor floor4 = buildingState.floors[4];
            //int numPeople4 = buildingState.floors[4].numPeople;
            for (int j = 0; j < floor4.numPeople; ++j) {
                _Person littleMan4 = floor4.people[j];
                floor4Satisfaction += littleMan4.angerLevel;
            }
            cout << "the anger level of floor 4 is " << floor4Satisfaction << endl;

            _Floor floor5 = buildingState.floors[5];
            //int numPeople5 = buildingState.floors[5].numPeople;
            for (int j = 0; j < floor4.numPeople; ++j) {
                _Person littleMan5 = floor5.people[j];
                floor5Satisfaction += littleMan5.angerLevel;
            }
            cout << "the anger level of floor 5 is " << floor5Satisfaction << endl;

            _Floor floor6 = buildingState.floors[6];
            //int numPeople6 = buildingState.floors[6].numPeople;
            for (int j = 0; j < floor6.numPeople; ++j) {
                _Person littleMan6 = floor6.people[j];
                floor6Satisfaction += littleMan6.angerLevel;
            }
            cout << "the anger level of floor 6 is " << floor6Satisfaction << endl;

            _Floor floor7 = buildingState.floors[7];
            //int numPeople7 = buildingState.floors[7].numPeople;
            for (int j = 0; j < floor7.numPeople; ++j) {
                _Person littleMan7 = floor7.people[j];
                floor7Satisfaction += littleMan7.angerLevel;
            }
            cout << "the anger level of floor 7 is " << floor7Satisfaction << endl;

            _Floor floor8 = buildingState.floors[8];
            //int numPeople8 = buildingState.floors[8].numPeople;
            for (int j = 0; j < floor8.numPeople; ++j) {
                _Person littleMan8 = floor8.people[j];
                floor8Satisfaction += littleMan8.angerLevel;
            }
            cout << "the anger level of floor 8 is " << floor8Satisfaction << endl;

            _Floor floor9 = buildingState.floors[9];
            //int numPeople9 = buildingState.floors[9].numPeople;
            for (int j = 0; j < floor9.numPeople; ++j) {
                _Person littleMan9 = floor9.people[j];
                floor9Satisfaction += littleMan9.angerLevel;
            }
            cout << "the anger level of floor 9 is " << floor9Satisfaction << endl;

            int angerFloor[NUM_FLOORS] = { floor0Satisfaction, floor1Satisfaction, floor2Satisfaction, floor3Satisfaction, floor4Satisfaction, floor5Satisfaction, floor6Satisfaction, floor7Satisfaction, floor8Satisfaction, floor9Satisfaction };
            int anger = 0;
            int angriestFloor = 0;

            for (int i = 0; i < NUM_FLOORS; i++) {
                int average = angerFloor[i] / buildingState.floors[i].numPeople;
                
                if (average > anger) {
                    anger = average;
                    angriestFloor = i;
                }
            }
            cout << "The angriest floor is floor " << angriestFloor << " with average anger " << average << endl;


            for (int i = 0; i < NUM_ELEVATORS; ++i) {
                _Elevator elevator = buildingState.elevators[i];
                if (!elevator.isServicing &&
                    elevator.currentFloor != angriestFloor &&
                    //TARGET FLOOR ISSUE
                    angriestFloor != elevatorZero.targetFloor && angriestFloor != elevatorOne.targetFloor && angriestFloor != elevatorTwo.targetFloor) {
                    if (abs(buildingState.elevators[i].currentFloor - angriestFloor) <=
                        (abs(buildingState.elevators[i + 1].currentFloor - angriestFloor))) {
                        string myMove = "e" + to_string(i) + "f" + to_string(angriestFloor);
                        return myMove;
                    }
                }
                else if ((buildingState.elevators[i].currentFloor == buildingState.elevators[i].targetFloor &&
                    buildingState.elevators[i].isServicing == false &&
                    (buildingState.floors[buildingState.elevators[i].currentFloor].numPeople >= 1))) {
                    myMove = "e" + to_string(i) + "p";
                    return myMove;
                }
            }
        }
        return   "";
    }
}

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
