#pragma once
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

enum Party { Independent, Democrat, Republican, Terminat };

class Candidate{
private:
    char* name = nullptr;
    Party party;
    int votes = 0;
    
    const string region;
    static int totalCandidates;
    static int min_name_length;

public:
    Candidate(const char* name, Party party, int votes, const string& region):region(region){
        this->set_name(name);
        this->party = party;
        this->votes = votes;
        totalCandidates++;
    }

    Candidate(const Candidate& c):region(c.region){
        this->set_name(c.name);
        this->party = c.party;
        this->votes = c.votes;
        totalCandidates++;
    }

    ~Candidate(){
        // cout << "\nDestructor called\n";
        delete[] this->name;
        this->name = nullptr;
        totalCandidates--;
    }

    void set_name(const char* name){
        if(name == nullptr || strlen(name) <= min_name_length){
            throw "Invalid field";
        }
        else{
            delete[] this->name;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
    }

    char* get_name(){
        char* copy = new char[strlen(this->name) + 1];
        strcpy(copy, this->name);
        return copy;
    }

    static int print_total(){
        cout << "\nTotal candidates: " << totalCandidates;
        return totalCandidates;
    }

    Candidate& operator=(const Candidate& c){
        if(this == &c){
            return *this;
        }
        if(this != &c){
            if(this->name != nullptr){
                delete[] this->name;
            }
            this->name = new char[strlen(c.name) + 1];
            strcpy(this->name, c.name);

            this->party = c.party;
            this->votes = c.votes;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Candidate& c);

    Candidate& operator++(){
        this->votes += 1;
        return *this;
    }

    bool operator==(const Candidate& other){
        if(this == &other){
            return true;
        }
        else{
            if(this->name == nullptr || other.name == nullptr){
                return false;
            }
            if(strcmp(this->name, other.name) != 0){
                return false;
            }
            if(this->party != other.party){
                return false;
            }
            if(this->votes != other.votes){
                return false;
            }
            if(this->region != other.region){
                return false;
            }
        }
        return true;
    }

    bool check_name(string name){
        if(name == this->name){
            cout << "Received name is name of the candidate" << endl;
            return true;
        }
        else{
            cout << "Received name is NOT name of the candidate" << endl;
            return false;
        }
    }

    double calculatePopularityIndex(){
        double weight = 1.0;
        
        switch(party){
            case Independent:
                weight = 1.5;
                break;
            case Democrat:
                weight = 1.2;
                break;
            case Republican:
                weight = 1.0;
                break;
            default:
                throw "Invalid field";
                break;
        }
        return votes * weight;
    }
};

ostream& operator<<(ostream& os, const Candidate& c){
    os << "Candidate name: " << c.name << " | " << "Candidate party: ";
    if(c.party == 0){
        cout << "Independent";
    }
    else if(c.party == 1){
        cout << "Democrat";
    }
    else if(c.party == 2){
        cout << "Republican";
    }
    else{
        cout << "Terminat";
    }
    cout << " | " << "Number of votes: " << c.votes << " | " << "Region: " << c.region << endl;
    return os;
}

int Candidate::totalCandidates = 0;
int Candidate::min_name_length = 3;