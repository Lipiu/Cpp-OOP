#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main(){
    cout << "---------------Testing ground---------------" << endl;

    Book b1("C++ Basics", "Anaser Duduianu", 10, 350.50);
    Book b2("Algorithms", "Fane Spoitoru", 15, 420.42);
    Library lib;

    lib.add_book(b1);
    lib.add_book(b2);
    lib.display_info();

    cout << "\nTesting operator + " << endl;

    100.2 + b1;
    cout << "Price after increase: " << b1.get_price();
}