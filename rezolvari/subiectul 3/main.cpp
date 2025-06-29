#include <iostream>
#include <string>
#include "Conference.h"
using namespace std;

int main(){
    Conference c1(22.3, "28/05/2004");
    cout << "General info\n";
    cout << "Conference ID: " << c1.getId() << " | " << "Conference date: " << c1.getDate() << " | " << "Price: " << c1.getPrice() << endl;
    
    cout << "\nTesting overloaded + operator:\n";
    Conference c2(38, "20/04/2025");
    if(c1 < c2)
        cout << "First conference is older\n";
    else
        cout << "Second conference is older\n";
    
}