#include <iostream>
#include <fstream>
#include "Event.h"
#include "Node.h"
#include "EmptyDataCollectionException.h"
#include "PriorityQueue.h"
#include "Queue.h"


using namespace std;
int main() {
    Queue<int> BankLine;  //Empty bank line
    PriorityQueue<Event> EventQueue;    //Empty Event Queue

    bool tellerAvailable = true;    //Teller is available
//We have to place the input file in the cmake-build-debug folder for the program to read because it looks for it there by default
    ifstream file;
    file.open("simulationShuffled1.in");
    if( !file ) {
        cerr << "FAILED : Could not open the file" << endl;
        exit(-1);
    }
    int arrival,pTime;
    Event insertion;
    //Read input and insert into the Event Queue
    while( !file.eof()){
        file>>arrival;
        file>>pTime;
        cout<<"arrival at :"<<arrival<<endl;
        cout<<"Process time :"<<pTime<<endl;
        insertion.setTime(arrival);
        insertion.setLength(pTime);
        EventQueue.enqueue(insertion);
    }

    Event newEvent;
    //Event loop
    while(!EventQueue.isEmpty()){
        newEvent = EventQueue.peek();

        //getting current time
        int cuurenttime = newEvent.getTime();
    }


return 1;
}