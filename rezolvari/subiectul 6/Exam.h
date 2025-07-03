/*
(3p) Define a class that allows the management of data related to an exam subject (title, points for each requirement, exam date, requirements, etc.), 
using members of public, private, protected, const, static type. 
The class contains at least one dynamically allocated field, 
constructors, 
2 accessor methods (set will validate the received value) for an attribute of your choice and the destructor. 

(1p) Overload the + operator to allow the implementation of the string + object operation. 
(2p) Overload the << operator to allow the object to be written to a text file. Test in main () on a locally created text file. 

(2p) Exemplify the use of a 1: 1 type “has a” relationship (one to one) by defining an additional class to manage a student's assessment. For the new class define the copy constructor. 
(1p) Exemplify the relationship between the constructors of the two classes, which are in the ratio of 1: 1, if the initial class does not have a default constructor. 
(1p) Explain and exemplify the concept of “dangling pointer” using a pointer to one of the previously defined classes. 
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Exam{
private:
    string title = "";
    int* point_for_each_req = nullptr;
    int number_of_points = 0;
    char* exam_date = nullptr;
    char* requirements = nullptr;

    const int exam_id;
    static int exam_counter;

public:
    Exam():exam_id(++exam_counter){}

    Exam(string title, int* point_for_each_req, int new_number_of_points, const char* exam_date, const char* requirements):exam_id(++exam_counter){
        this->title = title;
        this->set_points(new_number_of_points, point_for_each_req);
        this->set_date(exam_date);
        this->set_requirements(requirements);
    }


    Exam(const Exam& e):exam_id(++exam_counter){
        this->title = e.title;
        this->set_points(e.number_of_points, e.point_for_each_req);
        this->set_date(e.get_date());
        this->set_requirements(e.get_requirements());
    }

    ~Exam(){
        delete[] this->point_for_each_req;
        delete[] this->exam_date;
        delete[] this->requirements;

        this->point_for_each_req = nullptr;
        this->exam_date = nullptr;
        this->requirements = nullptr;
    }

    string get_title() const{
        return this->title;
    }

    int* get_points(){
        int* copy = new int[this->number_of_points];
        for(int i = 0; i < number_of_points; i++){
            copy[i] = point_for_each_req[i];
        }
        return copy;
    }

    char* get_date() const{
        return this->exam_date;
    }

    char* get_requirements() const{
        return this->requirements;
    }

    void set_title(string exam_title){
        if(exam_title == ""){
            throw "Field cannot be empty.";
        }
        else{
            this->title = exam_title;
        }
    }

    void set_points(int no_points, int* points){
        if(no_points < 0 || points == nullptr){
            throw "Invalid input.";
        }
        else{
            delete[] this->point_for_each_req;
            this->point_for_each_req = new int[no_points];
            for(int i = 0; i < no_points; i++){
                this->point_for_each_req[i] = points[i];
            }
            this->number_of_points = no_points;
        }
    }

    void set_date(const char* exam_date){
        if(exam_date == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->exam_date;
            this->exam_date = new char[strlen(exam_date) + 1];
            strcpy(this->exam_date, exam_date);
        }
    }

    void set_requirements(const char* requirements){
        if(requirements == nullptr){
            throw "Field cannot be empty.";
        }
        else{
            delete[] this->requirements;
            this->requirements = new char[strlen(requirements) + 1];
            strcpy(this->requirements, requirements);
        }
    }

    //(1p) Overload the + operator to allow the implementation of the string + object operation.
    Exam operator+(string message){
        Exam copy = *this;
        copy.title += message;
        return copy;
    }

    //(2p) Overload the << operator to allow the object to be written to a text file. Test in main () on a locally created text file.
    friend ostream& operator<<(ostream& os, const Exam& e) {
        os << "Title: " << e.title << " | ";

        if (e.point_for_each_req != nullptr && e.number_of_points > 0) {
            os << "Points for each requirement: ";
            for (int i = 0; i < e.number_of_points; i++) {
                os << e.point_for_each_req[i] << " ";
            }
            os << "| ";
        }

        if (e.exam_date != nullptr) {
            os << "Exam date: " << e.exam_date << " | ";
        }

        if (e.requirements != nullptr) {
            os << "Requirements: " << e.requirements;
        }

        os << endl;
        return os;
    }
};

int Exam::exam_counter = 0;