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
            sum += pCurrent->iData;
//            pCurrent->displayLink(); //show the link
            pCurrent = pCurrent->pNext; //move to next link
        }
        return sum;
    }

    int min()                   //returns the smallest iData of all links
    {

    }

    int numLinks()              //returns the number of links
    {

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
