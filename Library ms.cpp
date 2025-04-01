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


//From Tesfaye Teshale

// Library system
class Library {
private:
    static const int MAX_BOOKS = 1000;
    Book books[MAX_BOOKS];
    int bookCount = 0;
    Member* membersHead = NULL;
    const string BOOKS_FILE = "books.dat";
    const string MEMBERS_FILE = "members.dat";

public:
    Library() {
        loadBooks();
        loadMembers();
    }

    ~Library() {
        saveBooks();
        saveMembers();
        clearMembers();
    }

    void loadBooks() {
        ifstream file(BOOKS_FILE, ios::binary);
        if (!file) return;

        file.read((char*)&bookCount, sizeof(bookCount));
        for (int i = 0; i < bookCount; i++) {
            file.read((char*)&books[i], sizeof(Book));
        }
        file.close();
    }

    void saveBooks() {
        ofstream file(BOOKS_FILE, ios::binary);
        if (!file) {
            cerr << "Error saving books data!\n";
            return;
        }

        file.write((char*)&bookCount, sizeof(bookCount));
        for (int i = 0; i < bookCount; i++) {
            file.write((char*)&books[i], sizeof(Book));
        }
        file.close();
    }

    void loadMembers() {
        ifstream file(MEMBERS_FILE, ios::binary);
        if (!file) return;

        int memberCount;
        file.read((char*)&memberCount, sizeof(memberCount));

        for (int i = 0; i < memberCount; i++) {
            int id, borrowedBooks;
            bool isActive;
            string name;

            file.read((char*)&id, sizeof(id));
            file.read((char*)&borrowedBooks, sizeof(borrowedBooks));
            file.read((char*)&isActive, sizeof(isActive));

            size_t nameSize;
            file.read((char*)&nameSize, sizeof(nameSize));
            name.resize(nameSize);
            file.read(&name[0], nameSize);

            Member* newMember = new Member(id, name);
            newMember->borrowedBooks = borrowedBooks;
            newMember->isActive = isActive;
            newMember->next = membersHead;
            membersHead = newMember;
        }
        file.close();
    }

    void saveMembers() {
        ofstream file(MEMBERS_FILE, ios::binary);
        if (!file) {
            cerr << "Error saving members data!\n";
            return;
        }

        int memberCount = 0;
        Member* temp = membersHead;
        while (temp) {
            memberCount++;
            temp = temp->next;
        }

        file.write((char*)&memberCount, sizeof(memberCount));

        temp = membersHead;
        while (temp) {
            file.write((char*)&temp->id, sizeof(temp->id));
            file.write((char*)&temp->borrowedBooks, sizeof(temp->borrowedBooks));
            file.write((char*)&temp->isActive, sizeof(temp->isActive));

            size_t nameSize = temp->name.size();
            file.write((char*)&nameSize, sizeof(nameSize));
            file.write(temp->name.c_str(), nameSize);

            temp = temp->next;
        }
        file.close();
    }
void clearMembers() {
        while (membersHead) {
            Member* temp = membersHead;
            membersHead = membersHead->next;
            delete temp;
        }
    }


void addBook(int id, string title, string author, string genre) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = {id, title, author, genre, false};
            cout << "Book added successfully!\n";
            saveBooks();
        } else {
            cout << "Library is full!\n";
        }
    }

    void searchBook(string title) {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title) {
                books[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "Book not found!\n";
        }
}

