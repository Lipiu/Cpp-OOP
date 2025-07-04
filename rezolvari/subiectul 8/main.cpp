#include "TouristPoint.h"
#include "SomeClass.h"
#include <iostream>
using namespace std;

int main(){
    //TouristPoint(distance, duration, point_of_interest)
    TouristPoint t1(30, "5 hours", "Pass POO exam");
    TouristPoint t2(20, "3.5 hours", "Pls help me");

    TouristPoint t3 = t1;

    SomeClass s(2, 30, "5 hours", "Pass POO exam");
    
    t1.print_info();
    t2.print_info();
    // t3.print_info();

    cout << endl;
    t1.do_something();
    s.do_something();
    
    cout << endl;

    if(t1 == t2){
        cout << "Objects are the same" << endl;
    }
    else{
        cout << "Objects are different" << endl;
    }

    if(t1 == t3){
        cout << "Objects are the same";
    }
    else{
        cout << "Objects are different";
    }

    cout << endl;
    cout << "\nTesting - operator";
    TouristPoint t4 = t1 - t2;
    cout << "Distance of t4 using overloaded - : " << t4.get_distance() << endl;


    return 0;
}