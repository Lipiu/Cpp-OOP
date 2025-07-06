/*
(2p) Exemplify the concept oftype relationship “is a” by specializing the previous class. 
The new class adds a new attribute and the parameter constructor explicitly calls the base class constructor. 
Test the solution by instantiating the new class. 
(2p) Explain and exemplify the concept of late-binding by defining a virtual method in the base class.
*/

#pragma once
#include "TouristPoint.h"
#include <string>
#include <iostream>
using namespace std;

class Hike : public TouristPoint{
private:
    string difficulty = "";

public:
    Hike(string difficulty, int distance, const char* tourist_points, int duration, string points_of_interest) : 
    TouristPoint(distance, tourist_points, duration, points_of_interest){
        this->difficulty = difficulty;
    }

    void do_something() override{
        cout << "Method from child class" << endl;
    }
};