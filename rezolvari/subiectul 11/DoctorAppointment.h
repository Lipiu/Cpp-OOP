#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Appointment{
private:
    int date = 0; //hour
    string time = "";
    string* name = nullptr;

    static int counter;

public:
    Appointment(){
        counter++;
    }

    Appointment(int date, string time, string* name){
        this->date = date;
        this->time = time;
        this->set_name(name);
        counter++;
    }

    Appointment(const Appointment& a){
        this->date = a.date;
        this->time = a.time;
        this->set_name(a.name);
        counter++;
    }

    ~Appointment(){
        delete this->name;
        this->name = nullptr;
        counter--;
    }

    //by reference
    // void set_name(const string& name){
    //     if(this->name != nullptr){
    //         delete this->name;
    //     }
    //     this->name = new string(name);
    // }

    //by pointer
    void set_name(const string* name){
        if(name == nullptr){
            throw "Invalid.";
        }
        else{
            delete this->name;
            this->name = new string(*name);
        }
    }

    Appointment operator++(int){
        Appointment copy = *this;
        this->date++;
        return copy;
    }

    Appointment operator++(){
        ++date;
        return *this;
    }

    int get_date(){
        return this->date;
    }

    void appointment_available(){
        cout << "Appointment available at our hospital" << endl;
    }
};
int Appointment::counter = 0;