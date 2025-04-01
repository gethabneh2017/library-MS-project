//This is From Tesfaye Seifu
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    string author;
    string genre;
    bool isIssued = false;

    void display() {
        cout << "ID: " << id <<endl;
        cout<<"Title: " << title<<endl;
        cout<<"Author: " << author <<endl;
        cout<<"Genre: " << genre <<endl;
        cout<< "Issued: " << (isIssued ? "Yes" : "No") << endl;
    }
};

// Member node (singly linked list)
class Member {
public:
    int id;
    string name;
    int borrowedBooks = 0;
    bool isActive = true;
    Member* next = NULL;

    Member(int idVal, string nameVal) {
        id = idVal;
        name = nameVal;
    }

    void display() {
        cout << "ID: " << id <<endl;
        cout<< "Name: " << name<<endl;
        cout<< "Borrowed: " << borrowedBooks<<endl;
        cout<< "Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};
