//Cody Wall
//09/30/2019
//P2: Classes and Objects
//Type up the sample program and get it to work, then:
//add the private Property weight (decimal number)
//add the public Actions that change and show the property: showWeight and changeWeight
//Test the actions from the actions from the main() and show your program test run.


#include <iostream>
using namespace std;

class Person
{
private: //age is private
    int age;
    float weight;
public: // provides ways to access the private age
    void showAge();
    void showWeight();
    void changeAge(int newAge);
    void changeWeight(float newWeight);
    void bubbleSort();
    Person(); //Default Constructor
    Person(int newAge, float newWeight); //Explicit Constructor
};

void Person::showAge() {
    cout << "age: " << age << endl;
}

void Person::showWeight() {
    cout << "weight: " << weight << endl;
}

void Person::changeAge(int newAge)
{
    age = newAge;
}

void Person::changeWeight(float newWeight)
{
    weight = newWeight;
}

// loop to move the biggest number to the right
void Person::bubbleSort()
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size-1; i++)
        {
            if (k[i] > k[i+1])
            {
                temp = k[i];
                k[i] = k[i+1];
                k[i+1]  = temp;
            }
        }
    }
}

Person::Person() //default Constructor
{
    age = 101;
    weight = 150.5;
}

Person::Person(int newAge, float newWeight) //explicit constructor
{
    age = newAge;
    weight = newWeight;
}


int main() {
    Person alex; // use default Constructor
    alex.showAge(); // Garbage w/o Default Constructor, 101 with
    alex.showWeight();
    alex.changeAge(36); //changes age value to 36
    alex.changeWeight(203.56);
    alex.showAge();
    alex.showWeight();

    Person child(8, 33.4);
    child.showAge();
    child.showWeight();
    child.changeWeight(40.2);
    child.showWeight();

    return 0;
}

///Users/cody/Desktop/fall19/csis45/p2_cody-wall/cmake-build-debug/p2_cody_wall
//        age: 101
//weight: 150.5
//age: 36
//weight: 203.56
//age: 8
//weight: 33.4
//weight: 40.2
//
//Process finished with exit code 0
