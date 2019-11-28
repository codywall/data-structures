//Cody Wall
//09/30/2019
//P3: Array Encapsulation
//Type up the program below and get it working.
//Then add the following functions/methods/actions:

//void insertFirst(int number_to_add)  - assumes array is big enough, inserts element at index 0, and then shifts all others to the right.
//void deleteNumber(int number_to_delete) - If a number is found, delete that element and shifts all others to the left (deletes 1 number max).
//void sort() - sorts the array using bubble sort that we learned in CSIS45

#include <iostream>
using namespace std;

class EncapsulatedArray
{
    private:
        int *array; //dynamically allocated array
        int number_of_elements;
    public:
        EncapsulatedArray(int size);
        void add(int number_to_add);
        void insertFirst(int number_to_insert);
        void deleteFirst();
        void sort();
        void show();
};

EncapsulatedArray::EncapsulatedArray(int size) {
    array = new int[size]; // dynamically allocated array
    number_of_elements = 0;
}

//add the first number
void EncapsulatedArray::add(int number_to_add)
{
    array[number_of_elements] = number_to_add;
    number_of_elements++;
}

//insert a number into the first index position
void EncapsulatedArray::insertFirst(int number_to_insert)
{
    for (int i = number_of_elements - 1; i >= 0; i--)
        array[i + 1] = array[i];
    array[0] = number_to_insert;
    number_of_elements++;
}

//delete the first element in the array
void EncapsulatedArray::deleteFirst()
{
    for (int i = 0; i < number_of_elements; i++)
        array[i] = array[i + 1];  //shift all values left
        number_of_elements--; //decrease number of elements in array
}

void EncapsulatedArray::sort()
{
    /// BUBBLE SORT
    for (int j = 0; j < number_of_elements - 1; j++)
    {
        for (int i = 0; i < number_of_elements - 1; i++)
        {
            if (array[i] > array[i+1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1]  = temp;
            }
        }
    }
}

//show arrays
void EncapsulatedArray::show() {
    if (number_of_elements == 1)
    {
        cout << "array = {" << array[0] << "}\n";
        return;
    }

    int i;
    cout << "array = {";
    for (i = 0; i < number_of_elements - 1; i++)
        cout << array[i] << ", " ;
    cout << array[i] << "}\n";
}

int main() {
    EncapsulatedArray anArray(5);
    cout << "add initial number: " << endl;
    anArray.add(9);
    anArray.show();
    cout << "add two more numbers: " << endl;
    anArray.add(101);
    anArray.add(9);
    anArray.show();
    cout << "add a number to the beginning of the array: " << endl;
    anArray.insertFirst(66);
    anArray.show();
    cout << "delete the first number: " << endl;
    anArray.deleteFirst();
    anArray.show();
    cout << "move the largest number all the way to the right: " << endl;
    anArray.sort();
    anArray.show();
}

/*
/Users/cody/Desktop/fall19/csis45/p3/cmake-build-debug/p3
        add initial number:
array = {9}
add two more numbers:
array = {9, 101, 9}
add a number to the beginning of the array:
array = {66, 9, 101, 9}
delete the first number:
array = {9, 101, 9}
move the largest number all the way to the right:
array = {9, 9, 101}

Process finished with exit code 0
*/
