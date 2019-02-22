#include <iostream>
#include <fstream>
#include "Event.h"
#include "Node.h"
#include "EmptyDataCollectionException.h"
#include "PriorityQueue.h"
#include "Queue.h"


using namespace std;
int main() {
    cout<<"Simulation Begins"<<endl;
    Queue<Event> BankLine;  //Empty bank line
    PriorityQueue<Event> EventQueue;    //Empty Event Queue
    int pplCounter = 0; //counts the number of customers
    float avg = 0;

    bool tellerAvailable = true;    //Teller is available
//We have to place the input file in the cmake-build-debug folder for the program to read because it looks for it there by default
    ifstream file;
    file.open("../simulationShuffled1.in");
    if( !file ) {
        cerr << "FAILED : Could not open the file" << endl;
        exit(-1);
    }
    int arrival,pTime;
    Event arr,dep;
    //Read input and insert into the Event Queue
    while( !file.eof()){
        file>>arrival;
        file>>pTime;
        arr.setTime(arrival);
        arr.setLength(pTime);
        arr.setType('A');
        EventQueue.enqueue(arr);    //in goes the arrival
    }

    Event newEvent;
    //Event loop
    while(!EventQueue.isEmpty()) {

        newEvent = EventQueue.peek();
        Event customer = newEvent;
        //getting current time
        int curentTime = newEvent.getTime();
        if (newEvent.getType() == 'A') {
            EventQueue.dequeue();
            if(BankLine.isEmpty() && tellerAvailable ){
                dep.setType('D');
                dep.setTime(curentTime+newEvent.getLength());
                dep.setLength(0);
                cout<<"Processing an arrival event at time:   "<<curentTime<<endl;
                EventQueue.enqueue(dep);
                pplCounter++;
                tellerAvailable = false;
            } else{
                cout<<"Processing an arrival event at time:   "<<curentTime<<endl;
                pplCounter++;
                BankLine.enqueue(customer);
            }
        } else {//Its a departure event now
            cout<<"Processing a departure event at time:  "<<curentTime<<endl;
            EventQueue.dequeue();
            if( !BankLine.isEmpty()){
                //next customer
                customer = BankLine.peek(EmptyDataCollectionException());
                BankLine.dequeue();
                dep.setType('D');
                dep.setTime(curentTime+customer.getLength());
                EventQueue.enqueue(dep);
                avg = avg + curentTime - customer.getTime();
               }else {
                tellerAvailable = true;
            }
        }
    }
    cout<<"Simulation Ends"<<endl<<endl;
    cout<<"Final Statistics:"<<endl;
    cout<<"    Total number of people processed:  "<<pplCounter<<endl;
    cout<<"    Average amount of time spent waiting: "<<avg/pplCounter<<endl;


    return 0;
}
