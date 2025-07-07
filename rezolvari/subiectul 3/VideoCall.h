/*
(3p) Define classes that allow the abstraction of the video conferencing concept 
(name, platform used, start time, etc.) Member data is private or protected. 
The class contains at least three fields, of which one is 
dynamically allocated, 
a parameter constructor, 
destructor, 
accessory methods (get and set) for one of the attributes.
Use a constant member.
The set() method validates the input data. 

(1p) Overload the + operator in the form value + object to change the value of an attribute. 
(1p) Overload at least one relational operator to be able to compare two video conferences based on start date 

(2p) Exemplify the concept of a “has a” relation by defining a new class that handles several objects of the previous class type.
Implement a method that allows you to add an object to your collection.
You can use STL collections but it is not mandatory.Test the solution in the main(). 

(2p) Exemplify the concept of serialization and deserialization of an object by writing its values ​​in a binary file. 
(1p) Explain and exemplify the concept of “dangling pointer” using a pointer to one of the previously defined classes.
*/

#pragma once
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class VideoCall{
private:
    char* name = nullptr;
    string platform_used = "";
    int start_time = 0; // start time reprezinta ziua in care are loc conferinta
    int duration = 0;

    const int meeting_id;

public:
    VideoCall():meeting_id(meeting_id){}

    VideoCall(const char* name, string platform, int start_time, int duration, const int id):meeting_id(id){
        this->set_name(name);
        this->platform_used = platform;
        this->start_time = start_time;
        this->duration = duration;
    }

    VideoCall(const VideoCall& vc):meeting_id(vc.meeting_id){
        this->set_name(vc.name);
        this->platform_used = vc.platform_used;
        this->start_time = vc.start_time;
        this->duration = vc.duration;
    }

    ~VideoCall(){
        delete[] this->name;
        this->name = nullptr;
    }

    void set_name(const char* name){
        if(name == nullptr){
            throw "Invalid.";
        }
        else{
            delete[] this->name;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
    }

    void set_start_time(int start_time){
        if(start_time < 0){
            throw "Invalid";
        }
        this->start_time = start_time;
    }

    char* get_name(){
        char* copy = new char[strlen(this->name) + 1];
        strcpy(copy, this->name);
        return copy;
    }

    string get_platform_used() const{
        return this->platform_used;
    }

    int get_start_time(){
        return this->start_time;
    }

    int get_duration() const{
        return this->duration;
    }

    //Overload at least one relational operator to be able to compare two video conferences based on start date 
    bool operator>(VideoCall v2){
        return this->start_time > v2.start_time;
    }

    //Overload the + operator in the form value + object to change the value of an attribute. 
    // 10 + vc1
    friend VideoCall operator+(int value, VideoCall vc);

    //overloading operator << in case we need to write text (does not work for binary)
    friend ostream& operator<<(ostream& os, VideoCall vc);
};

ostream& operator<<(ostream& os, VideoCall vc){
    if(vc.name != nullptr){
        os << "Name of the conference: " << vc.name << "\n";
    }
    os << "Platform used: " << vc.platform_used << "\n";
    os << "Start time: " << vc.start_time << "\n";
    os << "Duration: " << vc.duration << "\n";
}

VideoCall operator+(int value, VideoCall vc){
    VideoCall copy = vc;
    copy.duration += value;
    return copy;
}