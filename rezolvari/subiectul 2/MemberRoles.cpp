#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class MemberRoles{
private:
    char* team_name = nullptr;
    string coordinator_name = "";
    int number_of_team_members = 0;
    vector <string> member_name_list;

public:

    //default constructor
    MemberRoles(){}

    //constructor with parameters
    MemberRoles(const char* new_team_name, string new_coordination_name, int new_number_of_team_members, vector<string> new_member_name_list) : 
    coordinator_name(new_coordination_name), number_of_team_members(new_number_of_team_members), member_name_list(new_member_name_list){
        set_team_name(new_team_name);
    }

    //destructor
    ~MemberRoles(){
        delete[] team_name;
        team_name = nullptr;
    }

    MemberRoles(const MemberRoles& m){
        cout << "Copy constructor called!" << endl;
        if(m.team_name != nullptr){
            set_team_name(m.team_name);
        }
        else{
            this->team_name = nullptr;
        }

        this->coordinator_name = m.coordinator_name;
        this->number_of_team_members = m.number_of_team_members;
        this->member_name_list = m.member_name_list; 
    }

    //getters
    inline string get_team_name() const{ return this->team_name; }
    inline string get_coordinator_name() const{ return this->coordinator_name; }
    inline vector<string> get_team_members() const { return this->member_name_list; }

    //setter
    void set_team_name(const char* team_name){
        if(team_name == nullptr){
            throw "This field cannot be empty!";
        }
        delete[] this->team_name;
        this->team_name = new char[strlen(team_name) + 1];
        strcpy(this->team_name, team_name);
    }

    //overloading operator -=

    MemberRoles& operator-=(int multiplicator){
        if(multiplicator <= 0){
            throw "Multiplicator must be strictly higher than 0!";
        }
        this->number_of_team_members *= multiplicator;
        return *this;
    }

    //overloading function operator
    bool operator()(string value, int index){
        if(member_name_list.at(index) == value){
            return true;
        }
        return false;
    }

    void printInfo(){
        cout << "Team name: " << team_name << "\nCoordinator name: " << coordinator_name << "\nNumber of team members: " << number_of_team_members << "\nMember list: ";
        for(size_t i = 0; i < member_name_list.size(); i++){
            cout << member_name_list[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    vector<string> members = {"Liviu", "Mihnea", "Ana", "Mara"};
    MemberRoles m("TeamX", "Fabian", 4, members);
    m.printInfo();

    cout << endl;

    MemberRoles m2 = m;
    m2 -= 2;
    m2.printInfo();

    return 0;
}