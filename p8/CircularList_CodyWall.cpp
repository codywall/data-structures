//P8: Circular List
//Cody Wall
//03 December 2019
//Use your LinkList class as a starting point to make a class CircList.
//It will be a singly linked Circular List that has no end and no beginning.
//The only access to the list is a single reference, current, that can point to any link on the list.
//This reference can move around the list as needed.

#include <iostream>
using namespace std;

class Link
{
public:
    int data; //data
    Link *next; //pointer to next link

    Link(int newData)
    {
    data = newData;
    next = NULL;
    }

    void show()
    {
        cout << "{" << data << "} ";
    }
};

class CircularList
{
private:
    Link *current; //ptr to current link in list
    int numLinks;   //number of links counter
public:
    CircularList()
    {
        current = NULL; //no links on list yet
        numLinks = 0;
    }

    bool isEmpty(){ return numLinks == 0; } //true if list is empty

    bool isFound(int value)
    {
        if (!isEmpty())
            for (int i = 0; i < numLinks; i++)
            {
                if (current->data == value)
                    return true;
                current = current->next;
            }
        return false;
    }

    void displayList()
    {
        cout << endl << "The list: ";
        if (!isEmpty())
            for (int i = 0; i < numLinks; i++)
            {
                if (i < numLinks) {
                    current->show();
                    current = current->next;
                } else
                    break; //break if youve printed all the links in the list
            }
        else
            cout << "is empty" << endl;
    }

    void insertInitialLink(int newValue)
    {
        Link *newLink = new Link(newValue); //initialize new link
        current = newLink;                  //set new link as current
        current->next = newLink;
        numLinks++;                         //add one to the amount of links
    }

    void insertAfterValueFound(int newValue, int valueToFind)
//    Inserts a new Link that has iData = newValue
//    Inserts After the first Link which has valueToFind
//    Does not insert if valueToFind is not found
    {
        if (isFound(valueToFind)) {
            Link *newLink = new Link(newValue); //initialize new link
            newLink->next = current->next; //connect the new link to the link after current
            current->next = newLink;    // add the new link after the current link
            numLinks++;                 //increment the list length
        }
        else
            cout << valueToFind << " isn't in the list." << endl;

    }

    bool deleteLink(int valueToFind)
//    Deletes the first Link which has iData == valueToFind
//            Returns true upon successful deletion, false otherwise
    {
            //assumes non-empty list
            if (!isEmpty()) {
                while (current->data != valueToFind)  //search for link
                {
                    if (current->next->data == valueToFind)  { //check if the next link's data matches the value to find
                        Link *deleteThis = current->next;   //set the link to delete as a temp variable
                        current->next = deleteThis->next; // connect the current link to the one after the deleted link
                        delete deleteThis;
                        numLinks--;
                        return true;                   //found it
                }
                }
            }
    }
};

int main() {
    CircularList theList;
    theList.insertInitialLink(22);
    theList.displayList();
    theList.insertAfterValueFound(33, 22);
    cout << endl << "Inserted 33 after 22";
    theList.displayList();
    theList.insertAfterValueFound(44, 22);
    cout << endl << "Inserted 44 after 22";
    theList.displayList();
    theList.insertAfterValueFound(66, 44);
    cout << endl << "Inserted 66 after 44";
    theList.displayList();
    theList.deleteLink(66);
    cout << endl << "Deleted the link with value of 44";
    theList.displayList();


    return 0;
}

/*
/Users/cody/Desktop/fall19/data-structures/p8/cmake-build-debug/p8

        The list: {22}
Inserted 33 after 22
The list: {22} {33}
Inserted 44 after 22
The list: {22} {44} {33}
Inserted 66 after 44
The list: {44} {66} {33} {22}
Deleted the link with value of 44
The list: {44} {33} {22}
Process finished with exit code 0
*/