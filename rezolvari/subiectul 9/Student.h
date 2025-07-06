#pragma once
#include "Dosar_admitere.h"
#include <string>
using namespace std;

class Student{
private:
    string name = "";
    int id = 0;
    Dosar_admitere dosar;

public:
    Student(const string name, int id, Dosar_admitere& dosar):name(name), id(id), dosar(dosar){}

    Dosar_admitere& get_dosar() {
        return this->dosar;
    }

    void info_student(){
        cout << "Nume: " << name << " | " << "ID: " << id;
        Dosar_admitere::afisare_dosare();
        cout << endl;
    }
};