/*
SUB 6 

(3p) Define a class that allows the management of data related to an exam subject (title, points for each requirement, exam date, requirements, etc.), 
using members of 
public, 
private, 
protected, 
const, 
static type. 

The class contains 
at least one dynamically allocated field, 
constructors, 
2 accessor methods (set will validate the received value) for an attribute of your choice 
and the destructor. 

(1p) Overload the + operator to allow the implementation of the string + object operation. 
(2p) Overload the << operator to allow the object to be written to a text file. Test in main () on a locally created text file. 

(2p) Exemplify the use of a 1: 1 type “has a” relationship (one to one) by defining an additional class to manage a student's assessment. For the new class define the copy constructor. 
(1p) Exemplify the relationship between the constructors of the two classes, which are in the ratio of 1: 1, if the initial class does not have a default constructor. 

(1p) Explain and exemplify the concept of “dangling pointer” using a pointer to one of the previously defined classes. 
*/

#pragma once
#include <string.h>
#include <string>
using namespace std;
#include <iostream>

class Exam{
private:
    char* title = nullptr;
    int rquirements = 0;
    int* points_for_each_requirement = nullptr;
    string exam_date = "";    

    const int exam_id;
    static int no_students;

public:
    Exam(const char* title, int requirements, int* points_for_each_requirement, string exam_date, const int exam_id):exam_id(exam_id){
        this->set_title(title);
        this->rquirements = requirements;
        this->set_points(points_for_each_requirement, requirements);
        this->exam_date = exam_date;
        no_students++;
    }

    Exam(const Exam& e):exam_id(exam_id){
        this->set_title(e.title);
        this->rquirements = e.rquirements;
        this->set_points(e.points_for_each_requirement, e.rquirements);
        this->exam_date = e.exam_date;
        no_students++;
    }

    ~Exam(){
        delete[] this->title;
        delete[] this->points_for_each_requirement;
        this->title = nullptr;
        this->points_for_each_requirement = nullptr;
        no_students--;
    }

    void set_title(const char* title){
        if(title == nullptr){
            throw "Field cannot be empty";
        }
        else{
            delete[] this->title;
            this->title = new char[strlen(title) + 1];
            strcpy(this->title, title);
        }
    }

    void set_points(int* points, int requirements){
        if(points == nullptr || requirements <= 0){
            throw "Invalid field.";
        }
        this->rquirements = requirements;
        delete[] this->points_for_each_requirement;
        this->points_for_each_requirement = new int[requirements];
        for(int i = 0; i < requirements; i++){
            this->points_for_each_requirement[i] = points[i];
        }
    }

    char* get_title() const{
        char* copy = new char[strlen(this->title) + 1];
        strcpy(copy, this->title);
        return copy;
    }

    int* get_points(){
        int* copy = new int[this->rquirements];
        for(int i = 0; i < this->rquirements; i++){
            copy[i] = this->points_for_each_requirement[i];
        }
        return copy;
    }

    //Overload the + operator to allow the implementation of the string + object operation.
    friend string operator+(string text, Exam e);

    //Overload the << operator to allow the object to be written to a text file. Test in main () on a locally created text file. 
    friend ostream& operator<<(ostream& os, Exam& e);
};

ostream& operator<<(ostream& os, Exam& e){
    os << "Exam title: " << e.get_title() << "\n";
    os << "Requirements: " << e.rquirements << "\n";
    os << "Number of points for each requirement: ";
    for(int i = 0; i < e.rquirements; i++){
        os << e.points_for_each_requirement[i] << " ";
    }
    os << "\n";
    os << "Exam date: " << e.exam_date << "\n";
    return os;
}

string operator+(string text, Exam e){
    char* title = e.get_title();
    text += title;
    delete[] title;
    return text;
}

int Exam::no_students = 0;