/*
Definiți o clasă Student care să modeleze un student cu următoarele caracteristici:

Atribute private:
numele studentului (șir de caractere, pointer la char)
numărul de note (int)
un vector dinamic de int care să rețină notele studentului

Funcționalități:
Constructor fără parametri
Constructor cu parametri care să primească numele studentului, un vector de note și numărul de note
Destructor
Constructor de copiere

Operatorul de atribuire (=)
Setteri pentru nume și pentru vectorul de note (cu realocare dacă e nevoie)
Operatorul de egalitate == care să compare doi studenți după nume și note
Operatorii de citire >> și scriere << pentru obiectele de tip Student
*/

#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Student{
private:
    char* name = nullptr;
    int no_grades = 0;
    int* grades = nullptr;
    int age = 0;

    static int counter;

public:
    Student(){
        counter++;
    }

    Student(const char* name, int no_grades, int* grades, int age){
        this->set_name(name);
        this->no_grades = no_grades;
        this->set_grades(grades, no_grades);
        this->age = age;
        counter++;
    }

    Student(const Student& s){
        this->set_name(s.name);
        this->no_grades = s.no_grades;
        this->set_grades(s.grades, s.no_grades);
        this->age = s.age;
        counter++;
    }

    ~Student(){
        delete[] this->name;
        delete[] this->grades;

        this->name = nullptr;
        this->grades = nullptr;
    }

    void set_name(const char* name){
        if(name == nullptr){
            throw "Invalid";
        }
        else{
            delete[] this->name;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
    }

    void set_grades(int* new_grades, int new_no_grades){
        if(new_grades == nullptr || new_no_grades < 0){
            throw "Invalid";
        }
        else{
            delete[] this->grades;
            this->no_grades = new_no_grades;
            this->grades = new int[new_no_grades];
            for(int i = 0; i < new_no_grades; i++){
                this->grades[i] = new_grades[i];
            }
        }
    }

    int get_age(){
        return this->age;
    }

    int get_no_grades(){
        return this->no_grades;
    }

    int* get_grades(){
        int* copy = new int[this->no_grades];
        for(int i = 0; i < this->no_grades; i++){
            copy[i] = this->grades[i];
        }
        return copy;
    }

    // == operator
    bool operator==(Student s){
        if(this == &s){
            return true;
        }
        if(this->name == nullptr || s.name == nullptr || strcmp(this->name, s.name) != 0){
            return false;
        }
        if(this->no_grades != s.no_grades){
            return false;
        }
        
        for(int i = 0; i < this->no_grades; i++){
            if(this->grades[i] != s.grades[i]){
                return false;
            }
        }
        if(this->age != s.age){
            return false;
        }
        return true;
    }

    //postfix ++
    Student operator++(int){
        Student copy = *this;
        this->age++;
        return copy;
    }

    //prefix ++
    Student operator++(){
        ++age;
        return *this;
    }

    bool operator<(Student s){
        return this->age < s.age;
    }

    Student& operator=(const Student& other){
        if(this != &other){
            delete[] this->name;
            delete[] this->grades;

            if(other.name != nullptr){
                this->name = new char[strlen(other.name) + 1];
                strcpy(this->name, other.name);
            }
            else{
                this->name = nullptr;
            }
            this->no_grades = other.no_grades;

            if(other.grades != nullptr && other.no_grades > 0){
                this->grades = new int[other.no_grades];
                for(int i = 0; i < other.no_grades; i++){
                    this->grades[i] = other.grades[i];
                }
            }
            else{
                this->grades = nullptr;
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Student& s);
};

ostream& operator<<(ostream& os, const Student& s){
    if(s.name != nullptr){
        os << "Student name: " << s.name << endl;
    }
    os << "Grades: ";
    for(int i = 0; i < s.no_grades; i++){
        os << s.grades[i] << ", ";
    }
    os << endl;
    os << "Age: " << s.age;
    
    return os;
}

int Student::counter = 0;