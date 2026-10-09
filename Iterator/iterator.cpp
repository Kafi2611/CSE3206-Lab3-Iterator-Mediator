// Iterator Pattern - RUET Cafeteria Menu
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Iterator interface
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual string next() = 0;
    virtual ~Iterator() {}
};

// Aggregate interface
class Menu {
public:
    virtual Iterator* createIterator() = 0;
    virtual ~Menu() {}
};

// Concrete Iterator 1: walks through an array
class ArrayIterator : public Iterator {
    string* items;
    int size;
    int index = 0;
public:
    ArrayIterator(string* items, int size) : items(items), size(size) {}
    bool hasNext() override { return index < size; }
    string next() override { return items[index++]; }
};

// Concrete Iterator 2: walks through a vector
class VectorIterator : public Iterator {
    vector<string>& items;
    int index = 0;
public:
    VectorIterator(vector<string>& items) : items(items) {}
    bool hasNext() override { return index < (int)items.size(); }
    string next() override { return items[index++]; }
};

// Concrete Aggregate 1: keeps items in an array
class BreakfastMenu : public Menu {
    string items[3] = {"Paratha", "Egg Bhaji", "Tea"};
public:
    Iterator* createIterator() override {
        return new ArrayIterator(items, 3);
    }
};

// Concrete Aggregate 2: keeps items in a vector
class LunchMenu : public Menu {
    vector<string> items = {"Rice", "Chicken Curry", "Dal"};
public:
    Iterator* createIterator() override {
        return new VectorIterator(items);
    }
};

// Client: works with ANY menu, does not know how items are stored
void printMenu(Menu& menu) {
    Iterator* it = menu.createIterator();
    while (it->hasNext()) {
        cout << "  - " << it->next() << endl;
    }
    delete it;
}

int main() {
    BreakfastMenu breakfast;
    LunchMenu lunch;

    cout << "Breakfast Menu:" << endl;
    printMenu(breakfast);

    cout << "Lunch Menu:" << endl;
    printMenu(lunch);

    return 0;
}
