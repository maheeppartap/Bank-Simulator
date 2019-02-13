
#include <stdio.h>
#include "Event.h"
using namespace std;


void Event::setTime(const int t) {
    time = t;
}

void Event::setType(const char m) {
    type = m;
}

void Event::setLength(const int l) {
    length = l;
}

int Event::getTime() const {
    return time;
}

char Event::getType() const{
    return type;
}

int Event::getLength() const {
    return length;
}




Event::Event() {
   length = 0;
   time = 0;
   type = 'a';
}


ostream &operator << (ostream &os, const Event &e)  {
    os << e.getLength()<<" , " <<e.getTime() << " , "<<e.getType()<<endl;
    return os;
}


