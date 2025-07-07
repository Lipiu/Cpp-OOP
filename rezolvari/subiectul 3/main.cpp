#include "VideoCall.h"
#include "Archive.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    VideoCall vc1("OOP Tutoring", "Zoom", 19, 3, 1);
    
    //testing overloaded '+' operator
    VideoCall vc2 = 10 + vc1;
    
    VideoCall vc3("Java Tutoring", "Zoom", 23, 2, 2);
    vc2.set_start_time(21);

    cout << vc2.get_duration();
    cout << endl;

    // testing overloaded '>' operator
    if(vc1 > vc2){
        cout << "vc2 incepe inaintea lui vc1" << endl;
    }
    else{
        cout << "vc1 incepe inaintea lui vc2" << endl;
    }

    cout << endl;

    // 'has a' relationship test
    Archive archive;
    archive.add_video_call(vc1);
    archive.add_video_call(vc3);
    archive.display();

    //dangling pointer
    //a dangling pointer is a pointer that no longer points to a valid memory address
    VideoCall* vc_ptr = new VideoCall("Test dangling pointer", "Memory leak", 1, 1, 10);
    delete vc_ptr;
    cout << vc_ptr->get_duration(); //vc_ptr no longer points to a valid memory address but still displays the correct output
    //but if we check the debugger we can see that vc_ptr duration is a garbage value

    //writing to a binary file
    int duration = vc1.get_duration();
    
    ofstream out("file.bin", ios::binary);
    out.write((char*)&duration, sizeof(duration));

    return 0;
}