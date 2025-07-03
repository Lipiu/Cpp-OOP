#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;

class Printer{
private:
    char* manufacturer = nullptr;
    char* model = nullptr;
    int number_of_printer_pages = 0;
    float temperature = 0.0;

    const int printer_id;
    static int printer_counter;

public:

    //default constructor
    Printer():printer_id(++printer_counter){}

    //constructor with parameters
    Printer(const char* manufacturer, const char* model, int new_no_printer_pages, float new_temperature):printer_id(++printer_counter){
        this->set_manufacturer(manufacturer);
        this->set_model(model);
        number_of_printer_pages = new_no_printer_pages;
        temperature = new_temperature;
    }

    //destructor
    ~Printer(){
        delete[] this->manufacturer;
        delete[] this->model;
        this->manufacturer = nullptr;
        this->model = nullptr;
    }

    //getters
    char* get_manufacturer() const{
        return this->manufacturer;
    }

    char* get_model() const{
        return this->model;
    }

    int get_no_printer_pages() const{
        return this->number_of_printer_pages;
    }

    float get_temperature() const{
        return this->temperature;
    }

    //setters
    void set_manufacturer(const char* manufacturer){
        if(manufacturer == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->manufacturer;
            this->manufacturer = new char[strlen(manufacturer) + 1];
            strcpy(this->manufacturer, manufacturer);
        }
    }

    void set_model(const char* model){
        if(model == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->model;
            this->model = new char[strlen(model) + 1];
            strcpy(this->model, model);
        }
    }

    void set_temperature(float new_temp){
        if(new_temp < 0){
            throw "Invalid value.";
        }
        else{
            this->temperature = new_temp;
        }
    }

    //overload cast to real value operator
    explicit operator float() const{
        return ((temperature * (float)9 / 5) + 32);
    }

    virtual void my_method(){
        cout << "my_method from Printer.h" << endl;
    }

    void print_info(){
        if(this->manufacturer != nullptr){
            cout << "Manufacturer: " << this->manufacturer << endl;
        }
        else{
            this->manufacturer = nullptr;
        }

        if(this->model != nullptr){
            cout << "Model: " << this->model << endl;
        }
        else{
            this->model = nullptr;
        }
        cout << "Number of printed pages: " << this->number_of_printer_pages << endl;
        cout << "Temperature: " << this->temperature << endl;
    }
};

int Printer::printer_counter = 0;