// Cody Wall
// 20 September 2019
// P4: ADT Bag Array Implementation
//=== WRITE and TEST the Functions below:
//    void most_expensive ( ) (shows the most expensive item)
//    void show_reverse ( ) (shows everything in the bag in reverse order of showItems() )
//    void get_frequency (Item item) (show how many times an Item (the name) appears in the bag)
//    bool delete_item (Item item) (delete 1 item (based on the name), shift array elements to the left, return true if successful
//    int get_index_of (Item item) (returns the index of an item (based on the name) )
//    double sum_of_all ( ) (returns the sum of all Items)


#include <iostream>
using namespace std;

class Item
{
private:
    string name;
    double cost;

public:
    Item()
    {
        name = "";
        cost = 0.0;
    }

    Item (string newName, double newCost)
    {
        name = newName;
        cost = newCost;
    }

    void show()
    {
        cout << "- " << name << " $" << cost << endl;
    }

    string get_name() {return name; }
    double get_cost() {return cost; }

    void set_item(string newName, double newCost)
    {
        name = newName;
        cost = newCost;
    }

    void setItem(Item item)
    {
        name = item.get_name();
        cost = item.get_cost();
    }
};

class Bag {
private:
    Item *items;
    int number_items;
    int max;

public:
    Bag(int Max) {
        items = new Item[Max]; // an array of items
        number_items = 0; // index of current item
        max = Max; // size of the bag/ array
    }

    void insert_item(string name, double cost) {
        items[number_items].set_item(name, cost);
        number_items++;
    }

    void insertItem(Item item) {
        items[number_items].setItem(item);
        number_items++;
    }

    int size() { return max; }

    void showItems() {
        for (int i = 0; i < max; i++)
            items[i].show();
    }

    void delete_first() {
        for (int i = 0; i < max; i++)
            items[i] = items[i + 1];
        number_items--;
        max = max - 1;
    }

    bool contains(string name_to_find) {
        for (int i = 0; i < number_items; i++)
            if (name_to_find == items[i].get_name())
                return true;
        return false;
    }

    void sort_by_cost_ascending() //bubble sort
    {
        for (int i = 0; i < number_items - 1; i++)
            for (int j = 0; j < number_items - 1; j++)
                if (items[j].get_cost() > items[j + 1].get_cost())
                    swap(j, j + 1);
    }

    void swap(int index1, int index2) {
        Item temp = items[index1];
        items[index1] = items[index2];
        items[index2] = temp;
    }

    void most_expensive() {
//    (shows the most expensive item)
        int max_price = 0;
        for (int i = 1; i < number_items; i++)
            if (items[i].get_cost() > items[max_price].get_cost())
                max_price = i;
        cout << "The most expensive item is: ";
        cout << "$" << items[max_price].get_cost();
        cout << " and is the " << items[max_price].get_name() << endl;

    }

    void show_reverse() {
//    (shows everything in the bag in reverse order of showItems() )
        for (int i = number_items - 1; i >= 0; i--)
            items[i].show();

    }

    void get_frequency(Item item)
//    (show how many times an Item (the name) appears in the bag)
    {
        int counter = 0;
        for (int i = 0; i < number_items; i++)
            if (items[i].get_name() == item.get_name())
                counter++;

        cout << "The " << item.get_name() << " appears " << counter << " times.";
    }

    bool deleteItem(Item item)
//    (delete item(based on the name), shift array elements to the left, return true if successful
    {
        int itemToDelete;
        for (itemToDelete = 0; itemToDelete < max; itemToDelete++)
            if (items[itemToDelete].get_name() == item.get_name())
                break;
        if (itemToDelete == max)
            return false;

        for (int i = itemToDelete; i < max; i++)
            items[i] = items[i + 1];

        number_items = number_items - 1;
        max = max - 1;
        return true;
    }

    int get_index_of(Item item)
//    (returns the index of an item (based on the name))
    {
        for (int i = 0; i < max; i++)
            if (items[i].get_name() == item.get_name())
                return i;

//                return 10;
    }

        double sum_of_all()
//    (returns the sum of all Items)
        {
            double sum = 0;
            for (int i = 0; i < number_items; i++) {
                sum += items[i].get_cost();
            }
            return sum;
        }

};

int main() {
    cout << "Testing first item..." << endl;
    Item appleItem("Fuji apple", 4.99);
    appleItem.show();
    Item doggyItem("Doggy", 62);

    cout << "Initializing an array with 5 items (max_items) and showing its contents with show()..." << endl;
    int max_items = 5;
    Bag bag(max_items);
    bag.showItems();

    cout << "Inserting dog fur, a brush, and a pony into the bag..." << endl;
    bag.insert_item("Dog fur", 10);
    bag.insert_item("Pony", 27);
    bag.insert_item("Brush", 3);
    bag.showItems();

    cout << "Inserting the apple Item and the dog Item..." << endl;
    bag.insertItem(appleItem);
    bag.insertItem(doggyItem);
    bag.showItems();

    cout << "Find out how many items the bag contains...";
    cout << bag.size() << endl;

    cout << "Delete the first item in the bag..." << endl;
    bag.delete_first();
    bag.showItems();

    cout << "Find out if there is an item called 'Pony'...";
    cout << bag.contains("Pony") << endl;
    if (bag.contains("Pony"))
        cout << "There is an item called Pony!";
    else
        cout << "There is not such an item.";

    cout << endl << "Sort the bag by ascending order..." << endl;
    bag.sort_by_cost_ascending();
    bag.showItems();

    cout << "Swap the first and last items..." << endl;
    bag.swap(0, 3);
    bag.showItems();

    cout << "Show the most expensive item..." << endl;
    bag.most_expensive();

    cout << "Show the bag in reverse..." << endl;
    bag.show_reverse();

    cout << "Check how many times the apple appears..." << endl;
    bag.get_frequency(appleItem);

    cout << endl << "Delete the doggy and show the array..." << endl;
    bag.deleteItem(doggyItem);
    bag.showItems();

    cout <<"The apple is in the index: " << bag.get_index_of(appleItem) << endl;

    cout << "The sum of all the items is..." << bag.sum_of_all();

    return 0;
};


/*
/Users/cody/Desktop/fall19/csis45/p4/cmake-build-debug/p4
Testing first item...
- Fuji apple $4.99
Initializing an array with 5 items (max_items) and showing its contents with show()...
-  $0
-  $0
-  $0
-  $0
-  $0
Inserting dog fur, a brush, and a pony into the bag...
- Dog fur $10
- Pony $27
- Brush $3
-  $0
-  $0
Inserting the apple Item and the dog Item...
- Dog fur $10
- Pony $27
- Brush $3
- Fuji apple $4.99
- Doggy $62
Find out how many items the bag contains...5
Delete the first item in the bag...
- Pony $27
- Brush $3
- Fuji apple $4.99
- Doggy $62
Find out if there is an item called 'Pony'...1
There is an item called Pony!
Sort the bag by ascending order...
- Brush $3
- Fuji apple $4.99
- Pony $27
- Doggy $62
Swap the first and last items...
- Doggy $62
- Fuji apple $4.99
- Pony $27
- Brush $3
Show the most expensive item...
The most expensive item is: $62 and is the Doggy
Show the bag in reverse...
- Brush $3
- Pony $27
- Fuji apple $4.99
- Doggy $62
Check how many times the apple appears...
The Fuji apple appears 1 times.
Delete the doggy and show the array...
- Fuji apple $4.99
- Pony $27
- Brush $3
The apple is in the index: 0
The sum of all the items is...34.99
Process finished with exit code 0
 */