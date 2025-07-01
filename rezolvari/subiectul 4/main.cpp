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

    //operator +
    std::cout << "\nTesting operator + " << std::endl;

    100.2 + b1;
    std::cout << "Price after increase: " << b1.get_price();

    std::cout << "\n";

    // operator -
    std::cout << "\nTesting operator - " << std::endl;
    Book b4 = b1 - b2;
    std::cout << "Price of b1: " << b1.get_price() << std::endl;
    std::cout << "Price of b2: " << b2.get_price() << std::endl;
    std::cout << "Price of b4 (b1 - b2): " << b4.get_price() << std::endl;

    std::cout << std::endl;

    // am dat overload si la operatorii *, /, != dar testarea e la fel

    // operator << 
    std::cout << "Testing overloaded << operator:\n";
    std::cout << b1;

    // std::cout << "\n\nTesting overloaded >> operator: \n";
    // std::cin >> b1;

    // == operator
    Book b3 = b2;
    std::cout << "\n\nTesting overloaded == operator: \n";
    if(b3 == b2){
        std::cout << "The books are the same";
    }
    else{
        std::cout << "The books are different";
    }

    // ++ prefix
    std::cout << "\n\nTesting overloaded ++ prefix:\n";
    std::cout << "Before prefix ++ the price of b2 was: " << b2.get_price() << std::endl;
    
    ++b2;
    std::cout << "After prefix ++ the price of b2 is: " << b2.get_price();

    // ++ postfix
    std::cout << "\n\nTesting overloaded ++ postfix:\n";
    Book old = b1++;

    std::cout << "Before postfix ++ the price of b1 was: " << old.get_price() << std::endl;
    std::cout << "After postfix ++ the price of b1 is: " << b1.get_price() << std::endl;

    // -- prefix
    std::cout << "\nTesting overloaded -- prefix:\n";
    std::cout << "Before prefix -- the price of b3 was: " << b3.get_price() << std::endl;
    
    --b3;
    std::cout << "After prefix -- the price of b3 is: " << b3.get_price();


    // -- postfix
    std::cout << "\n\nTesting overloaded -- postfix:\n";
    Book old2 = b3--;

    std::cout << "Before postfix -- the price of b3 was: " << old2.get_price() << std::endl;
    std::cout << "After postfix -- the price of b3 is: " << b3.get_price() << std::endl;
}