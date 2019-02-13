#include <iostream>
#include "Event.h"
#include "node.h"
//#include "EmptyDataCollectionException.h"
//#include "PriorityQueue.h"
using namespace std;
int main() {
    Event list;
    char a = 'b';
    list.setLength(20);
    list.setTime(22);
    list.setType(a);
    cout<<list;
    return 0;
    }