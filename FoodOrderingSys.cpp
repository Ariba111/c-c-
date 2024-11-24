#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Class to represent a menu item
class MenuItem {
public:
    int id;
    string name;
    double price;

    MenuItem(int i, string n, double p) : id(i), name(n), price(p) {}
};

// Class to represent an order
class Order {
    vector<MenuItem> menu;
    vector<int> orderIds;
    double total = 0;

public:
    Order() {
        // Initialize menu with items
        menu.push_back(MenuItem(1, "Burger", 5.99));
        menu.push_back(MenuItem(2, "Pizza", 8.99));
        menu.push_back(MenuItem(3, "Pasta", 7.49));
        menu.push_back(MenuItem(4, "Fries", 2.99));
        menu.push_back(MenuItem(5, "Coke", 1.99));
    }

    void showMenu() {
        cout << "\n--- Menu ---\n";
        cout << left << setw(10) << "ID" << setw(20) << "Name" << "Price ($)" << endl;
        for (const auto& item : menu) {
            cout << left << setw(10) << item.id << setw(20) << item.name << fixed << setprecision(2) << item.price << endl;
        }
    }

    void takeOrder() {
        int choice;
        do {
            cout << "\nEnter the ID of the item you want to order (0 to finish): ";
            cin >> choice;
            if (choice == 0) break;

            bool found = false;
            for (const auto& item : menu) {
                if (item.id == choice) {
                    orderIds.push_back(choice);
                    total += item.price;
                    cout << item.name << " added to your order.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 0);
    }

    void generateBill() {
        cout << "\n--- Bill ---\n";
        cout << left << setw(20) << "Item Name" << "Price ($)" << endl;

        for (const auto& id : orderIds) {
            for (const auto& item : menu) {
                if (item.id == id) {
                    cout << left << setw(20) << item.name << fixed << setprecision(2) << item.price << endl;
                }
            }
        }
        cout << "\nTotal: $" << fixed << setprecision(2) << total << endl;
    }
};

int main() {
    Order order;
    cout << "Welcome to the Food Ordering System!" << endl;

    char proceed;
    do {
        order.showMenu();
        order.takeOrder();

        cout << "\nWould you like to order more items? (y/n): ";
        cin >> proceed;
    } while (proceed == 'y' || proceed == 'Y');

    order.generateBill();
    cout << "\nThank you for using the Food Ordering System! Have a great day!" << endl;
    return 0;
}
