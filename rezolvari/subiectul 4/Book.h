#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
//#include <va rog ajutati-ma nu mai suport>

class Book{
private:
    char* title = nullptr;
    char* author = nullptr;
    int number_of_pages = 0;
    float price = 0.0;

    static int book_counter_by_id;
    const int book_id;

public:
    Book():book_id(++book_counter_by_id){}

    Book(const char* new_title, const char* new_author, int no_pages, float new_price):book_id(++book_counter_by_id){
        if(new_title != nullptr){
            title = new char[strlen(new_title) + 1];
            strcpy(title, new_title);
        }
        else{
            title = nullptr;
        }

        if(new_author != nullptr){
            author = new char[strlen(new_author) + 1];
            strcpy(author, new_author);
        }
        else{
            author = nullptr;
        }
        number_of_pages = no_pages;
        price = new_price;
    }

    ~Book(){
        delete[] this->title;
        delete[] this->author;

        this->title = nullptr;
        this->author = nullptr;
    }

    //getters
    const char* get_title(){
        return this->title;
    }

    const char* get_author(){
        return this->author;
    }

    int get_no_pages(){
        return this->number_of_pages;
    }

    float get_price(){
        return this->price;
    }

    void set_title(char* new_title){
        if(new_title == nullptr){
            throw "Titlul nu poate fi liber GOLANULE";
        }
        else{
            delete[] this->title;
            this->title = new char[strlen(new_title) + 1];
            strcpy(this->title, new_title);
        }
    }

    void set_author(char* new_author){
        if(new_author == nullptr){
            throw "Credeam ca ne-am inteles ca nu poti sa lasi liber NATAFLETULE";
        }
        else{
            delete[] this->author;
            this->author = new char[strlen(new_author) + 1];
            strcpy(this->author, new_author);
        }
    }

    void set_no_pages(int new_number_of_pages){
        if(new_number_of_pages < 0){
            throw "Numarul nu poate fi negativ bossangeles";
        }
        else{
            this->number_of_pages = new_number_of_pages;
        }
    }

    void set_price(float price){
        if(price < 0){
            throw "Ti-am spus de 10000 de ori BAGABONTULE, gaseste tu problema acum";
        }
        else{
            this->price = price;
        }
    }

    friend void operator+(float price, Book& book){
        book.set_price(book.get_price() + price);
    }

    friend bool operator<(Book& book1, Book& book2){
        return book1.number_of_pages < book2.number_of_pages;
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Title: " << (book.title ? book.title : "(no title)") << " | "
           << "Author: " << (book.author ? book.author : "(no author)") << " | "
           << "Number of pages: " << book.number_of_pages << " | "
           << "Price: " << book.price;
        return os;
    }
};

int Book::book_counter_by_id = 0;