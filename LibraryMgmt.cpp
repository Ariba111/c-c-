#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    int bookID;

public:
    Book(string t, string a, int id) : title(t), author(a), bookID(id) {}

    void displayDetails() {
        cout << "Title: " << title << ", Author: " << author << ", Book ID: " << bookID << endl;
    }
};

int main() {
    Book b1("The Alchemist", "Paulo Coelho", 101);
    Book b2("1984", "George Orwell", 102);

    b1.displayDetails();
    b2.displayDetails();

    return 0;
}
