#include "DoctorAppointment.h"
#include <vector>
#include <iostream>
using namespace std;

class Pacient : public Appointment{
private:
    Appointment appointment;
    vector<Appointment> list;

public:
    Pacient(){}

    void pacient_app(){
        appointment.appointment_available();
        cout << "Pacient made an appointment" << endl;
    }

    void show_appointments(){
        cout << "Appointments made: " << this->list.size();
    }

    Pacient& operator+=(const Appointment& a){
        this->list.push_back(a);
        return *this;
    }
};