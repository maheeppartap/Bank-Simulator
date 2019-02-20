#include <iostream>
//#include "Event.h"
//#include "Node.h"
#include "EmptyDataCollectionException.h"
#include "PriorityQueue.h"
#include "Queue.h"


using namespace std;
int main() {
    PriorityQueue<int> a;
    for(int i = 0 ; i < 10 ; i ++){
        a.enqueue(i);
    }
    for(int i = 0 ; i < 10 ; i ++){
        cout << a.peek() << endl;
        a.dequeue();
    }

    PriorityQueue<int> b;

    b.enqueue(3);
    for(int i = 10 ; i >= 0; i--){
        b.enqueue(i);
    }
    while(!b.isEmpty()){
        cout << b.peek() << endl;
        b.dequeue();
    }


}