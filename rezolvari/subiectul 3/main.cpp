#include <iostream>
#include "Conference.h"
#include "HandleConference.h"
using namespace std;

int main(){
    Conference c1(22.3, "28/05/2004");
    cout << "General info\n";
    cout << "Conference ID: " << c1.getId() << " | " << "Conference date: " << c1.getDate() << " | " << "Price: " << c1.getPrice() << endl;
    
    Conference c2(38, "20/04/2025");

    cout << endl;
    cout << "Testing overloaded + operator: \n";
    10.5f + c1;
    cout << "New price of c1 after an increase of 10.5: " << c1.getPrice() << endl;

    //testing < operator (comparing the year)
    if(c1 < c2){
        cout << "\nFirst conference is older!" << endl;
    }
    else{
        cout << "\nSecond conference is older!" << endl;
    }

    cout << "\nTesting HandleConference class" << endl;
    HandleConference manager;
    manager.add_conference(c1);
    manager.add_conference(c2);
    manager.display_conferences();

    cout << endl;

    //explaining the dangling pointer concept
    cout << "Dangling pointer test:" << endl;
    Conference* conf_ptr = new Conference(50, "10/10/2023");
    cout << "Price before deletion of conf_ptr: " << conf_ptr->getPrice();

    delete conf_ptr;

    cout << "\nTrying to access deleted object: " << endl;
    cout << conf_ptr->getPrice() << endl;
    
    return 0;
}