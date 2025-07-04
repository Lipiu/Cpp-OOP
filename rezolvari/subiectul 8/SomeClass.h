#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "TouristPoint.h"
#include <iostream>
using namespace std;

class SomeClass : TouristPoint{
private:
    int number_of_tourists = 0;
public:
    SomeClass(){}

    SomeClass(int num_tourists, int distance, const char* duration, const char* points_of_interest):TouristPoint(distance, duration, points_of_interest){
        cout << "Constructor from child class" << endl;
        this->number_of_tourists = num_tourists;
    }

    void do_something(){
        cout << "Method from child class" << endl;
    }
};