#include <iostream>
#include <map>
using namespace std;

class Portfolio {
private:
    map<string, int> stocks;

public:
    void buyStock(string name, int qty) {
        stocks[name] += qty;
        cout << qty << " shares of " << name << " bought.\n";
    }

    void sellStock(string name, int qty) {
        if (stocks[name] >= qty) {
            stocks[name] -= qty;
            cout << qty << " shares of " << name << " sold.\n";

            if (stocks[name] == 0)
                stocks.erase(name);
        } else {
            cout << "Not enough shares to sell!\n";
        }
    }

    void viewPortfolio() {
        cout << "\n--- Portfolio ---\n";
        if (stocks.empty()) {
            cout << "No stocks owned.\n";
            return;
        }

        for (auto stock : stocks) {
            cout << stock.first << " : " << stock.second << " shares\n";
        }
    }
};

int main() {
    Portfolio p;
    int choice, qty;
    string name;

    do {
        cout << "\n1. Buy Stock\n";
        cout << "2. Sell Stock\n";
        cout << "3. View Portfolio\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Stock Name: ";
                cin >> name;
                cout << "Quantity: ";
                cin >> qty;
                p.buyStock(name, qty);
                break;

            case 2:
                cout << "Stock Name: ";
                cin >> name;
                cout << "Quantity: ";
                cin >> qty;
                p.sellStock(name, qty);
                break;

            case 3:
                p.viewPortfolio();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
