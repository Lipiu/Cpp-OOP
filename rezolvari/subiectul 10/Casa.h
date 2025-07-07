/*
(3p) Se consideră o aplicație pentru gestionarea caselor dintr - un sat.Se vor urmări atribute specifice, precum:
suprafață, numar camere, cu sau fără etaj, etc.
Datele membre sunt private și sunt puse la dispoziție metode de acces.
Clasa conține cel puțin patru câmpuri, dintre care: 
unul este alocat dinamic, 
constructori, 
metodele specifice claselor cu membri alocați dinamic și operatorul de afișare.
Folosiți un membru static sau const. 

(1p) Se definește operator() (int) (operator funcție) care primește numărul de locatari din acea casă.
Operatorul returnează true dacă fiecare persoană are posibilitatea să aibă propria camera în casă sau false daca sunt
 mai puțin camera decât personae. 

(1p) Definiți operatorul == care compară două obiecte de tip Casa și returnează true dacă toate valorile atributelor sunt egale între ele. 

(2p) Exemplificați conceptul de relație de tip „is a” prin specializarea clasei Casa.
Testați soluția prin instanțierea noii clase. 
(2p) Explicați conceptele de early binding și late binding. 
(1p) Exemplificați conceptul de funcție template în C++.
*/

#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Casa{
private:
    char* suprafata = nullptr;
    int numar_locatari = 0;
    int numar_camere = 0;
    bool cu_etaj;

    static int counter;

public:
    Casa(const char* suprafata, int numar_locatari, int numar_camere, bool cu_etaj){
        this->set_suprafata(suprafata);
        this->numar_locatari = numar_locatari;
        this->numar_camere = numar_camere;
        this->cu_etaj = cu_etaj;

        counter++;
    }

    Casa(const Casa& c){
        this->set_suprafata(c.suprafata);
        this->numar_locatari = c.numar_locatari;
        this->numar_camere = c.numar_camere;
        this->cu_etaj = c.cu_etaj;

        counter++;
    }

    ~Casa(){
        delete[] this->suprafata;
        this->suprafata = nullptr;

        counter--;
    }

    void set_suprafata(const char* suprafata){
        if(suprafata == nullptr){
            throw "Eroare.";
        }
        else{
            delete[] this->suprafata;
            this->suprafata = new char[strlen(suprafata) + 1];
            strcpy(this->suprafata, suprafata);
        }
    }

    virtual void do_something(){
        cout << "Method from Casa.h" << endl;
    }

    //Se definește operator() (int) (operator funcție) care primește numărul de locatari din acea casă.
    //Operatorul returnează true dacă fiecare persoană are posibilitatea să aibă propria camera în casă sau false daca sunt
    //mai puțin camera decât personae. 
    bool operator()(int value){
        if(this->numar_camere >= value){
            return true;
        }
        else{
            return false;
        }
    }

    //Definiți operatorul == care compară două obiecte de tip Casa și returnează true dacă toate valorile atributelor sunt egale între ele. 
    bool operator==(const Casa& other){
        if(this == &other){
            return true;
        }
        if(this->suprafata == nullptr || other.suprafata == nullptr || strcmp(this->suprafata, other.suprafata) != 0){
            return false;
        }
        if(this->numar_locatari != other.numar_locatari){
            return false;
        }
        if(this->numar_camere != other.numar_camere){
            return false;
        }
        if(this->cu_etaj != other.cu_etaj){
            return false;
        }
        return true;
    }

    //operatorul de afisare
    friend void operator<<(ostream& os, Casa c);

};

void operator<<(ostream& os, Casa c){
    os << "Informatii despre casa:\n";
    if(c.suprafata != nullptr){
        os << "Suprafata: " << c.suprafata << " | ";
    }
    else{
        delete[] c.suprafata;
    }
    os << "Numar locatari: " << c.numar_locatari << " | ";
    os << "Numar camere: " << c.numar_camere << " | ";
    os << "Casa dispune de etaj: ";
    if(c.cu_etaj == false){
        os << "Nu";
    }
    else if(c.cu_etaj == true){
        os << "Da";
    }
    else{
        os << "Input invalid, te rog alege 'Da' sau 'Nu'.\n";
    }
}

int Casa::counter = 0;