#include <iostream>
#include <string>
#include <string.h>
using namespace std;


// SUB 1 

// 3p) Define classes that allow the management of data related to a weather condition (date, temperature, description, location, etc.), using members of public, private, protected, const, static type. 
// The class contains at least one dynamically allocated field (like recorded temperatures array), constructors, 
// 2 accessor methods (set will validate the received value) for an attribute of your choice and the class destructor. 
// (1p) Overload the ++ operator with the postfix form that allows you to change the schedule by delaying it by one hour 
// (1p) Exemplify  the overloading concept for the previously defined set method.  
// (1p) Using the previous class,exemplify the three different situations in which the copy constructor is called. 
// (2p) To exemplify the use of a “has a” type 1: M relation (one to several) by defining an additional class to manage the weather conditions for a region with multiple locations. You can use a STL collection but it is not mandatory. 
// (1p) Overload an operator of your choice to add new weather conditions data for the region. 
// (1p) Explain how virtualization works. You can use the debugger for that. 

class Weather{
private:
    string date = "";
    float* temperature = nullptr;
    int numberOfElements = 0;
    string description = "";
    char* location = nullptr;

public:

    //default constructor
    Weather(){
        cout << "Default constructor" << endl;
    }

    //constructor with parameters
    Weather(string newDate, float* newTemperature, int numberOfElements, string newDescription, char* newLocation){
        date = newDate;
        numberOfElements = numberOfElements;
        description = description;
        
        if(newTemperature != nullptr && numberOfElements > 0){
            temperature = new float[numberOfElements];
            for(int i = 0; i < numberOfElements; i++){
                temperature[i] = newTemperature[i];
            }
        }
        else{
            temperature = nullptr;
        }

        if(newLocation != nullptr){
            location = new char[strlen(newLocation) + 1];
            strcpy(location, newLocation);
        }
        else{
            location = nullptr;
        }
    }

    //copy constructor
    Weather(const Weather& weather){
        this->date = weather.date;
        this->description = weather.description;
        this->numberOfElements = weather.numberOfElements;

        if(weather.temperature != nullptr && weather.numberOfElements > 0){
            this->temperature = new float[weather.numberOfElements];
            for(int i = 0; i < weather.numberOfElements; i++){
                this->temperature[i] = weather.temperature[i];
            }
        }
        else{
            this->temperature = nullptr;
        }

        if(weather.location != nullptr){
            this->location = new char[strlen(weather.location) + 1];
            strcpy(this->location, weather.location);
        }
        else{
            this->location = nullptr;
        }
    }

    //destructor
    ~Weather(){
        //deallocation of temperature vector of floats
        delete[] temperature;
        temperature = nullptr;

        //deallocation of location vector of chars
        delete[] location;
        location = nullptr;
    }

    //getters
    string getDate(){
        return this->date;
    }

    float* getTemperature(){
        float* copy = new float[this->numberOfElements];
        for(int i = 0; i < numberOfElements; i++){
            copy[i] = temperature[i];
        }
        return copy;
    }

    string getDescription(){
        return this->description;
    }

    string getLocation(){
        if(location == nullptr){
            return nullptr;
        }
        else{
            char* copy = new char[strlen(this->location) + 1];
            strcpy(copy, location);
            return copy;
        }
    }

    //setters
    void setDate(string newDate){
        if(newDate.empty()){ // sau newDate == ""
            throw "Date cannot be empty, (format DD/MM/YYYY)!";
        }
        else{
            this->date = newDate;
        }
    }

    void setTemperature(int numberOfElements, float* temperature){
        if(temperature == nullptr){
            throw "Temperature field cannot be empty!";
        }
        else{
            for(int i = 0; i < numberOfElements; i++){
                this->temperature[i] = temperature[i];
            }
        }
    }

    void setDescription(string newDescription){
        if(newDescription.empty()){
            throw "Description field cannot be empty";
        }
        else{
            this->description = newDescription;
        }
    }

    void setLocation(char* newLocation){
        if(newLocation == nullptr){
            throw "Location field cannot be empty!";
        }
        else{
            delete[] this->location;
            this->location = new char[strlen(this->location) + 1];
            strcpy(this->location, newLocation);
        }
    }

    //overloading the ++ operator (delay by one day) -> format: DD/MM/YYYY : example: 01/02/2001
    Weather Weather::operator++(int){
        Weather copy = *this;

        if(date.empty() != false && date.length() == 10){
            string dayString = date.substr(0,2); // means we start from position 0 and we take 2 characters (for day) -> 01
            string monthString = date.substr(3,2); // means we start from position 3 and we take 2 characters (for month) -> 02
            string yearString = date.substr(6,4); // means we start from positon 6 and we take 4 characters (for year) -> 2001

            int day = stoi(dayString);
            int month = stoi(monthString);
            int year = stoi(yearString);

            day++;

            string newDayStr;
            if(day < 10){
                newDayStr = "0" + to_string(day);
            }
            else{
                newDayStr = to_string(day);
            }

            string newMonthStr;
            if(month < 10){
                newMonthStr = "0" + to_string(month);
            }
            else{
                newMonthStr = to_string(month);
            }

            /*
            here we check for leap year and if the date overflows we go to next year
            int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
            if(month == 2){
                bool isLeap;
                if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
                    daysInMonth[1] = 29;
                }
            }
            day++;

            if(day > daysInMonth[month - 1]){
                day = 1;
                month++;

                if(month > 12){
                    month = 1;
                    year++;
                }
            }
            */
            date = newDayStr + "/" + newMonthStr + "/" + yearString;
        }
        return copy;
    }
};