/*
(3p) Define classes that allow the abstraction of the video conferencing concept (name, platform used, start time, etc.) Member data is private or protected. 
The class contains at least three fields, of which one is dynamically allocated, a parameter constructor, destructor, accessory methods (get and set) for one of the attributes.
Use a constant member.The set() method validates the input data.

(1p) Overload the + operator in the form value + object to change the value of an attribute.

(1p) Overload at least one relational operator to be able to compare two video conferences based on start date

(2p) Exemplify the concept of a “has a” relation by defining a new class that handles several objects of the previous class type.
Implement a method that allows you to add an object to your collection.You can use STL collections but it is not mandatory.Test the solution in the main().

(2p) Exemplify the concept of serialization and deserialization of an object by writing its values in a binary file.

(1p) Explain and exemplify the concept of “dangling pointer” using a pointer to one of the previously defined classes.
*/

#pragma once
#include <iostream>
#include <string.h>
using namespace std;


class Conference{
private:
    //static field
    static int idCounter;

    //const field
    const int id;
    float entryPrice = 0.0;
    
    //dynamic field
    char* date = nullptr;

public:
    Conference(): id(++idCounter){}

    int getId(){
        return this->id;
    }

    //ctor with parameters
    Conference(float price, const char* date): id(++idCounter){
        this->setDate(date);
        this->setPrice(price);
    }

    ~Conference(){
        cout << "Destructor on id:" << this->id;
        cout << endl;
        delete[] this->date;
        this->date = nullptr;
    }

    //getters
    float getPrice() const{
        return this->entryPrice;
    }

    const char* getDate(){
        return this->date;
    }

    //setters
    void setPrice(float entryPrice){
        if(entryPrice < 0)
            throw "Price cannot be negative";
        this->entryPrice = entryPrice;
    }

    void setDate(const char* date){
        if(date == nullptr)
            throw "Date cannot be empty";
        delete[] this->date;
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
    }

    //overloading < to compare two video conferences
    bool operator<(const Conference& other){
        int c1,c2;
        c1 = atoi(&(this->date[6])); //date[6] because it will take only the year and compare
        c2 = atoi(&(other.date[6]));
        
        return c1 < c2;
    }

    //overloading + operator
    friend void operator+(float price, Conference& c) {
        c.setPrice(c.getPrice() + price);
    }

    //overloading << (ostream operator)
    friend ostream& operator<<(ostream& os, const Conference& conference){
        os << "ID: " << conference.id << " | " << "Date: " << conference.date << " | " << "Price: " << conference.entryPrice;
        return os;
    }
};

int Conference::idCounter = 0;
