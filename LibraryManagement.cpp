#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void addBook(vector<Book>& lib) {
    Book b;
    cout << "Enter book title: ";
    getline(cin, b.title);
    cout << "Enter author name: ";
    getline(cin, b.author);
    cout << "Enter publication year: ";
    cin >> b.year;
    cin.ignore(); // clear buffer

    lib.push_back(b);
    cout << "Book added successfully!\n";
}

void displayBooks(const vector<Book>& lib) {
    if (lib.empty()) {
        cout << "No books in library.\n";
        return;
    }
    cout << "\n--- Library Books ---\n";
    for (int i = 0; i < lib.size(); i++) {
        cout << i + 1 << ") "
            << lib[i].title << " | "
            << lib[i].author << " | "
            << lib[i].year << "\n";
    }
}

void searchBook(const vector<Book>& lib, const string& name) {
    bool found = false;
    for (auto& b : lib) {
        if (b.title == name) {
            cout << "Found: " << b.title << " by " << b.author
                << " (" << b.year << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Book not found.\n";
    }
}

int main() {
    vector<Book> library;
    int choice;
    string name;

    while (true) {
        cout << "\n=== Library Management ===\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            addBook(library);
        }
        else if (choice == 2) {
            displayBooks(library);
        }
        else if (choice == 3) {
            cout << "Enter Book Name to search: ";
            getline(cin, name);
            searchBook(library, name);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
