#include "Config.h"
#include <iostream>
using namespace std;

int main(){

    Config c1("Vivobook", "Intel", 10, "Nvidia 3060", "2025-2030", 1);

    cout << "Initial cpu gen: " << c1.get_cpu_gen() << endl;

    cout << "Cpu gen after using overloaded *: ";
    Config new_gen = c1 * 10;
    cout << new_gen.get_cpu_gen() << endl;

    cout << endl;

    cout << "Testing cast to string operator\n";
    
    string desc = static_cast<string>(c1);
    cout << desc;

    return 0;
}