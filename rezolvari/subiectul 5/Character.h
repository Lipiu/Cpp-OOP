/*
(3p) It is considered an application used to manage the characters in a computer / mobile game.
Specific attributes will be followed, such as: character name, life points, special powers, whether he is a positive or negative hero, etc. 
Member data is private or protected.The class contains at least three fields, of which one is dynamically allocated, a parameter constructor, destructor, accessory methods (get and set) for one of the attributes. 
Use a static or const.The set() method validates the input data. 

(1p) Overload the += operator in the form object += value to change the value of an attribute. 

1p) Define the >= operator that compares two objects and returns true based on the value ​​of an attribute. 

2p) Exemplify the concept of “is a” type relationship by specializing the previous class.The new class adds a new attribute and the parameter constructor explicitly calls the base class constructor.
Test the solution by instantiating the new class. 

(2p) Explain and exemplify the concept of abstract class.Derive one of the existing classes from the abstract class and test in the main(). 

(1p) Explain and exemplify the concept of “dangling pointer” using a pointer to one of the previously defined classes. 
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "Abstract.h"
using namespace std;

class Character : Abstract{
private:
    char* character_name = nullptr;
    int life_points = 0;
    char* special_power = nullptr;

    const int character_id;
    static int counter;

public:
    Character():character_id(++counter){}

    Character(const char* character_name, int life_points, const char* special_power):character_id(++counter){
        cout << "Ctor with parameters from parent class" << endl;
        this->set_character_name(character_name);
        this->life_points = life_points;
        this->set_power(special_power);
    }

    // Character(Character& c):character_id(++counter){
    //     this->set_character_name(c.get_character_name());
    //     this->life_points = life_points;
    //     this->set_power(c.get_powers());
    // }

    ~Character(){
        delete[] this->character_name;
        delete[] this->special_power;
        this->character_name = nullptr;
        this->special_power = nullptr;
    }

    char* get_character_name() {
        char* copy = new char[strlen(this->character_name) + 1];
        strcpy(copy, this->character_name);
        return copy;
    }

    char* get_powers(){
        char* copy = new char[strlen(this->special_power) + 1];
        strcpy(copy, this->special_power);
        return copy;
    }

    int get_life_points(){
        return this->life_points;
    }

    void set_character_name(const char* character_name){
        if(character_name == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->character_name;
            this->character_name = new char[strlen(character_name) + 1];
            strcpy(this->character_name, character_name);
        }
    }

    void set_life_points(int points){
        if(points < 0){
            throw "Life points cannot be negative";
        }
        else{
            this->life_points = points;
        }
    }

    void set_power(const char* special_power){
        if(special_power == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->special_power;
            this->special_power = new char[strlen(special_power) + 1];
            strcpy(this->special_power, special_power);
        }
    }

    Character& operator+=(int value){
        this->life_points += value;
        return *this;
    }

    bool operator>=(const Character& other){
        if(this->life_points >= other.life_points){
            return true;
        }
        else{
            return false;
        }
    }

    void do_something() override{
        cout << "do_something from Character class" << endl;
    }
};

int Character::counter = 0;