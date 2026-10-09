// WITHOUT Mediator Pattern (the problem)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
    string name;
    vector<User*> friends;   // every user must keep every other user
public:
    User(string name) : name(name) {}

    void addFriend(User* u) { friends.push_back(u); }

    void send(const string& msg) {
        cout << name << " sends: " << msg << endl;
        for (User* f : friends)
            f->receive(msg, name);
    }

    void receive(const string& msg, const string& from) {
        cout << "   " << name << " got from " << from << ": " << msg << endl;
    }
};

int main() {
    User kafi("Kafi"), sadaf("Sadaf"), sakila("Sakila");

    // 3 users already need 6 links; 10 users would need 90!
    kafi.addFriend(&sadaf);   kafi.addFriend(&sakila);
    sadaf.addFriend(&kafi);   sadaf.addFriend(&sakila);
    sakila.addFriend(&kafi);  sakila.addFriend(&sadaf);

    kafi.send("Lab report is ready!");
    return 0;
}
