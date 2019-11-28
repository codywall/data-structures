//Cody Wall
//26 November 2019
//P5: Sorts (Bubble, Selection, and Insertion)
//Use the provided (in this document) examples to add (and test!) the following methods (functions) to your EncapsulatedArray class

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
    void deleteIndex(int index_to_delete);
    void selectSort();
    void bubbleSort();
    void insertSort();
    void swap(int index1, int index2);
    void show();
    void noDups();
    void insert_in_order(int number_to_insert);
};

EncapsulatedArray::EncapsulatedArray(int size) {
    array = new int[size]; // dynamically allocated array
    number_of_elements = 0;
}

//append a number to the end of the array
void EncapsulatedArray::add(int number_to_add)
{
    array[number_of_elements] = number_to_add;
    number_of_elements++;
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

void EncapsulatedArray::swap(int index1, int index2)
//    swaps two elements of the same array provided index1 and index2
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void EncapsulatedArray::bubbleSort()
//    uses the bubble sort algorithm implementation to sort the encapsulated array
    {
        for (int j = 0; j < number_of_elements - 1; j++)
            for (int i = 0; i < number_of_elements - 1; i++)
                if (array[i] > array[i + 1])
                {
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1]  = temp;
                }
            }

void EncapsulatedArray::selectSort()
//    uses the selection sort algorithm implementation to sort the encapsulated array
{
    int min, min_index;
    for (int current_index = 0; current_index < number_of_elements - 1; current_index++)
    {
        min_index = current_index;

        for(int i = current_index + 1; i < number_of_elements; i++)
            if (array[i] < array[min_index])
                min_index = i;

            swap(current_index, min_index); // swap is outside the loop so it is completed after min is found
    }
}

void EncapsulatedArray::insertSort()
//    uses the insert sort algorithm implementation to sort the encapsulated array
{
    int in, out, temp;

    for(out = 1; out < number_of_elements; out++) {
        in = out;
        temp = array[in]; // store the element outside sorted section in temp
        while (in > 0 && array[in - 1] > temp) //sort through the array to the left til smaller int found
        {
            array[in] = array[in - 1]; //shift all sorted ints to the right
            in--;
        }
        array[in] = temp; //insert the element into the last sorted space
    }
}

void EncapsulatedArray::deleteIndex(int index_to_delete)
//    deletes an element at index_to_delete, shifts-left elements on top of deleted element
{
    for (int i = index_to_delete; i < number_of_elements - 1; i++) //start at index of element to delete
        array[i] = array[i + 1]; //shift the elements to the left
    number_of_elements--;   //adjust size of array
}

void EncapsulatedArray::noDups()
//    removes all duplicates from a sorted array, shifts-left elements on top of deleted elements
{
    for (int i = 0; i < number_of_elements - 1; i++)
        if (array[i] == array[i + 1]) {
            deleteIndex(i);
        }
}

void EncapsulatedArray::insert_in_order(int number_to_insert)
//    insert a number in the correct order, in an already sorted array
{
    int i;
    for (i = 0; i < number_of_elements; i++)
        if (array[i] > number_to_insert) // loop through until larger number is found
            break; //then break the loop

            for (int j = number_of_elements - 1; j >= i; j--) //create another loop
            {
                array[j + 1] = array[j]; //shift the larger elements to the right to make room
            }
        array[i] = number_to_insert; //insert the number into the space we created
        number_of_elements++;
}

int main() {
    EncapsulatedArray anArray(5);
    anArray.add(33);
    anArray.add(88);
    anArray.add(939);
    anArray.add(2);
    anArray.add(42);
    anArray.add(80);
    anArray.show();
    cout << "Bubble sorted ";
    anArray.bubbleSort();
    anArray.show();
    anArray.add(66);
    anArray.add(1);
    anArray.show();
    anArray.selectSort();
    cout << "Select sorted ";
    anArray.show();
    anArray.add(3);
    anArray.add(66);
    anArray.show();
    anArray.insertSort();
    cout << "Insertion sorted ";
    anArray.show();
    anArray.deleteIndex(2);
    cout << "Deleted the element at index 2...";
    anArray.show();
    cout << "Delete duplicates in the ";
    anArray.noDups();
    anArray.show();
    cout << "Insert the number 36 in order: ";
    anArray.insert_in_order(36);
    anArray.show();
    return 0;
}


//OUTPUT
///Users/cody/Desktop/fall19/csis45/p5/cmake-build-debug/p5
//array = {33, 88, 939, 2, 42, 80}
//Bubble sorted array = {2, 33, 42, 80, 88, 939}
//array = {2, 33, 42, 80, 88, 939, 66, 1}
//Select sorted array = {1, 2, 33, 42, 66, 80, 88, 939}
//array = {1, 2, 33, 42, 66, 80, 88, 939, 3, 66}
//Insertion sorted array = {1, 2, 3, 33, 42, 66, 66, 80, 88, 939}
//Deleted the element at index 2...array = {1, 2, 33, 42, 66, 66, 80, 88, 939}
//Delete duplicates in the array = {1, 2, 33, 42, 66, 80, 88, 939}
//Insert the number 36 in order: array = {1, 2, 33, 36, 42, 66, 80, 88, 939}
//
//Process finished with exit code 0
