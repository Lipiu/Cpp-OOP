/*
Define a Fleet class that manages multiple vehicles.

Implement:
a method to add a new vehicle
a method to display all vehicles

You can use STL containers like vector, or raw arrays if you prefer.
(1p) Operator Overloading for Fleet
Overload an operator (e.g. +=) to add a new ElectricVehicle to a Fleet object.
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "Vehicle.h"
#include "ElectricVehicle.h"
using namespace std;

class Fleet{
private:
    vector<Vehicle> vehicles;

public:
    void add_vehicles(const Vehicle& v){
        vehicles.push_back(v);
    }

    void display_vehicles(){
        cout << "Welcome to the dealership" << endl;

        for(int i = 0; i < vehicles.size(); i++){
            cout << "Car #" << (i+1) << " | ";
            if(vehicles[i].get_brand() != nullptr){
                cout << vehicles[i].get_brand() << " | ";
            }
            if(vehicles[i].get_license_plate() != nullptr){
                cout << vehicles[i].get_license_plate() << " | ";
            }
            cout << "Production year: " << vehicles[i].get_prod_year() << endl;
        }
    }

    Fleet& operator+=(const ElectricVehicle& ev){
        vehicles.push_back(ev);
        return *this;
    }
};