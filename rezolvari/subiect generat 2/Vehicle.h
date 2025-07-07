/*
Define a base class Vehicle to model data for a generic vehicle.

It must include:
Attributes such as:

brand (dynamically allocated char*)
licensePlate (dynamically allocated char*)
productionYear (int)
basePrice (float)

Members:

at least one protected attribute
at least one private attribute
at least one public attribute
at least one const attribute (e.g. unique vehicle ID)
at least one static attribute (e.g. total vehicles registered)

The class must implement:

a parameterized constructor
a destructor that properly frees dynamic memory
two accessor methods (getter and setter) for an attribute of your choice
The setter should validate data.
a dynamically allocated attribute
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;

class Vehicle{
private:
    char* brand = nullptr;
    char* license_plate = nullptr;
    int production_year = 0;

    const int vehicle_id;
    static int vehicle_counter;

protected:
    float base_price = 0.0;

public:
    Vehicle():vehicle_id(++vehicle_counter){}

    Vehicle(const char* brand, const char* license_plate, int new_prod_year):vehicle_id(++vehicle_counter){
        this->set_brand(brand);
        this->set_license_plate(license_plate);
        production_year = new_prod_year;
    }

    Vehicle(const Vehicle& v):vehicle_id(++vehicle_counter){
        this->set_brand(v.get_brand());
        this->set_license_plate(v.get_license_plate());
        production_year = v.production_year;
    }

    ~Vehicle(){
        delete[] this->brand;
        delete[] this->license_plate;
        
        this->brand = nullptr;
        this->license_plate = nullptr;
    }

    char* get_brand() const{
        return this->brand;
    }

    char* get_license_plate() const{
        return this->license_plate;
    }

    int get_prod_year() const{
        return this->production_year;
    }

    void set_brand(const char* new_brand){
        if(new_brand == nullptr){
            throw "Brand cannot be empty.";
        }
        else{
            delete[] this->brand;
            this->brand = new char[strlen(new_brand) + 1];
            strcpy(this->brand, new_brand);
        }
    }

    void set_license_plate(const char* new_license_plate){
        if(new_license_plate == nullptr){
            throw "License plate cannot be empty.";
        }
        else{
            delete[] this->license_plate;
            this->license_plate = new char[strlen(new_license_plate) + 1];
            strcpy(this->license_plate, new_license_plate);
        }
    }

    virtual void my_method(){
        cout << "my_method function from main class" << endl;
    }
};

int Vehicle::vehicle_counter = 0;