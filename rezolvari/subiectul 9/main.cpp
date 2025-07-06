#include <iostream>
#include <fstream>
#include "Dosar_admitere.h"
#include "Student.h"
using namespace std;

int main(){

    Dosar_admitere d1("Foaie matricola", "Copie ci", "Are diploma bac", ASE);
    Student s1("Anaser Duduianu", 1, d1);

    ofstream file("Dosar facultate.txt");
    if(file.is_open()){
        file << d1;
        file.close();
    }

    // string input;
    // while(true){
    //     cout << "Introduceti copie ci: ";
    //     getline(cin, input);

    //     try{
    //         d1.set_copie_ci(input);
    //         break;
    //     }
    //     catch(invalid_argument& e){
    //         cout << "Eroare " << e.what() << "\nTe rog incearca din nou!" << endl;
    //     }
    // }

    // cout << "Ai introdus: " << d1.get_copie_ci() << endl;
    
    s1.info_student();
    // Dosar_admitere::afisare_dosare();


    return 0;
}