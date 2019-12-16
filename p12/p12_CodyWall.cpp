//P12: Hash Table
//Cody Wall
//10 December 2019
//Type up and get the Hash table on pages 19 - 22 (Links to an external site.) to work.
//Show your sample test run at the bottom of your code using a multiline comment

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <cstdlib> //for rand nums
#include <ctime> //for rand nums
using namespace std;

///// HASH TABLE //////////////////////////
//hash.cpp
//demonstrates hash table w linear probing
///////////////////////////////////////////
class DataItem
{
public:
    int data;
    DataItem(int newData)
    {
        data = newData;
    } // constructor {}
};

class HashTable
{
private:
    vector<DataItem*> hashArray; // vector holds hash table
    int arraySize;
    DataItem* pNonItem; //for deleted items

public:
    HashTable(int size) //constructor
    {
        arraySize = size;
        hashArray.resize(arraySize); //size the vector
        for (int j = 0; j < arraySize; j++) //init elements
            hashArray[j] = NULL;
        pNonItem = new DataItem(-1); //deleted item key is -1
    }
    // -------------------
    void displayTable()
    {
        cout << "Table: ";
        for (int j = 0; j < arraySize; j++)
        {
            if(hashArray[j] != NULL)
                cout << hashArray[j]->data << " ";
            else
                cout << "** ";
        }
        cout << endl;
    }
    int hashFunc(int key)
    {
        return key % arraySize; //hash function
    }
    //-------------------
    void insert(DataItem* pItem) //insert a DataItem
    //assume table not full
    {
        int key = pItem->data; //extract key
        int hashVal = hashFunc(key); //hash the key
        while(hashArray[hashVal] != NULL &&
              hashArray[hashVal]->data != -1) //until empty cell or -1
        {
            ++hashVal; // go to next cell
            hashVal %= arraySize; //wraparound if necesssary
        }
        hashArray[hashVal] = pItem; //insert item
    } // end insert
    // --------------------------
    DataItem* remove(int key)           //remove a DataItem
    {
        int hashVal = hashFunc(key);     //hash the key
        while(hashArray[hashVal] != NULL) //until empty cell,
        {
            if (hashArray[hashVal]->data == key) //found the key?
            {
                DataItem* pTemp = hashArray[hashVal]; //save item
                hashArray[hashVal] = pNonItem;  //delete item
                return pTemp;
            }
            ++hashVal; // go to next cell
            hashVal %= arraySize; //wraparound if necessary
        }
        return NULL;
    } //end remove()
    //----------------------------
    DataItem* find(int key)     //find item with key
    {
        int hashVal = hashFunc(key);     //hash the key
        while(hashArray[hashVal] != NULL)   //until empty cell
        {
            if (hashArray[hashVal]->data == key) //found the key?
                return hashArray[hashVal];  //yes, return item
                ++hashVal; // got to next cell
                hashVal %= arraySize; //wraparound if necessary
        }
        return NULL;    //cant find item
    }
}; // end class HashTable


int main() {
    DataItem* pDataItem;
    int aKey, size, n, keysPerCell;
    time_t aTime;
    char choice = 'b';
    //get sizes
    cout << "Enter size of hash table: ";
    cin >> size;
    cout << "Enter initial number of items: ";
    cin >> n;
    keysPerCell = 10;

    HashTable theHashTable(size); //make table
    srand (static_cast<unsigned >(time(&aTime))); // make random list of numbers
    for (int j = 0; j < n; j++) //insert data
    {
        aKey = rand() % (keysPerCell*size); // r
        pDataItem = new DataItem(aKey);
        theHashTable.insert(pDataItem);
    }
    while (choice != 'x')   //interact with user
    {
        cout << "Enter first letter of "
        << "show, insert, delete, or find: ";
        char choice;
        cin >> choice;
        switch (choice)
        {
            case 's':
                theHashTable.displayTable();
                break;
            case 'i':
                cout << "Enter key value to insert: ";
                cin >> aKey;
                pDataItem = new DataItem(aKey);
                theHashTable.insert(pDataItem);
                break;
            case 'd':
                cout << "Enter key value to delete: ";
                cin >> aKey;
                theHashTable.remove(aKey);
                break;
            case 'f':
                cout << "Enter key value to find: ";
                cin >> aKey;
                pDataItem = theHashTable.find(aKey);
                if (pDataItem != NULL)
                    cout << "Found " << aKey << endl;
                else
                    cout << "Could not find " << aKey << endl;
                break;
            default:
                cout << "Invalid Entry" << endl;
        }
    }

}

/*
/Users/cody/Desktop/fall19/data-structures/p12/cmake-build-debug/p12
        Enter size of hash table: 12
Enter initial number of items: 8
Enter first letter of show, insert, delete, or find: s
        Table: ** ** 2 51 40 52 15 114 114 26 ** **
Enter first letter of show, insert, delete, or find: f
        Enter key value to find: 4
Could not find 4
Enter first letter of show, insert, delete, or find: f
        Enter key value to find: 40
Found 40
Enter first letter of show, insert, delete, or find: i
        Enter key value to insert: 1
Enter first letter of show, insert, delete, or find: s
        Table: ** 1 2 51 40 52 15 114 114 26 ** **
Enter first letter of show, insert, delete, or find: d
        Enter key value to delete: 15
Enter first letter of show, insert, delete, or find: s
        Table: ** 1 2 51 40 52 -1 114 114 26 ** **
Enter first letter of show, insert, delete, or find:
*/