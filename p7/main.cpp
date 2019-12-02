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

    void removeFirst() //delete first link
    {

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}