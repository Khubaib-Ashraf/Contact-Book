#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Contact {
    string name;
    string phone;
};

void saveContacts(const vector<Contact>& contacts) {
    ofstream file("contacts.txt");
    for (const auto& contact : contacts) {
        file << contact.name << "," << contact.phone << endl;
    }
}

void loadContacts(vector<Contact>& contacts) {
    ifstream file("contacts.txt");
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(",");
        Contact contact;
        contact.name = line.substr(0, pos);
        contact.phone = line.substr(pos + 1);
        contacts.push_back(contact);
    }
}

int main() {
    vector<Contact> contacts;
    loadContacts(contacts);

    while (true) {
        cout << "1. Add Contact\n2. View Contacts\n3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            Contact contact;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, contact.name);
            cout << "Enter phone: ";
            getline(cin, contact.phone);
            contacts.push_back(contact);
            saveContacts(contacts);
        } else if (choice == 2) {
            for (const auto& contact : contacts) {
                cout << "Name: " << contact.name << ", Phone: " << contact.phone << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
