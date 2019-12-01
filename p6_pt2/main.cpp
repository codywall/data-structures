#include <iostream>;
using namespace std;

class CharStack
{
private:
    int top; //top of stackArray
    char *stackArray;

public:
    int size; //size of stackArray

    CharStack(int newSize)
    {
        size = newSize; //set array size
        stackArray = new char[size]; //make a new dynamic array
        top = -1; //no items yet
    }

    //put items on top of stack
    void push(char newValue) {
        stackArray[++top] = newValue; //increment top, insert item
    };

    //take item from top of stack
    char pop() {
        return stackArray[top--]; //access item, decrement top
    }

    //look at item on top of stack
    int peek() {
        return stackArray[top]; //access item
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

};

int main() {
    CharStack aStack(12);

   char a[] = {'h','e','l','l','o',' ','w','o','r','l','d','!'};

   for (int i = 0; i < aStack.size; i++)
    aStack.push(a[i]);

    cout << "Popping the values out of the stack: ";
    while (!aStack.isEmpty())
        cout << aStack.pop() << " ";

    cout << endl;

    return 0;
}

//
///Users/cody/Desktop/fall19/data-structures/p6_pt2/cmake-build-debug/p6_pt2
//        Popping the values out of the stack: ! d l r o w   o l l e h
//
//Process finished with exit code 0
