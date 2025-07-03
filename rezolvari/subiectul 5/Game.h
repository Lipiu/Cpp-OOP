/*
(3p) It is considered an application used to manage the characters in a computer / mobile game.Specific attributes will be followed, 
such as: character name, life points, special powers, whether he is a positive or negative hero, etc. 
Member data is private or protected.
The class contains at least three fields, of which one is dynamically allocated, 
a parameter constructor, 
destructor, 
accessory methods (get and set) for one of the attributes. 
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
using namespace std;

class Game{
private:
    char* character_name = nullptr;
    int life_points = 0;
    char* special_powers = nullptr;
    bool is_negative_hero = false;

    const int character_id;
    static int character_counter;

public:
    Game():character_id(++character_counter){}

    Game(const char* character_name, int new_life_points, const char* special_powers, bool villain):character_id(++character_counter){
        this->set_character_name(character_name);
        this->life_points = new_life_points;
        this->set_special_powers(special_powers);
        is_negative_hero = villain;
    }

    Game(const Game& g):character_id(++character_counter){
        if(g.character_name != nullptr){
            character_name = new char[strlen(g.character_name) + 1];
            strcpy(character_name, g.character_name);
        }
        else{
            character_name = nullptr;
        }

        if(g.special_powers != nullptr){
            special_powers = new char[strlen(g.special_powers) + 1];
            strcpy(special_powers, g.special_powers);
        }
        else{
            special_powers = nullptr;
        }

        life_points = g.life_points;
        is_negative_hero = g.is_negative_hero;
    }

    ~Game(){
        delete[] this->character_name;
        delete[] this->special_powers;
        this->character_name = nullptr;
        this->special_powers = nullptr;
    }

    bool is_villain(){
        if(this->is_negative_hero == false){
            return false;
        }
        else{
            return true;
        }
    }

    char* get_character_name() const{
        return this->character_name;
    }

    int get_life_points() const{
        return this->life_points;
    }

    char* get_special_powers() const{
        return this->special_powers;
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

    void set_life_points(int life_points){
        if(life_points < 0){
            throw "Life points cannot be negative.";
        }
        else{
            this->life_points = life_points;
        }
    }

    void set_special_powers(const char* special_powers){
        if(special_powers == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->special_powers;
            this->special_powers = new char[strlen(special_powers) + 1];
            strcpy(this->special_powers, special_powers);
        }
    }

    // Overload the += operator in the form object += value to change the value of an attribute. 
    Game& operator+=(int points){
        this->life_points += points;
        return *this;
    }

    // Define the >= operator that compares two objects and returns true based on the value ​​of an attribute. 
    bool operator>=(const Game& new_game){
        return life_points >= new_game.life_points; 
    }

    virtual void do_something(){
        cout << "Method from parent class" << endl;
    }
};

int Game::character_counter = 0;