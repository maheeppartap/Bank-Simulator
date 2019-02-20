//
// Created by mahee on 2019-02-12.
//

#ifndef ASSIGNMENT_3_EVENT_H
#define ASSIGNMENT_3_EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event{
private:
    int time;
    char type;
    int length;

public:
    //Default constructor
    Event();
    //Destructor

//Here are the setters
    void setTime(int time);
    void setType( char type);
    void setLength(int length);


//Getters
    int getTime()const;
    char getType()const;
    int getLength()const;

    friend ostream&operator<<(ostream & os,const Event & e);

    friend bool operator <(Event a,Event b);

    friend bool operator >(Event b,Event a);
};
#endif //ASSIGNMENT_3_EVENT_H
