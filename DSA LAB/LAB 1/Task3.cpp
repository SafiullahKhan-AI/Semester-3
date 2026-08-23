#include <iostream>
using namespace std;

class Numbers {
private:
    int size;
    int* data;

public:
    Numbers(int s) {
        size = s;
        data = new int[size];
        cout << "Constructor: Allocated memory at " << data << "\n";
    }
    ~Numbers() {
        cout << "Destructor: Freeing memory at " << data << "\n";
        delete[] data;
    }

    // Copy Constructor (Deep Copy)
    Numbers(const Numbers& other) {
        size = other.size;
        data = new int[size]; 
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        cout << "Copy Constructor: Deep copied to new memory at " << data << "\n";
    }

    //Copy Assignment Operator (Deep Copy)
    Numbers& operator=(const Numbers& other) {
        cout << "Copy Assignment: Copying data...\n";
        

        if (this != &other) { 
            delete[] data; 

            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            cout << "Copy Assignment: Deep copied to new memory at " << data << "\n";
        }
        return *this;
    }

    void setValues(int startVal) {
        for (int i = 0; i < size; ++i) {
            data[i] = startVal + i;
        }
    }

    void modifyValue(int index, int newVal) {
        if (index >= 0 && index < size) {
            data[index] = newVal;
        }
    }

    void display() const {
        cout << "[Address: " << data << "] Values: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    cout << "--- Creating Object 1 ---\n";
    Numbers obj1(5);
    obj1.setValues(10); 
    cout << "obj1: ";
    obj1.display();

    cout << "\n--- Initialization using Copy Constructor ---\n";
    Numbers obj2 = obj1;
    cout << "obj2: ";
    obj2.display();

    cout << "\n--- Deep Copy Check ---\n";
    cout << "Modifying obj2's first value to 999...\n";
    obj2.modifyValue(0, 999);
    
    cout << "obj1: "; 
    obj1.display();
    cout << "obj2: "; 
    obj2.display(); 

    cout << "\n--- Assignment using Copy Assignment Operator ---\n";
    Numbers obj3(3);
    cout << "obj3 before assignment: ";
    obj3.setValues(50);
    obj3.display();
    
    obj3 = obj1; //Copy Assignment Operator
    cout << "obj3 after assignment: ";
    obj3.display();

    cout << "\n--- Destructors Called ---\n";
    return 0;
}

/*
DIFFERENCE:
1. Shallow Copy (Default C++ behavior): Only copies the memory address of the pointer. 
   Both objects point to the same memory block. Modifying one affects the other, and 
   when the destructor runs, it will cause a crash (double-free error) because both 
   objects try to delete the same memory.
   
2. Deep Copy (Implemented in this code): Allocates a brand new block of memory for 
   the new object and copies the actual values over. The objects are completely 
   independent, as seen when modifying obj2, obj1 remains unchanged.
*/