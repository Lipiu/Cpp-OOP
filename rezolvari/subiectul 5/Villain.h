/*
2p) Exemplify the concept of “is a” type relationship by specializing the previous class.The new class adds a new attribute and the parameter constructor explicitly calls the base class constructor.
Test the solution by instantiating the new class. 
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Character.h"
#include "Abstract.h"
#include <iostream>
using namespace std;

class Villain : public Character{
private:
    bool is_villain = false;

public:
    Villain(bool is_villain, const char* character_name, int life_points, const char* special_power):Character(character_name, life_points, special_power){
        cout << "Ctor from child class" << endl;
        this->is_villain = is_villain;
    }

    void do_something() override{
        cout << "do_something from Villain class" << endl;
    }
};