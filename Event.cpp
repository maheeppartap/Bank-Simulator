
#include <stdio.h>
#include "Event.h"
using namespace std;
/*todo: add a destructor
 *
*/
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
   type = NULL;
}

//overloading the << just to print the output of the object
ostream &operator << (ostream &os, const Event &e)  {
    os << e.getLength()<<" , " <<e.getTime() << " , "<<e.getType()<<endl;
    return os;
}

//todo: implementing this overload function to compare the priority of the events
bool operator <(Event a,Event b) {
    if (a.getType() < b.getType())
        return true;
    else if (a.getType() == b.getType()) {
        return a.getTime() <= b.getTime();
    }
    return false;
}
