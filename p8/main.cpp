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
        cout << "{" << data << "}";
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
        cout << "The list: ";
        if (!isEmpty())
            for (int i = 0; i < numLinks; i++)
            {
                current->show();
                current = current->next;
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

//    Link *getFirst () { return pFirst; };
//
//    Link *find(int key)                 //find link given key
//    {                                   //assume non-empty list
//        Link *pCurrent = pFirst;        //start at 'first'
//        while (pCurrent->iData != key)  //while no match
//        {
//            if (pCurrent->pNext == NULL) //if end of list
//                return NULL;             //didn't find it
//            else
//                pCurrent = pCurrent->pNext;
//        }
//        return pCurrent;
//    }

//    void removeFirst() //delete first link
//    {                   //assumes list is not empty
//        Link *pTemp = pFirst; //save first
//        pFirst = pFirst->pNext; //unlink it: first --> old next
//        delete pTemp;   //delete old first
//    }

//    bool remove(int key)            //remove link with given key
//    {                               //assumes non-empty list
//        Link *pCurrent = pFirst;
//        Link *pPrevious = pFirst;
//        while (pCurrent->iData != key)  //search for link
//        {
//            if (pCurrent->pNext ==NULL)
//                return false;                   //didnt find it
//            else
//            {
//                pPrevious = pCurrent;       //go to next link
//                pCurrent = pCurrent->pNext;
//            }
//        }
//        //key was found
//        if (pCurrent == pFirst)             //if first link
//            pFirst = pFirst->pNext;         //-change first
//        else
//            pPrevious->pNext = pCurrent->pNext; //otherwise bypass current link
//
//        delete pCurrent;
//        return true;
//    }
//
//    void displayList()
//    {
//        int count;
//        cout << "List (first-->last): ";
//        Link *pCurrent = pFirst; //start at beginning of list
//        while (count <= numLinks) //until every link has been displayed
//        {
//            pCurrent->displayLink(); //show the link
//            pCurrent = pCurrent->pNext; //move to next link
//        }
//        cout << endl;
//    }

//    int sumIdata()             //returns sum of iData of all links
//    {
//        Link *pCurrent = pFirst; //start at beginning of list
//        int sum = 0;
//
//        while (pCurrent != NULL) //until end of list
//        {
//            sum += pCurrent->iData;     //add the current num to the sum variable
//            pCurrent = pCurrent->pNext; //move to next link
//        }
//        return sum;
//    }
//
//    int min()                   //returns the smallest iData of all links
//    {
//        Link *pCurrent = pFirst; //start at beginning of list
//        int min;
//        while (pCurrent != NULL) {
//            if (min > pCurrent->iData)          //if min is bigger than the current num
//                min = pCurrent->iData;          //make min equal to the current num
//            pCurrent = pCurrent->pNext; //move to next link
//        }
//        return min;
//    }
//    int numLinks()              //returns the number of links
//    {
//        Link *pCurrent = pFirst; //start at beginning of list
//        int counter = 0;
//        while (pCurrent != NULL) {
//            counter++;          //add to the counter
//            pCurrent = pCurrent->pNext; //move to next link
//        }
//        return counter;
//
//    }


};

int main() {
    CircularList theList;
    theList.insertInitialLink(22);
    theList.displayList();
//    LinkList theList;                       //make new list
//    theList.insertFirst(22, 2.99); //insert 4 items
//    theList.insertFirst(44, 4.99);
//    theList.insertFirst(66, 6.99);
//    theList.insertFirst(88, 8.99);
//    theList.displayList();                  //show the list
//
//    while (!theList.isEmpty())
//    {
//        Link *pTemp = theList.getFirst();   //get first link
//        cout << "\nRemoving link with data ";
//        pTemp->displayLink();               //display links data
//        theList.removeFirst();              //remove it
//    }
//    cout << endl << "Empty list: ";
//    theList.displayList();
//
//    theList.insertFirst(22, 2.99); //reinsert 4 items
//    theList.insertFirst(44, 4.99);
//    theList.insertFirst(66, 6.99);
//    theList.insertFirst(88, 8.99);
//    cout << "\nReinserting the links" << endl;
//    theList.displayList();                  //show the list
//
//
//    int findKey = 44;
//    Link *pFind = theList.find(findKey);
//    if (pFind)
//        cout << "Found link with key: " << pFind->iData << endl;
//    else
//        cout << "Can't find link with key " << findKey << endl;
//
//    if (theList.remove(findKey))
//        cout <<"Deleted " << findKey << " from the list." << endl;
//    else
//        cout << "Did not delete " << findKey << " from the list." << endl;
//
//    cout << "Link list after deletion: " << endl;
//    theList.displayList();
//
//    cout << "\nThe sum of all links is: " << theList.sumIdata() << endl;
//    cout << "The smallest link is: " << theList.min() << endl;
//    cout << "The number of links is: " << theList.numLinks() << endl;

    return 0;
}