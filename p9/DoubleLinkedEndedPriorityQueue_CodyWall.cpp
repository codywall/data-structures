/*
 P9: Double Ended, Double-Linked, Priority-Queue List
 Cody Wall
 14 December 2019
 We can remove the first , last or, any link
 Each Link has a pNext and pPrevious
 Links are always Inserted in Order
 Show the list forward (front to end)
 Show the list backward (end to front).
 Link with a given value can be removed.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Link
{
public:
    int data; //data
    Link *pNext, *pPrev; //pointer to previous and next link
    Link(int newData) { // constructor
        data = newData;
        pNext = NULL;
        pPrev = NULL;
    }

    void displayLink()
    {
        cout << "{ " << setw(3) << data << "\t:\t"
                << setw(14) << pPrev << "\t:\t\t" << &data
                << "\t:\t" << setw(14) << pNext <<  "}\n";
    }
};

class DoubleEndedList
{
private:
    Link *pFirst, *pLast; //ptr to first link on list, last
public:
    DoubleEndedList()
    {
        pFirst = NULL; //no links on list yet
        pLast = NULL;
    }
    void displayFirst() { cout << "First: "; pFirst->displayLink();}
    void displayLast() { cout << "Last: "; pLast->displayLink();}

    bool isEmpty()
    {
        return pFirst == NULL; //true if list is empty
    }

    void insertLink(int newData) {
        if (isEmpty()) {
            Link *pNewLink = new Link(newData); //make new Link
            pNewLink->pNext = pFirst; //newLink --> old first (1)
            pFirst = pNewLink;
            pLast = pNewLink;
            return; //cant forget return or bottom code will be run
        }
        else if (newData < pFirst->data) {
            Link *pNewLink = new Link(newData); //make new Link
            pNewLink->pNext = pFirst; //newLink --> old first (1)
            pFirst->pPrev = pNewLink;
            pFirst = pNewLink;
            return;
        }
        else if (newData > pLast->data) {
            Link *pNewLink = new Link(newData); //make new Link
            pNewLink->pPrev = pLast; //connect newLink to old last
            pLast->pNext = pNewLink;
            pLast = pLast->pNext;
            return;
        } else {
            Link *pNewLink = new Link(newData); //make new Link
            Link *CurrentLink = pFirst;
            while (CurrentLink != pLast) {
                if (CurrentLink->data > newData) {
                    pNewLink->pNext = CurrentLink->pNext;
                    pNewLink->pPrev = CurrentLink;
                    CurrentLink->pNext->pPrev = pNewLink;
                    CurrentLink->pNext = pNewLink;
                    break;
                }
            }

        }
    }

    Link *find(int key)                 //find link given key
    {                                   //assume non-empty list
        Link *pCurrent = pFirst;        //start at 'first'
        while (pCurrent->data != key)  //while no match
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
        pFirst->pPrev= NULL; //remove prev pointer from new first link
        delete pTemp;   //delete old first
    }

    void removeLast() //delete last link
    {                   //assumes list is not empty
        Link *pTemp = pLast; //save last link
        pLast = pLast->pPrev; //unlink it: last --> old last
        pLast->pNext = NULL; // remove next pointer from new last link]
        delete pTemp;   //delete old last
    }

    bool removeValue(int key)            //remove link with given key
    {                               //assumes non-empty list
        Link *pCurrent = pFirst;
        Link *pPrevious = pFirst;
        while (pCurrent->data != key)  //search for link
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

            else if (pCurrent == pLast) //if last link
        {
            pLast = pLast->pPrev;
            pPrevious->pNext = pCurrent->pNext;
        }
        else
            pPrevious->pNext = pCurrent->pNext;

        delete pCurrent;
        return true;
    }

    void displayList()
    {
        cout << "List (first-->last): " << endl;
        Link *pCurrent = pFirst; //start at beginning of list
        while (pCurrent != NULL) //until end of list
        {
            pCurrent->displayLink(); //show the link
            pCurrent = pCurrent->pNext; //move to next link
        }
        cout << endl;
    }

    void displayListBackward()
    {
        cout << "List (last-->first): " << endl;
        Link *pCurrent = pLast; //start at beginning of list
        while (pCurrent != NULL) //until end of list
        {
            pCurrent->displayLink(); //show the link
            pCurrent = pCurrent->pPrev; //move to next link
        }
        cout << endl;
    }
};

int main() {
    DoubleEndedList theList;                       //make new list
    theList.insertLink(22); //insert 4 items
    theList.insertLink(12);
    theList.insertLink(33);
    theList.insertLink(5);
    theList.insertLink(44);

    theList.displayList();                  //show the list
    cout << "Display list backward: " << endl;
    theList.displayListBackward();          //show it backwards

    int findKey = 22;
    Link *pFind = theList.find(findKey);
    if (pFind)
        cout << "Found link with key: " << pFind->data << endl;
    else
        cout << "Can't find link with key " << findKey << endl;

    if (theList.removeValue(findKey))
        cout <<"Deleted " << findKey << " from the list." << endl;
    else
        cout << "Did not delete " << findKey << " from the list." << endl;

    cout << "Link list after deletion: " << endl;
    theList.displayList();

    theList.displayFirst();
    theList.displayLast();
    cout << endl;

    cout << "Remove first link: " << endl;
    theList.removeFirst();
    theList.displayList();

    cout << "Remove last link: " << endl;
    theList.removeLast();
    theList.displayList();

    return 0;
}
/*
/Users/cody/Desktop/fall19/data-structures/p9/cmake-build-debug/p9
        List (first-->last):
{   5	:	           0x0	:		0x7f901f402a00	:	0x7f901f4029c0}
{  12	:	0x7f901f402a00	:		0x7f901f4029c0	:	0x7f901f400620}
{  22	:	0x7f901f4029c0	:		0x7f901f400620	:	0x7f901f4029e0}
{  33	:	0x7f901f400620	:		0x7f901f4029e0	:	0x7f901f402a20}
{  44	:	0x7f901f4029e0	:		0x7f901f402a20	:	           0x0}

Display list backward:
List (last-->first):
{  44	:	0x7f901f4029e0	:		0x7f901f402a20	:	           0x0}
{  33	:	0x7f901f400620	:		0x7f901f4029e0	:	0x7f901f402a20}
{  22	:	0x7f901f4029c0	:		0x7f901f400620	:	0x7f901f4029e0}
{  12	:	0x7f901f402a00	:		0x7f901f4029c0	:	0x7f901f400620}
{   5	:	           0x0	:		0x7f901f402a00	:	0x7f901f4029c0}

Found link with key: 22
Deleted 22 from the list.
Link list after deletion:
List (first-->last):
{   5	:	           0x0	:		0x7f901f402a00	:	0x7f901f4029c0}
{  12	:	0x7f901f402a00	:		0x7f901f4029c0	:	0x7f901f4029e0}
{  33	:	0x7f901f400620	:		0x7f901f4029e0	:	0x7f901f402a20}
{  44	:	0x7f901f4029e0	:		0x7f901f402a20	:	           0x0}

First: {   5	:	           0x0	:		0x7f901f402a00	:	0x7f901f4029c0}
Last: {  44	:	0x7f901f4029e0	:		0x7f901f402a20	:	           0x0}

Remove first link:
List (first-->last):
{  12	:	           0x0	:		0x7f901f4029c0	:	0x7f901f4029e0}
{  33	:	0x7f901f400620	:		0x7f901f4029e0	:	0x7f901f402a20}
{  44	:	0x7f901f4029e0	:		0x7f901f402a20	:	           0x0}

Remove last link:
List (first-->last):
{  12	:	           0x0	:		0x7f901f4029c0	:	0x7f901f4029e0}
{  33	:	0x7f901f400620	:		0x7f901f4029e0	:	           0x0}


Process finished with exit code 0
*/