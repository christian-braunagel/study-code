#include <iostream>
#include <string>
#include <iomanip>
using namespace std; // sollte man nicht verwenden

class Article {
public:
    string name;
    double price;
    int stock;
    string* category; // der Pointer macht keinen Sinn, braucht man nicht
    int id;

    Article(string name, double price, int stock, string category, int id) { // in eine Initializer Liste packen
        name = name;   // this key-word fehlt
        price = price; // this key-word fehlt
        stock = stock; // this key-word fehlt
        this->id = id;
        this->category = new string;
        *this->category = category;
    } // kein destructor vorhanden

    void setPrice(double price) {
        price = price; // this key-word fehlt
    }
    // überprüfung fehlt
    void sell(int amount) {
        stock = stock - amount; // this key-word fehlt
    }
    // überprüfung fehlt
    void restock(int amount) {
        this->stock += amount;
    }
    // überprüfung fehlt
    double applyDiscount(double percent) {
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() {
        return price;
    }

    bool isAvailable() { // die abfrage ist: ist true = true; kann ein 1 zeiler sein
        if (stock > 0)
            return true; // geschweifte klammern verw.
        else
            return false; // geschweifte klammern verw.
    }

    void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5); // minus ist falsch
    a.price = -100;
    a.applyDiscount(150); // ist nicht klar wie hoch der discount ist + keine überprüfung

    if (a.isAvailable()) cout << "Article available" << endl;

    a.printInfo();
}