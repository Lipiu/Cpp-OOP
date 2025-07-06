/*
(2p) Se consideră aplicația pentru gestiunea documentelor dintr - un dosar de admitere la facultate, 
folosind aspecte comune precum foaie matricolă, copie CI, copie diplomă certificat naștere, opțiuni facultăți, etc.
Definiți o clasă care modelează un aspect propriu acestei activități.Datele membre sunt private și sunt puse la dispoziție metode de acces.
Clasa conține cel puțin patru câmpuri, dintre care 
unul este alocat dinamic, 
constructori, 
metodele specifice claselor cu membri alocați dinamic.
Folosiți un membru static sau const. 

(1p) Supraîncărcați operator+ pentru adăugarea unei noi opțiuni în cadrul dosarului de admitere. 

(2p) Să se genereze un raport într - un fișier text cu informațiile dintr - un dosar de admitere la facultate. 

(2p) Să se exemplifice utilizarea mecanismul try - catch pentru a gestiona modificarea valorii unui atribut pentru 
care a fost implementată metoda setter.
Metoda setter trebuie sa genereze o excepție specifica aplicației(definita de programator) pentru date invalide.
Utilizatorul este avertizat  dacă introduce date invalide de la consolă având posibilitatea sa le reintroducă. 

(1p) Definiți și testați o metodă statică pentru afișarea numărului total de dosare create la un moment dat.
Metoda va contoriza dosarele create chiar dacă nu au fost depuse la facultate. 

(2p) Să se exemplifice conceptul de relație de “has a” între clase prin crearea unei clase 
pentru reprezentarea unui student care depune un dosar de admitere la facultate. 
*/

#pragma once
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

enum Optiuni {ASE, UPB, UNIVERSITATE};

class Dosar_admitere{
private:
    char* foaie_matricola = nullptr;
    string copie_ci = "";
    string diploma_bac = "";
    Optiuni optiuni;

    static int counter;

public:
    Dosar_admitere(const char* foaie_matricola, string copie_ci, string diploma_bac, Optiuni optiuni){
        this->set_foaie_matricola(foaie_matricola);
        this->copie_ci = copie_ci;
        this->diploma_bac = diploma_bac;
        this->optiuni = optiuni;
        counter++;
    }

    Dosar_admitere(const Dosar_admitere& d){
        this->set_foaie_matricola(d.foaie_matricola);
        this->copie_ci = d.copie_ci;
        this->diploma_bac = d.diploma_bac;
        this->optiuni = d.optiuni;
        counter++;
    }

    ~Dosar_admitere(){
        delete[] this->foaie_matricola;
        this->foaie_matricola = nullptr;
        counter--;
    }

    char* get_foaie_matricola() const{
        char* copy = new char[strlen(this->foaie_matricola) + 1];
        strcpy(copy, this->foaie_matricola);
        return copy;
    }

    string get_copie_ci() const{
        return this->copie_ci;
    }

    void set_foaie_matricola(const char* foaie_matricola){
        if(foaie_matricola == nullptr){
            throw "Acest camp trebuie completat!";
        }
        else{
            delete[] this->foaie_matricola;
            this->foaie_matricola = new char[strlen(foaie_matricola) + 1];
            strcpy(this->foaie_matricola, foaie_matricola);
        }
    }

    void set_copie_ci(string copie){
        if(copie.empty()){
            throw invalid_argument("Acest camp trebuie completat.");
        }
        else{
            this->copie_ci = copie;
        }
    }

    static void afisare_dosare(){
        cout << "\nNumar total de dosare: " << counter << endl;
    }

    //Supraîncărcați operator+ pentru adăugarea unei noi opțiuni în cadrul dosarului de admitere. 
    //nu stiu sa fac asta

    //Să se genereze un raport într - un fișier text cu informațiile dintr - un dosar de admitere la facultate. 
    friend ostream& operator<<(ostream& os, Dosar_admitere& d);

};

ostream& operator<<(ostream& os, Dosar_admitere& d){
    os << "Foaie matricola: " << d.get_foaie_matricola() << " | ";
    os << "Copie CI: " << d.copie_ci << " | ";
    os << "Diploma bac: " << d.diploma_bac << " | ";
    os << "Optiuni facultati: ";
    if(d.optiuni == 0){
        os << "ASE";
    }
    else if(d.optiuni == 1){
        os << "UPB";
    }
    else{
        os << "UNIVERSITATE";
    }

    return os;
}

int Dosar_admitere::counter = 0;