#include <iostream>
#include <fstream>
#include "Event.h"
#include "Node.h"
#include "EmptyDataCollectionException.h"
#include "PriorityQueue.h"
#include "Queue.h"


using namespace std;
int main() {
/*
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
                cout<<"Arrival at : "<<curentTime<<endl;
                EventQueue.enqueue(dep);
                tellerAvailable = false;
            } else{
                cout<<"Arrival at : "<<curentTime<<endl;
                BankLine.enqueue(customer);
            }
        } else {//Its a departure event now
            cout<<"departure at : "<<curentTime<<endl;
            EventQueue.dequeue();
            if( !BankLine.isEmpty()){
                //next customer
                customer = BankLine.peek(EmptyDataCollectionException());
                BankLine.dequeue();
                dep.setType('D');
                dep.setTime(curentTime+customer.getLength());
                EventQueue.enqueue(dep);
            }else {tellerAvailable = true;
            }
        }
    }
    */
    PriorityQueue<int> a = PriorityQueue<int>();

    for(int i = 10; i > 0; i--){
        a.enqueue(i);
    }
    while(!a.isEmpty()){

        try{
            cout<< a.peek() << endl;
            a.dequeue();
        }catch(EmptyDataCollectionException &e){
            cout << "caught empty queue except"<<endl;
        }
    }

    return 1;
}

