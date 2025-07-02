/*
Define a derived class Book that inherits from Publication and adds:

number of pages (int)
price (float)

Implement:
a parameterized constructor that calls the base class constructor
a destructor
a method display() that prints all information about the book (including Publication attributes)

Operator Overloading
Overload the operator + in the form: value + object
*/

#pragma once;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Publication.h"
using namespace std;

class Book : public Publication{
private:
    int number_of_pages = 0;
    float price = 0.0;

public:
    Book(){
        cout << "Derived Book Class, Default Constructor";
    }

    ~Book(){}

    Book(char* title, char* author, int year, int no_pages, float new_price): Publication(title, author, year){
        number_of_pages = no_pages;
        price = new_price;
        cout << "Derived Book Class, Constructor with parameters" << endl;
    }

    void set_no_pages(int number_of_pages){
        if(number_of_pages < 0){
            throw "Number of pages cannot be negative.";
        }
        this->number_of_pages = number_of_pages;
    }

    void set_price(float price){
        if(price < 0){
            throw "Price cannot be negative.";
        }
        this->price = price;
    }

    int get_no_pages() const{
        return this->number_of_pages;
    }

    float get_price() const{
        return this->price;
    }

    void display(){
        cout << "Title: " << get_title() << " | " << "Author: " << get_author() << " | " << "Year of publication: " << get_year() << " | "
             << "Number of pages: " << get_no_pages() << " | " << "Price: " << get_price() << endl; 
    }

    friend void operator+(float price, Book& b){
        return b.set_price(b.get_price() + price);
    }
};