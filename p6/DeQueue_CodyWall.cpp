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
    void insertRight(int newValue) //put item at rear of queue
    {
        if (!isFull()) {
            //deal w wraparound
            if (rear == size - 1) //reached the far right
                rear = -1; //move to beginning, so rear++ goes to 0

            rear++; //increment rear
            queueArray[rear] = newValue; //insert into rear
            number_items++; //add item
        } else {
            cout << " * The queue is full * ";
        }
    }

    //front ++ upon insertion, if front reaches far left, move it to far right
    void insertLeft(int newValue) //put item at front of queue
    {
        if (!isFull()) {
            //deal w wraparound
            if (front == 0) //reached the far left
                front = size; //move to end, so front++ goes to the end

            front--; //decrement front
            queueArray[front] = newValue; //insert into front
            number_items++; //add item
        } else {
            cout << " * The queue is full * ";
        }
    }

    //front++ upon removal, if front reaches far right, move it to far left
    int removeLeft()
    {
        if (!isEmpty()) {
            int temp = queueArray[front++];
            if (front == size)
                front = 0;

            number_items--;
            return temp;
        } else {
            return 0;
        }
    }

    //rear-- upon removal, if rear reaches far left, move it to far right
    int removeRight()
    {
        if (!isEmpty()) {
            int temp = queueArray[rear--];
            if (rear == 0)
                rear = size;

            number_items--;
            return temp;
        } else {
            return 0;
        }
    }

    int peekFront() { return queueArray[front]; };
    int peekRear() { return queueArray[rear]; };
    bool isEmpty() { return (number_items == 0); };
    bool isFull() { return (number_items == size); };
    int qsize() { return number_items; };
};

int main() {
    Queue aQueue(5); // { }
    aQueue.insertRight(10);
    aQueue.insertRight(20);
    aQueue.insertRight(30);
    aQueue.insertLeft(50);
    aQueue.insertLeft(40);
    cout << "Deleted number on the left: " << aQueue.removeLeft() << endl;
    cout << "Deleted number on the right: " << aQueue.removeRight() << endl;
    cout << aQueue.qsize() << " items in the queue: ";
    cout << "{ ";

    while ( !aQueue.isEmpty() )
    {
        cout << aQueue.peekFront() << " ";
        aQueue.removeLeft();
    }
    cout << "} " << endl;
    return 0;
}

///Users/cody/Desktop/fall19/data-structures/p6/cmake-build-debug/p6
//        Deleted number on the left: 40
//Deleted number on the right: 30
//3 items in the queue: { 50 10 20 }
//0
//Process finished with exit code 0
