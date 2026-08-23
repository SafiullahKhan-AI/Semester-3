#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
    int* quantity;

public:
    Product(string n, int q) {
        name = n;
        quantity = new int(q);
    }

    ~Product() {
        delete quantity;
    }

    Product(const Product& other) {
        name = other.name;
        quantity = new int(*(other.quantity));
    }

    Product& operator=(const Product& other) {
        if (this != &other) {
            delete quantity;
            name = other.name;
            quantity = new int(*(other.quantity));
        }
        return *this;
    }

    void modifyData(string newName, int newQuantity) {
        name = newName;
        *quantity = newQuantity;
    }

    void display(const string& objName) const {
        cout << objName << " =>> Name: " << name << ", Quantity: " << *quantity << "\n";
    }
};

int main() {
    Product p1("Laptop", 50);
    Product p2 = p1;
    Product p3("Mouse", 100);
    p3 = p1;

    cout << "--- Before Modification ---\n";
    p1.display("p1 (Original)");
    p2.display("p2 (Copy Constructor)");
    p3.display("p3 (Assignment)");

    p2.modifyData("Gaming Laptop", 15);
    p3.modifyData("Ultrabook", 5);

    cout << "\n--- After Modifying p2 and p3 ---\n";
    p1.display("p1 (Original)");
    p2.display("p2 (Modified)");
    p3.display("p3 (Modified)");

    return 0;
}