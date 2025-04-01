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
// Library System
// This is Destaw's contribution 
class Library {
private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int bookCount = 0;
    Member* membersHead = nullptr;

    // Helper function to convert string to lowercase
    string toLower(const string& str) const {
        string lowerStr = str;
        for (char& c : lowerStr) {
            if (c >= 'A' && c <= 'Z') {
                c += 32; // Convert to lowercase
            }
        }
        return lowerStr;
    }

public:
    // Add a book
    void addBook(int id, const string& title, const string& author, const string& genre) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = {id, title, author, genre, false};
            cout << "Book added successfully!\n";
        } else {
            cout << "Library is full!\n";
        }
    }

    // Search book by title (case-insensitive)
    void searchBook(const string& title) const {
        string lowerTitle = toLower(title);

        for (int i = 0; i < bookCount; i++) {
            string lowerBookTitle = toLower(books[i].title);

            if (lowerBookTitle == lowerTitle) {
                books[i].display();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Update book details
    void updateBook(int id, const string& newTitle, const string& newAuthor, const string& newGenre) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                books[i] = {id, newTitle, newAuthor, newGenre, books[i].isIssued};
                cout << "Book updated successfully!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Delete book
    void deleteBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                books[i] = books[--bookCount]; // Replace with last book
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }
