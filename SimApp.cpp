#include <iostream>
//#include "Event.h"
//#include "Node.h"
#include "EmptyDataCollectionException.h"
//#include "PriorityQueue.h"
#include "Queue.h"

using namespace std;
int main() {
    Queue<int> a;
    for(int i = 0 ; i < 10 ; i ++){
        a.enqueue(i);
        cout<<i<<endl;
    }
    for(int i = 0 ; i < 10 ; i ++){
        a.dequeue();
    }


}