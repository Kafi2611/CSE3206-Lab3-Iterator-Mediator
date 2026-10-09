// Mediator Pattern - Group Chat Room
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User;  // forward declaration

// Mediator interface
class ChatMediator {
public:
    virtual void addUser(User* user) = 0;
    virtual void sendMessage(const string& msg, User* sender) = 0;
    virtual ~ChatMediator() {}
};

// Colleague: a user knows ONLY the mediator, not other users
class User {
    string name;
    ChatMediator* chat;
public:
    User(string name, ChatMediator* chat) : name(name), chat(chat) {}

    string getName() { return name; }

    void send(const string& msg) {
        cout << name << " sends: " << msg << endl;
        chat->sendMessage(msg, this);
    }

    void receive(const string& msg, const string& from) {
        cout << "   " << name << " got from " << from << ": " << msg << endl;
    }
};

// Concrete Mediator: decides who gets the message
class ChatRoom : public ChatMediator {
    vector<User*> users;
public:
    void addUser(User* user) override {
        users.push_back(user);
    }

    void sendMessage(const string& msg, User* sender) override {
        for (User* u : users) {
            if (u != sender) {               // do not send back to the sender
                u->receive(msg, sender->getName());
            }
        }
    }
};

int main() {
    ChatRoom room;

    User kafi("Kafi", &room);
    User sadaf("Sadaf", &room);
    User sakila("Sakila", &room);

    room.addUser(&kafi);
    room.addUser(&sadaf);
    room.addUser(&sakila);

    kafi.send("Lab report is ready!");
    sadaf.send("Great, I will check the code.");

    return 0;
}
