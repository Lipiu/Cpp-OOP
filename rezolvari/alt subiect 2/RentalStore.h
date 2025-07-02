/*
Define a class RentalStore that has a collection of Movie objects.

✅ Implement methods to:

add a new movie

display all movies

✅ Test these methods in your main().
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "Movie.h"
using namespace std;

class RentalStore{
private:
    vector<Movie> movies;

public:
    RentalStore(){}

    void add_movie(const Movie& m){
        movies.push_back(m);
    }

    void display_info(){
        cout << "Movie list" << endl;
        for(int i = 0; i < movies.size(); i++){
            cout << "Movie #" << (i + 1) << " | ";
            
            if(movies[i].get_title() != nullptr){
                cout << "Title: " << movies[i].get_title() << " | ";
            }
            
            if(movies[i].get_director() != nullptr){
                cout << "Director: " << movies[i].get_director() << " | ";
            }
            cout << "Release year: " << movies[i].get_year() << " | " << "Rental price: " << movies[i].get_price() << endl;
        }
    }
};