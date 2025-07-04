#include <iostream>
#include "Character.h"
#include "Villain.h"
using namespace std;

int main(){

    Character c;
    Character c2;

    c.set_life_points(100);
    cout << c.get_life_points() << endl;
    c += 10; // should change life_points
    cout << c.get_life_points() << endl;

    if(c >= c2 == true){
        cout << "True" << endl;
    }
    else{
        cout << "False";
    }

    Villain v(true, "Venom", 100, "Symbiote");

    cout << "\nDangling pointer\n";

    Character* c_ptr = new Character("Spider-man", 30, "He can shoot webs");
    delete c_ptr;

    cout << c_ptr->get_life_points();

    cout << endl;
    c.do_something();
    v.do_something();

    return 0;
}