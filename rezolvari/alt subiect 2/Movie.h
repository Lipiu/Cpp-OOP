/*
(3p) Class Design
Define a class Movie that models a movie in a rental shop. The class should:

Have at least four attributes, e.g.:
title (dynamically allocated char*)
director (dynamically allocated char*)
release year (int)
rental price (float)

Contain:
a static attribute to count how many movies have been created
a const attribute (e.g. movie ID)

a parameterized constructor
a destructor that correctly frees memory
getters and setters for at least one attribute
setters should validate data (e.g. price can’t be negative)
Overload the + operator in the form: value + object
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

class Movie{
private:
    char* title = nullptr;
    char* director = nullptr;
    int release_year = 0;
    float rental_price = 0.0;

    static int movie_counter;
    const int movie_id;

public:
    Movie():movie_id(++movie_counter){}

    Movie(const char* title, const char* director, int new_release_year, float new_rental_price):movie_id(++movie_counter){
        this->set_title(title);
        this->set_director(director);
        release_year = new_release_year;
        rental_price = new_rental_price;
    }

    ~Movie(){
        delete[] this->title;
        delete[] this->director;
        this->title = nullptr;
        this->director = nullptr;
    }

    const char* get_title(){
        return this->title;
    }

    const char* get_director(){
        return this->director;
    }

    int get_year(){
        return this->release_year;
    }

    float get_price(){
        return this->rental_price;
    }

    void set_title(const char* new_title){
        if(new_title == nullptr){
            throw "Title cannot be empty";
        }
        else{
            delete[] this->title;
            this->title = new char[strlen(new_title) + 1];
            strcpy(this->title, new_title);
        }
    }

    void set_director(const char* new_director){
        if(new_director == nullptr){
            throw "Director field cannot be empty";
        }
        else{
            delete[] this->director;
            this->director = new char[strlen(new_director) + 1];
            strcpy(this->director, new_director);
        }
    }

    void set_price(float new_price){
        if(new_price < 0){
            throw "Price cannot be negative";
        }
        else{
            this->rental_price = new_price;
        }
    }

    friend void operator+(float price, Movie& m);
};

void operator+(float price, Movie& m){
    m.set_price(m.get_price() + price);
}

int Movie::movie_counter = 0;