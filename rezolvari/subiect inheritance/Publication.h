/*
Design a base class Publication with at least these attributes:

title (dynamically allocated char*)
author (dynamically allocated char*)
year of publication (int)

Implement:

a static attribute that counts how many publications were created
a const attribute (e.g. unique ID)

a parameterized constructor
a destructor that correctly frees memory
getters and setters for at least one attribute, with validation
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;

class Publication{
private:
    char* title = nullptr;
    char* author = nullptr;
    int year_of_publication = 0;

    static int publication_counter;
    const int publication_id;

public:
    Publication():publication_id(++publication_counter){
        cout << "Publication Class, Default constructor" << endl;
    }

    Publication(char* title, char* author, int year):publication_id(++publication_counter){
        this->set_title(title);
        this->set_author(author);
        year_of_publication = year;
        cout << "Publication Class, Constructor with parameters" << endl;
    }

    ~Publication(){
        delete[] this->title;
        delete[] this->author;
        this->title = nullptr;
        this->author = nullptr;
    }

    char* get_title() const{
        return this->title;
    }

    char* get_author() const{
        return this->author;
    }

    int get_year() const{
        return this->year_of_publication;
    }

    void set_title(char* new_title){
        if(new_title == nullptr){
            throw "Title cannot be empty.";
        }
        else{
            delete[] this->title;
            this->title = new char[strlen(new_title) + 1];
            strcpy(this->title, new_title);
        }
    }

    void set_author(char* new_author){
        if(new_author == nullptr){
            throw "Author cannot be empty.";
        }
        else{
            delete[] this->author;
            this->author = new char[strlen(new_author) + 1];
            strcpy(this->author, new_author);
        }
    }

};

int Publication::publication_counter = 0;