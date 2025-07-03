/*
2p) Exemplify the concept of “is a” type relationship by specializing the previous class.The new class adds a new attribute and the parameter constructor explicitly calls the base class constructor.
Test the solution by instantiating the new class. 

(2p) Explain and exemplify the concept of abstract class.Derive one of the existing classes from the abstract class and test in the main(). 
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

class HorrorGame : public Game{
private:
    vector<Game> games;

public:
    HorrorGame(){}

    HorrorGame(const char* character_name, int new_life_points, const char* special_powers, bool villain) : Game(character_name, new_life_points, special_powers, villain){}

    ~HorrorGame(){}

    void add_game(const Game& g){
        games.push_back(g);
    }

    void display_info(){
        for(int i = 0; i < games.size(); i++){
            cout << "Game #" << (i+1) << " | ";
            if(games[i].get_character_name() != nullptr){
                cout << "Character name: " << games[i].get_character_name() << " | ";
            }
            else{
                cout << "Empty name";
            }
            cout << "Character life points: " << games[i].get_life_points() << " | ";
            if(games[i].get_special_powers() != nullptr){
                cout << "Special power: " << games[i].get_special_powers() << " | ";
            }
            else{
                cout << "Empty space";
            }
            
            if(games[i].is_villain() == false){
                cout << games[i].get_character_name() << " is hero" << endl;
            }
            else{
                cout << games[i].get_character_name() << " is villain" << endl;
            }
        }
    }

    void do_something(){
        cout << "Method from child class" << endl;
    }
};