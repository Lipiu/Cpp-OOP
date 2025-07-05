/*
(3p) It is considered an application used to manage the configuration of a laptop. Specific attributes will be followed, 
such as: model, processor type, video card, component list, warranty, housing series, etc. 
Member data is private or protected. 
The class contains at least three fields, 
of which one is dynamically allocated, 
a parameter constructor, 
destructor, 
accessory methods (get and set) for one of the attributes. 
Use a constant member. The set () method validates the input data. 

(1p) Overload the operator * in the form object * value to change the value of an attribute by multiplication. 

(1p) Overload the cast to string operator, in the explicit form to return the description of an object. (...) 
*/

#pragma once
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

class Config{
private:
    char* model = nullptr;
    string processor_type = "";
    int cpu_generation = 0;
    string gpu = "";
    char* warranty = nullptr;

    const int config_id;
    static int counter;

public:
    Config(const char* model, string processor, int cpu_gen, string new_gpu, const char* warranty, int id):config_id(id){
        this->set_model(model);
        this->processor_type = processor;
        this->cpu_generation = cpu_gen;
        this->gpu = new_gpu;
        this->set_warranty(warranty);
        counter++;
    }

    Config(Config& c):config_id(c.config_id){
        this->set_model(c.model);
        this->processor_type = c.processor_type;
        this->cpu_generation = c.cpu_generation;
        this->gpu = c.gpu;
        this->set_warranty(c.warranty);
        counter++;
    }

    ~Config(){
        delete[] this->model;
        delete[] this->warranty;
        this->model = nullptr;
        this->warranty = nullptr;
        counter--;
    }

    char* get_model() const{
        char* copy = new char[strlen(this->model) + 1];
        strcpy(copy, this->model);
        return copy;
    }

    int get_cpu_gen(){
        return this->cpu_generation;
    }

    char* get_warranty() const{
        char* copy = new char[strlen(this->warranty) + 1];
        strcpy(copy, this->warranty);
        return copy;
    }

    void set_model(const char* model){
        if(model == nullptr){
            throw "Field cannot be empty";
        }
        else{
            delete[] this->model;
            this->model = new char[strlen(model) + 1];
            strcpy(this->model, model);
        }
    }

    void set_warranty(const char* warranty){
        if(warranty == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->warranty;
            this->warranty = new char[strlen(warranty) + 1];
            strcpy(this->warranty, warranty);
        }
    }

    // Overload the operator * in the form object * value to change the value of an attribute by multiplication.
    Config operator*(int value){
        Config copy = *this;
        copy.cpu_generation *= value;
        return copy;
    }

    // Overload the cast to string operator, in the explicit form to return the description of an object.
    explicit operator string() const;
};

Config::operator string() const{
        stringstream ss;
        ss << "Description of product:\n";
        ss << "Model: ";
        if(this->model != nullptr){
            ss << this->model << " | ";
        }
        ss << "Processor type: " << this->processor_type << " | ";
        ss << "Cpu generation: " << this->cpu_generation << " | ";
        ss << "GPU: " << this->gpu << " | ";
        ss << "Warranty: ";
        if(this->warranty != nullptr){
            ss << this->warranty << endl;
        }
        return ss.str();
    }

int Config::counter = 0;