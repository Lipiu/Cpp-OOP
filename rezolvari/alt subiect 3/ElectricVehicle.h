/*
Define a derived class ElectricVehicle that inherits from Vehicle and adds:

Attributes such as:
batteryCapacity (float)
rangePerCharge (int)

The derived class should:
have a parameterized constructor that calls the base class constructor
have its own destructor
override a method from the base class (e.g. display vehicle details)

Operator Overloading (++)
Overload the ++ operator in postfix form for ElectricVehicle to increase the rangePerCharge by 10 km.

Overload a setter
Exemplify function overloading by defining multiple versions of a setter method for one of your attributes.
E.g.:
setBasePrice(float price)
setBasePrice(const char* currency, float price)

Copy Constructor Situations
Using your classes, exemplify the three different situations in which the copy constructor is called.

E.g.:
initialization
passing by value
returning by value
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include <string.h>
#include <iostream>
using namespace std;

class ElectricVehicle : public Vehicle{
private:
    float battery_capacity = 0.0f;
    int range_per_charge = 0;

public:
    ElectricVehicle(const char* brand, const char* license_plate, int production_year, float new_battery_capacity, int new_range_per_charge) : Vehicle(brand, license_plate, production_year){
        battery_capacity = new_battery_capacity;
        range_per_charge = new_range_per_charge;
    }

    ElectricVehicle(const ElectricVehicle& ev) : Vehicle(ev){
        cout << "\nCalling copy constructor\n";
        this->battery_capacity = ev.battery_capacity;
        this->range_per_charge = ev.range_per_charge;
    }

    ~ElectricVehicle(){}

    void my_method(){
        cout << "my_method from child class" << endl;
    }

    ElectricVehicle operator++(int){
        ElectricVehicle copy = *this;
        this->range_per_charge += 100;
        return copy;
    }

    void set_base_price(float price){
        if(price < 0){
            throw "Price cannot be negative.";
        }
        else{
            this->base_price = price;
        }
    }
    
    void set_base_price(const char* currency, float price){
        if(currency == nullptr || price < 0){
            throw "Invalid data.";
        }
        else{
            cout << "Base price set using currency: " << currency << endl;
            this->base_price = price;
        }
    }
};