#include <iostream>
#include "Weather.cpp"
#include <vector>
using namespace std;

// (2p) To exemplify the use of a “has a” type 1: M relation (one to several) 
// by defining an additional class to manage the weather conditions for a region with multiple locations. You can use a STL collection but it is not mandatory. 

class Region{
private:
    string name;
    vector<Weather> weatherData; //using STL
    
    //or classic array
    Weather weatherData[100];
    int numberOfWeather = 0;

public:
    

    Region(){
        name = "";
        numberOfWeather = 0;
    }

    Region(string newName){
        name = newName;
        numberOfWeather = 0;
    }

    void addWeather(const Weather& w){
        //if we use STL
        // weatherData.push_back(w);    
        
        //if we use classic array
        if(numberOfWeather < 100){
            weatherData[numberOfWeather] = w;
            numberOfWeather++;
        }
        else{
            cout << "Array is full. Cannot add any more data" << endl;
        }
    }

    //optional
    void displayWeather(){
        cout << "Region: " << name << endl;
        for(int i = 0; i < numberOfWeather; i++){
            cout << "Weather #" << (i+1) << weatherData[i].getDate() << ", " << weatherData[i].getDescription() << endl;
        }
    }
};