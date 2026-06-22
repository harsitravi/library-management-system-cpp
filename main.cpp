#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Book {
private:
    int id;
    string title;
    bool issued;

public:
    Book(int i, string t) {
        id = i;
        title = t;
        issued = false;
    }

    int getId() {
        return id;
    }

    string getTitle() {
        return title;
    }

    bool isIssued() {
        return issued;
    }

    void issueBook() {
        issued = true;
    }

    void returnBook() {
        issued = false;
    }

    void display() {
        cout << id << " | "
             << title << " | "
             << (issued ? "Issued" : "Available")
             << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title) {
        books.push_back(Book(id, title));
    }

    void showBooks() {
        cout << "\nBooks List\n";
        for(auto &book : books) {
            book.display();
        }
    }

    void issueBook(int id) {
        for(auto &book : books) {
            if(book.getId() == id && !book.isIssued()) {
                book.issueBook();
                cout << "Book Issued Successfully\n";
                return;
            }
        }
        cout << "Book Not Available\n";
    }

    void returnBook(int id) {
        for(auto &book : books) {
            if(book.getId() == id && book.isIssued()) {
                book.returnBook();
                cout << "Book Returned Successfully\n";
                return;
            }
        }
        cout << "Invalid Book ID\n";
    }
};

int main() {

    Library lib;

    lib.addBook(101, "C++ Programming");
    lib.addBook(102, "Data Structures");
    lib.addBook(103, "Operating Systems");

    int choice;

    do {
        cout << "\n====== Library Menu ======\n";
        cout << "1. Show Books\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";

        cin >> choice;

        switch(choice) {

            case 1:
                lib.showBooks();
                break;

            case 2:
            {
                int id;
                cout << "Enter Book ID: ";
                cin >> id;
                lib.issueBook(id);
                break;
            }

            case 3:
            {
                int id;
                cout << "Enter Book ID: ";
                cin >> id;
                lib.returnBook(id);
                break;
            }

            case 4:
                cout << "Thank You\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 4);

    return 0;
}
