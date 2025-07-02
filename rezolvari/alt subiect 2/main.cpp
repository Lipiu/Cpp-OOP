/*
(1p) Dangling Pointer Example
Provide a short code example demonstrating a dangling pointer using a pointer to a Movie object. Explain why it happens.
Test everything
*/

#include <iostream>
#include "Movie.h"
#include "RentalStore.h"
using namespace std;

int main(){

    Movie m1("28 Years Later", "Danny Boyle", 2025, 100);
    Movie m2("Once Upon a Time in Hollywood", "Quentin Tarantino", 2019, 120);

    RentalStore store;

    store.add_movie(m1);
    store.add_movie(m2);
    store.display_info();

    cout << "\nTesting overloaded + operator: " << endl;
    
    cout << "Initial price of m1: " << m1.get_price() << endl;
    102.2 + m1;

    cout << "Price after increase: " << m1.get_price();


    cout << "\n\nDangling pointer example:" << endl;
    Movie* dangling_p = new Movie("Dangling", "Pointer", 2024, 1.2);
    delete dangling_p;

    cout << "Price of dangling_p: " << dangling_p->get_price() << endl;


    return 0;
}