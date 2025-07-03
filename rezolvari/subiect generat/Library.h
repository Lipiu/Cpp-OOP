#pragma once
#include "Book.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Library{
private:
    string library_name = "";
    // Book books[3];
    vector<Book> book_list;
    int max_books = 0;

public:
    Library(){}

    void add_book(const Book& b){
        book_list.push_back(b);
    }

    //title, author, number pages, price
    void display_info(){
        cout << "Carti valabile in libraria INTERLOPILOR: " << library_name << endl;
        for(int i = 0; i < book_list.size(); i++){
            cout << "Book #" << (i+1) << " | ";
            if(book_list[i].get_title() != nullptr){
                cout << book_list[i].get_title() << " | ";
            }

            if(book_list[i].get_author() != nullptr){
                cout << book_list[i].get_author() << " | ";
            }
            
            cout << "Total pages: " << book_list[i].get_no_pages() << " | " << "Price: " << book_list[i].get_price() << endl;
        }
    }
};