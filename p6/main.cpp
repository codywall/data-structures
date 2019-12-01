//P6: Dequeue
//Cody Wall
//28 November 2019
//Implement a double ended queue (dequeue) :
//insertLeft (int value)
//insertRight (int value)
//removeLeft
//removeRight

#include <iostream>
using namespace std;

class Queue
{
private:
    int size, front, rear, number_items;
    int *queueArray;

public:
    Queue(int newSize) //constructor
    {
        size = newSize;
        queueArray = new int[size];
        front = 0; //front moves forward (+) upon remove
        rear = -1; //rear moves forward (+) upon insert
    }

    //rear ++ upon insertion, if rear reaches far right, move it to far left
    void insert(int newValue) //put item at rear of queue
    {
        //deal w wraparound
        if (rear == size - 1) //reached the far right
            rear = -1; //move to beginning, so rear++ goes to 0

            rear++; //increment rear
            queueArray[rear] = newValue; //insert into rear
            number_items++; //add item
    }

    //front++ upon removal, if front reaches far right, move it to far left
    int remove()
    {
        int temp = queueArray[front++];
        if (front == size)
            front = 0;

        number_items--;
        return temp;
    }

    int peekFront() { return queueArray[front]; };
    int peekRear() { return queueArray[rear]; };
    bool isEmpty() { return (number_items == 0); };
    bool isFull() { return (number_items == size); };
    int qsize() { return number_items; };
};

int main() {
    Queue aQueue(5); // { }
    aQueue.insert(10);
    aQueue.insert(20);
    aQueue.insert(30);
    aQueue.insert(40);
    aQueue.insert(50);
    cout << "{ ";
    while ( !aQueue.isEmpty() )
    {
        cout << aQueue.peekFront() << " ";
        aQueue.remove();
    }
    cout << "}";
    return 0;
}