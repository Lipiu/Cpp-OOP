#include "Game.h"
#include "HorrorGame.h"
#include <iostream>
using namespace std;

int main(){
    Game g1("Teemo", 700, "DPS", false);
    Game g2("Freddy Fazbear", 1500, "Scary", true);

    HorrorGame hg;

    hg.add_game(g1);
    hg.add_game(g2);

    hg.display_info();

    cout << "Method from parent class:\n";
    g1.do_something();

    cout << endl;
    cout << "Method from child class:\n";
    hg.do_something();

    bool value = g1 >= g2;
    if(value == 0){
        cout << "g1 has less points than g2" << endl;
    }
    else{
        cout << "g1 has more points than g2" << endl;
    }

    cout << endl;
    cout << "g1 before increase in life points: " << g1.get_life_points() << endl;
    g1 += 2000;
    cout << "g1 after increase in life points: " << g1.get_life_points();

    cout << endl;
    
    cout << "Dangling pointer example:\n";
    Game* g_ptr = new Game("Sonic", 20, "Speed", false);
    delete g_ptr;
    cout << "life points: " << g_ptr->get_life_points(); //invalid value


    return 0;
}