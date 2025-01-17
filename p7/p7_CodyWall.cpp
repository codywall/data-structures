//P7: Linked List
//Cody Wall
//01 December 2019
//Part 1) Write the Complete Link List (shown on pages 1-14 above)
//Part 2) Test the Link List:
//Part 3) Show your Results (as a multiline comment /* */ at the bottom of your code):
//Part 4) Add the following 3 new methods to LinkList:
//int sumData() – returns the sum of iData of all links
//int min() – returns the smallest iData of all links
//int numLinks() – returns the total number of links in the list
//Part 5) Test the new methods from the main()
//Part 6) Show your results

#include <iostream>
using namespace std;

class Link
{
public:
    int iData; //data
    double dData; //data
    Link *pNext; //pointer to next link

    Link(int id, double dd) //constructor
    {
        iData = id;
        dData = dd;
        pNext = NULL; //refer to nothing until connected
    }

    void displayLink()
    {
        cout << "{" << iData << ", ";
         cout << dData << "} ";
    }

};

class LinkList
{
private:
    Link *pFirst; //ptr to first link on list
public:
    LinkList()
    {
        pFirst = NULL; //no links on list yet
    }

    bool isEmpty()
    {
        return pFirst == NULL; //true if list is empty
    }

    void insertFirst(int id, double dd)
    {
        Link *pNewLink = new Link(id, dd); //make new Link
        pNewLink->pNext = pFirst; //newLink --> old first (1)
        pFirst = pNewLink;        //first --> newLink     (2)
    }

    Link *getFirst () { return pFirst; };

    Link *find(int key)                 //find link given key
    {                                   //assume non-empty list
        Link *pCurrent = pFirst;        //start at 'first'
        while (pCurrent->iData != key)  //while no match
        {
            if (pCurrent->pNext == NULL) //if end of list
                return NULL;             //didn't find it
            else
                pCurrent = pCurrent->pNext;
        }
        return pCurrent;
    }

    void removeFirst() //delete first link
    {                   //assumes list is not empty
        Link *pTemp = pFirst; //save first
        pFirst = pFirst->pNext; //unlink it: first --> old next
        delete pTemp;   //delete old first
    }

    bool remove(int key)            //remove link with given key
    {                               //assumes non-empty list
        Link *pCurrent = pFirst;
        Link *pPrevious = pFirst;
        while (pCurrent->iData != key)  //search for link
        {
            if (pCurrent->pNext ==NULL)
                return false;                   //didnt find it
                else
            {
                    pPrevious = pCurrent;       //go to next link
                    pCurrent = pCurrent->pNext;
            }
        }
        //key was found
        if (pCurrent == pFirst)             //if first link
            pFirst = pFirst->pNext;         //-change first
            else
                pPrevious->pNext = pCurrent->pNext; //otherwise bypass current link

                delete pCurrent;
                return true;
    }

    void displayList()
    {
        cout << "List (first-->last): ";
        Link *pCurrent = pFirst; //start at beginning of list
        while (pCurrent != NULL) //until end of list
        {
            pCurrent->displayLink(); //show the link
            pCurrent = pCurrent->pNext; //move to next link
        }
        cout << endl;
    }

    int sumIdata()             //returns sum of iData of all links
    {
        Link *pCurrent = pFirst; //start at beginning of list
        int sum = 0;

        while (pCurrent != NULL) //until end of list
        {
            sum += pCurrent->iData;     //add the current num to the sum variable
            pCurrent = pCurrent->pNext; //move to next link
        }
        return sum;
    }

    int min()                   //returns the smallest iData of all links
    {
        Link *pCurrent = pFirst; //start at beginning of list
        int min;
        while (pCurrent != NULL) {
            if (min > pCurrent->iData)          //if min is bigger than the current num
                min = pCurrent->iData;          //make min equal to the current num
            pCurrent = pCurrent->pNext; //move to next link
        }
        return min;
    }
    int numLinks()              //returns the number of links
    {
        Link *pCurrent = pFirst; //start at beginning of list
        int counter = 0;
        while (pCurrent != NULL) {
            counter++;          //add to the counter
            pCurrent = pCurrent->pNext; //move to next link
        }
        return counter;

    }


};

int main() {
    LinkList theList;                       //make new list
    theList.insertFirst(22, 2.99); //insert 4 items
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);
    theList.displayList();                  //show the list

    while (!theList.isEmpty())
    {
        Link *pTemp = theList.getFirst();   //get first link
        cout << "\nRemoving link with data ";
        pTemp->displayLink();               //display links data
        theList.removeFirst();              //remove it
    }
    cout << endl << "Empty list: ";
    theList.displayList();

    theList.insertFirst(22, 2.99); //reinsert 4 items
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);
    cout << "\nReinserting the links" << endl;
    theList.displayList();                  //show the list


    int findKey = 44;
    Link *pFind = theList.find(findKey);
    if (pFind)
        cout << "Found link with key: " << pFind->iData << endl;
    else
        cout << "Can't find link with key " << findKey << endl;

    if (theList.remove(findKey))
        cout <<"Deleted " << findKey << " from the list." << endl;
    else
        cout << "Did not delete " << findKey << " from the list." << endl;

    cout << "Link list after deletion: " << endl;
    theList.displayList();

    cout << "\nThe sum of all links is: " << theList.sumIdata() << endl;
    cout << "The smallest link is: " << theList.min() << endl;
    cout << "The number of links is: " << theList.numLinks() << endl;

    return 0;
}

/*
/Users/wall2294a/Documents/projects/data-structures/p7/cmake-build-debug/p7
        List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

Removing link with data {88, 8.99}
Removing link with data {66, 6.99}
Removing link with data {44, 4.99}
Removing link with data {22, 2.99}
Empty list: List (first-->last):

Reinserting the links
        List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}
Found link with key: 44
Deleted 44 from the list.
Link list after deletion:
List (first-->last): {88, 8.99} {66, 6.99} {22, 2.99}

The sum of all links is: 176
The smallest link is: 22
The number of links is: 3

Process finished with exit code 0
 */