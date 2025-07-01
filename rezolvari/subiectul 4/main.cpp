#include <iostream>
#include "Book.h"
#include "Library.h"

int main(){
    std::cout << "---------------Testing ground---------------" << std::endl;

    Book b1("C++ Basics", "Anaser Duduianu", 10, 350.50);
    Book b2("Algorithms", "Fane Spoitoru", 15, 420.42);
    Library lib;

    lib.add_book(b1);
    lib.add_book(b2);
    lib.display_info();

    std::cout << "\nTesting operator + " << std::endl;

    100.2 + b1;
    std::cout << "Price after increase: " << b1.get_price();

    std::cout << "\n\n";

    std::cout << "Testing overloaded <<:\n";
    std::cout << b1;
}