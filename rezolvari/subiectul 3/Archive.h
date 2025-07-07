//Exemplify the concept of a “has a” relation by defining a new class that handles several objects of the previous class type.
// Implement a method that allows you to add an object to your collection.
// You can use STL collections but it is not mandatory.Test the solution in the main().

#pragma once
#include "VideoCall.h"
#include <vector>
#include <iostream>
using namespace std;

class Archive{
private:
    vector<VideoCall> list;
    VideoCall vc;

public:
    Archive(){}

    void add_video_call(const VideoCall& vc){
        list.push_back(vc);
    }

    void display(){
        cout << "List of video calls:" << endl;
        for(int i = 0; i < list.size(); i++){
            cout << "Video call #" << (i+1) << endl;
            char* temp_name = list[i].get_name();
            if(list[i].get_name() != nullptr){
                cout << "Name of the video conference: " << temp_name << endl;
                delete[] temp_name;
            }
            cout << "Platform used: " << list[i].get_platform_used() << endl;
            cout << "Start time (day): " << list[i].get_start_time() << endl;
            cout << "Duration (hours): " << list[i].get_duration() << endl;
            cout << "--------------------------------------------" << endl;
        }
    }
};