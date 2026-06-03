#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool issued;

public:
    Book(int id, string title, string author)
        : id(id), title(title), author(author), issued(false) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isIssued() const { return issued; }

    void issueBook() { issued = true; }
    void returnBook() { issued = false; }

    void display() const {
        cout << "\nID: " << id
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nStatus: " << (issued ? "Issued" : "Available")
             << "\n----------------------\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.emplace_back(id, title, author);
        cout << "Book Added Successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No Books Available.\n";
            return;
        }

        for (const auto &book : books)
            book.display();
    }

    void searchBook(int id) {
        for (const auto &book : books) {
            if (book.getId() == id) {
                book.display();
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void issueBook(int id) {
        for (auto &book : books) {
            if (book.getId() == id) {
                if (!book.isIssued()) {
                    book.issueBook();
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book Already Issued!\n";
                }
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void returnBook(int id) {
        for (auto &book : books) {
            if (book.getId() == id) {
                if (book.isIssued()) {
                    book.returnBook();
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "Book Was Not Issued!\n";
                }
                return;
            }
        }
        cout << "Book Not Found!\n";
    }
};

int main() {
    Library lib;
    int choice, id;
    string title, author;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            lib.addBook(id, title, author);
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            cout << "Enter Book ID: ";
            cin >> id;
            lib.searchBook(id);
            break;

        case 4:
            cout << "Enter Book ID: ";
            cin >> id;
            lib.issueBook(id);
            break;

        case 5:
            cout << "Enter Book ID: ";
            cin >> id;
            lib.returnBook(id);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
