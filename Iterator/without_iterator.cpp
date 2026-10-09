// WITHOUT Iterator Pattern (the problem)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BreakfastMenu {
public:
    string items[3] = {"Paratha", "Egg Bhaji", "Tea"};   // must be public
};

class LunchMenu {
public:
    vector<string> items = {"Rice", "Chicken Curry", "Dal"}; // must be public
};

// The waiter must know HOW each menu stores its items
void printMenus(BreakfastMenu& b, LunchMenu& l) {
    for (int i = 0; i < 3; i++)                  // loop for the array
        cout << "  - " << b.items[i] << endl;
    for (int i = 0; i < (int)l.items.size(); i++) // another loop for the vector
        cout << "  - " << l.items[i] << endl;
    // a new menu type (e.g. linked list) = one more loop here
}

int main() {
    BreakfastMenu b;
    LunchMenu l;
    printMenus(b, l);
    return 0;
}
