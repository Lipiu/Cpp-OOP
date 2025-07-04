/*
(3p) It is considered an application used to manage the route between tourist points. 
Specific attributes will be defined, such as: 
distance, tourist points, duration, points of interest, map, etc. 
Member data is private and access methods are provided. 
The class contains at least three fields,of which one is 
dynamically allocated, a parameter constructor, destructor, accessor methods (get and set) for one of the attributes. 
The set () method validates the input data. Use a static or const. 

(1p) Overload the operator - (minus) for object- value to change the value of an attribute. 

(1p) Define the == operator that compares two objects and returns true if all attribute values ​​are equal to each other. 

(2p) Exemplify the concept of type relationship “is a” by specializing the previous class. 
The new class adds a new attribute and the parameter constructor explicitly calls the base class constructor. Test the solution by instantiating the new class. 

(2p) Explain and exemplify the concept of late-binding by defining a virtual method in the base class. 

(1p) Exemplify the concept of template function in C ++. 
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;

class TouristPoint{
private:
    int distance = 0;
    char* duration = nullptr;
    char* points_of_interest = nullptr;

    const int point_id;
    static int counter;

public:
    TouristPoint():point_id(++counter){}

    TouristPoint(int distance, const char* duration, const char* points_of_interest):point_id(++counter){
        this->distance = distance;
        this->set_duration(duration);
        this->set_points(points_of_interest);
    }

    TouristPoint(const TouristPoint& tp):point_id(++counter){
        this->distance = tp.get_distance();
        this->set_duration(tp.get_duration());
        this->set_points(tp.get_points_of_interest());
    }

    ~TouristPoint(){
        delete[] this->duration;
        delete[] this->points_of_interest;
        this->duration = nullptr;
        this->points_of_interest = nullptr;
    }

    int get_distance() const{
        return this->distance;
    }

    char* get_duration() const{
        return this->duration;
    }

    char* get_points_of_interest() const{
        return this->points_of_interest;
    }

    void set_duration(const char* duration){
        if(duration == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->duration;
            this->duration = new char[strlen(duration) + 1];
            strcpy(this->duration, duration);
        }
    }

    void set_points(const char* points_of_interest){
        if(points_of_interest == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->points_of_interest;
            this->points_of_interest = new char[strlen(points_of_interest) + 1];
            strcpy(this->points_of_interest, points_of_interest);
        }
    }

    //(1p) Overload the operator - (minus) for object- value to change the value of an attribute.
    TouristPoint operator-(const TouristPoint& tp) const{
        TouristPoint copy = *this;
        copy.distance -= tp.distance;
        return copy;
    }

    //(1p) Define the == operator that compares two objects and returns true if all attribute values ​​are equal to each other.
    bool operator==(const TouristPoint& tp) const{
        if(this == &tp)
            return true;
        if(this->distance != tp.distance)
            return false;
        if(this->duration == nullptr || tp.duration == nullptr || strcmp(this->duration, tp.duration) != 0)
            return false;
        if(this->points_of_interest == nullptr || tp.points_of_interest == nullptr || strcmp(this->points_of_interest, tp.points_of_interest) != 0)
            return false;
        
        return true;
    }

    void print_info(){
        cout << "Distance: " << this->distance << " | ";
        if(this->duration != nullptr){
            cout << "Duration: " << this->duration <<  " | ";
        }
        else{
            this->duration = nullptr;
        }
        if(this->points_of_interest != nullptr){
            cout << "Points of interest: " << this->points_of_interest << endl;
        }
        else{
            this->points_of_interest = nullptr;
        }
        
    }

    virtual void do_something(){
        cout << "Method call from parent class" << endl;
    }
    
};

int TouristPoint::counter = 0;