// (2p) Exemplify the concept of a “has a” relation by defining a new class that handles several objects of the previous class type.
// Implement a method that allows you to add an object to your collection.You can use STL collections but it is not mandatory.Test the solution in the main().

#pragma once
#include <vector>
#include "Conference.h"
using namespace std;


class HandleConference{
private:
    vector<Conference> conference_list;

public:
    void add_conference(const Conference& c){
        conference_list.push_back(c);
    }

    void display_conferences(){
        for(auto& c: conference_list){
            cout << "Conference id: " << c.getId() << " | " << "Conference date: " << c.getDate() << " | " << "Price: " << c.getPrice() << endl;
        }
    }


};
