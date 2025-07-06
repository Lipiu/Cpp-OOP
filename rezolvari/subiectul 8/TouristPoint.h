/*
(3p) It is considered an application used to manage the route between tourist points. 
Specific attributes will be defined, such as: 
distance, tourist points, duration, points of interest, map, etc. 
Member data is private and access methods are provided. 
The class contains at least three fields,of which one is 
dynamically allocated, 
a parameter constructor, 
destructor, 
accessor methods (get and set) for one of the attributes. 
The set () method validates the input data. 
Use a static or const. 

(1p) Overload the operator - (minus) for object- value to change the value of an attribute. 
(1p) Define the == operator that compares two objects and returns true if all attribute values ​​are equal to each other. 

(2p) Exemplify the concept oftype relationship “is a” by specializing the previous class. 
The new class adds a new attribute and the parameter constructor explicitly calls the base class constructor. 
Test the solution by instantiating the new class. 
(2p) Explain and exemplify the concept of late-binding by defining a virtual method in the base class. 

(1p) Exemplify the concept of template function in C ++. 
*/

#pragma once
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

class TouristPoint{
private:
    int distance = 0;
    char* tourist_points = nullptr;
    int duration = 0;
    string points_of_interest = "";

    static int no_tourists;

public:
    TouristPoint(int distance, const char* tourist_points, int duration, string points_of_interest){
        this->distance = distance;
        this->set_points(tourist_points);
        this->duration = duration;
        this->points_of_interest = points_of_interest;
        no_tourists++;
    }

    ~TouristPoint(){
        delete[] this->tourist_points;
        this->tourist_points = nullptr;

        no_tourists--;
    }

    TouristPoint(const TouristPoint& tp){
        this->distance = tp.distance;
        this->set_points(tp.tourist_points);
        this->duration = tp.duration;
        this->points_of_interest = tp.points_of_interest;
        no_tourists++;
    }

    int get_distance(){
        return this->distance;
    }

    char* get_points(){
        char* copy = new char[strlen(this->tourist_points) + 1];
        strcpy(copy, this->tourist_points);
        return copy;
    }

    void set_points(const char* points){
        if(points == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->tourist_points;
            this->tourist_points = new char[strlen(points) + 1];
            strcpy(this->tourist_points, points);
        }
    }

    //Overload the operator - (minus) for object- value to change the value of an attribute.
    TouristPoint operator-(int value){
        TouristPoint copy = *this;
        copy.distance -= value;
        return copy;
    }

    //Define the == operator that compares two objects and returns true if all attribute values ​​are equal to each other. 
    bool operator==(const TouristPoint& other){
        if(this == &other){
            return true;
        }
        if(this->distance != other.distance){
            return false;
        }
        if(this->tourist_points == nullptr || other.tourist_points == nullptr){
            return false;
        }
        if(strcmp(this->tourist_points, other.tourist_points) != 0){
            return false;
        }
        if(this->duration != other.duration){
            return false;
        }
        if(this->points_of_interest != other.points_of_interest){
            return false;
        }
        return true;
    }

    //overload operator =
    TouristPoint& operator=(const TouristPoint& t){
        if(this != &t){
            this->distance = t.distance;
            
            if(this->tourist_points != nullptr){
                delete[] this->tourist_points;
            }
            if(t.tourist_points != nullptr){
                this->tourist_points = new char[strlen(t.tourist_points) + 1];
                strcpy(this->tourist_points, t.tourist_points);
            }
            else{
                this->tourist_points = nullptr;
            }
            this->duration = t.duration;
            this->points_of_interest = t.points_of_interest;
        }
        return *this;
    }

    virtual void do_something(){
        cout << "Method from parent class" << endl;
    }
};

int TouristPoint::no_tourists = 0;