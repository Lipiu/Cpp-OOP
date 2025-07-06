#include "TouristPoint.h"
#include "Hike.h"
#include <iostream>
using namespace std;

int main(){

    TouristPoint tp(10, "Un munte", 4, "Un varf inalt");
    TouristPoint tp2 = tp;

    TouristPoint temp = tp - 9;
    cout << temp.get_distance();

    cout << endl;
    
    if(tp == tp2){
        cout << "Objects are the same\n";
    }
    else{
        cout << "Objects are different\n";
    }

    cout << endl;

    Hike h("Hard", 9, "Alt munte", 3, "Alt varf inalt");

    TouristPoint* ptr = new Hike("Hard", 9, "Alt munte", 3, "Alt varf inalt");
    ptr->do_something(); // calls Hike::do_something()
    //because the function is virtual, the call is resolved at runtime
    //and is based on the actual object (Hike) type, not the pointer type
    delete ptr;

    return 0;
}