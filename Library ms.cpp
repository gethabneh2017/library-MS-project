//From Tesfaye Seifu
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Book structure for array storage
struct Book {
    int id;
    string title;
    string author;
    string genre;
    bool isIssued = false;

    void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author
             << ", Genre: " << genre << ", Issued: " << (isIssued ? "Yes" : "No") << endl;
    }
};
//this is bashas
class Member {
public:
    int id;
    string name;
    int borrowedBooks = 0;
    bool isActive = true;
    Member* next = nullptr;

    Member(int id, const string& name) : id(id), name(name) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Borrowed: " << borrowedBooks << ", Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};