// From Basha Meshabie

    void addMember(int id, string name) {
        Member* newMember = new Member(id, name);
        newMember->next = membersHead;
        membersHead = newMember;
        cout << "Member added successfully!\n";
        saveMembers();
    }

    void searchMember(int id) {
        Member* temp = membersHead;
        while (temp) {
            if (temp->id == id) {
                temp->display();
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found!\n";
    }

    void updateMember(int id, bool status) {
        Member* temp = membersHead;
        while (temp) {
            if (temp->id == id) {
                temp->isActive = status;
                cout << "Member status updated!\n";
                saveMembers();
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found!\n";
    }

    void deleteMember(int id) {
        Member* temp = membersHead;
        Member* prev = NULL;
        while (temp) {
            if (temp->id == id) {
                if (prev) prev->next = temp->next;
                else membersHead = temp->next;
                delete temp;
                cout << "Member deleted successfully!\n";
                saveMembers();
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Member not found!\n";
    }

// From Destaw Demeke

    void issueBook(int bookId, int memberId) {
        Book* book = NULL;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == bookId) {
                book = &books[i];
                break;
            }
        }

        Member* member = membersHead;
        while (member) {
            if (member->id == memberId) break;
            member = member->next;
        }

if (!book==!member) {
            cout << "Invalid book or member!\n";
            return;
        }
        if (book->isIssued) {
            cout << "Book is already issued!\n";
            return;
        }
        if (member->borrowedBooks >= 3) {
            cout << "Member has reached the borrowing limit!\n";
return;
        }
        if (!member->isActive) {
            cout << "Member is inactive and cannot borrow books!\n";
            return;
        }

        book->isIssued = true;
        member->borrowedBooks++;
        cout << "Book issued successfully!\n";
        saveBooks();
        saveMembers();
    }

    void returnBook(int bookId, int memberId) {
        Book* book = NULL;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == bookId) {
                book = &books[i];
                break;
            }
        }

        Member* member = membersHead;
        while (member) {
            if (member->id == memberId) break;
            member = member->next;
        }

        if (!book==!member) {
            cout << "Invalid book or member!\n";
            return;
        }
        if (!book->isIssued) {
            cout << "This book was not issued!\n";
            return;
        }

        book->isIssued = false;
        member->borrowedBooks--;
        cout << "Book returned successfully!\n";
        saveBooks();
        saveMembers();
    }
};

void displayMenu() {
    cout << "\nLibrary Management System Menu:\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Update Book\n";
    cout << "4. Delete Book\n";
    cout << "5. Add Member\n";
    cout << "6. Search Member\n";
    cout << "7. Update Member Status\n";
    cout << "8. Delete Member\n";
    cout << "9. Issue Book\n";
    cout << "10. Return Book\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

//this is from banderaw
int main() {
    Library lib;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string title, author, genre;
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Genre: ";
                getline(cin, genre);
                lib.addBook(id, title, author, genre);
                break;
            }
            case 2: {
                string title;
                cout << "Enter Title to Search: ";
                cin.ignore();
                getline(cin, title);
                lib.searchBook(title);
                break;
            }
            case 3: {
                int id;
                string newTitle, newAuthor, newGenre;
                cout << "Enter Book ID to Update: ";
                cin >> id;
                cout << "Enter New Title: ";
                cin.ignore();
                getline(cin, newTitle);
                cout << "Enter New Author: ";
                getline(cin, newAuthor);
                cout << "Enter New Genre: ";
                getline(cin, newGenre);
                lib.updateBook(id, newTitle, newAuthor, newGenre);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Book ID to Delete: ";
                cin >> id;
                lib.deleteBook(id);
                break;
            }
            case 5: {
                int id;
                string name;
                cout << "Enter Member ID: ";
                cin >> id;
                cout << "Enter Member Name: ";
                cin.ignore();
                getline(cin, name);
                lib.addMember(id, name);
                break;
            }
            case 6: {
                int id;
                cout << "Enter Member ID to Search: ";
                cin >> id;
                lib.searchMember(id);
                break;
}
            case 7: {
                int id;
                bool status;
                cout << "Enter Member ID to Update: ";
                cin >> id;
                cout << "Enter New Status (1 for Active, 0 for Inactive): ";
                cin >> status;
                lib.updateMember(id, status);
                break;
            }
            case 8: {
                int id;
                cout << "Enter Member ID to Delete: ";
                cin >> id;
                lib.deleteMember(id);
                break;
            }
            case 9: {
                int bookId, memberId;
                cout << "Enter Book ID to Issue: ";
                cin >> bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                lib.issueBook(bookId, memberId);
                break;
            }
            case 10: {
                int bookId, memberId;
                cout << "Enter Book ID to Return: ";
                cin >> bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                lib.returnBook(bookId, memberId);
                break;
            }
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}


