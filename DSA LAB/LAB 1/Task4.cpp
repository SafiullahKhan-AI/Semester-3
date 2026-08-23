#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;

public:
    MyString(const char* s = "") {
        str = new char[strlen(s) + 1]; 
        strcpy(str, s);
        cout << "Constructor called for String :  " << str << endl;
    }

    ~MyString() {
        cout << "Destructor called for String : " << str << endl;
        delete[] str;
    }

    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        cout << "Copy Constructor: Deep copied at " << (void*)str << "\n";
    }

    MyString& operator=(const MyString& other) {
        cout << "Copy Assignment: Copying data...\n";
        
        if (this != &other) { 
            delete[] str; 

            str = new char[strlen(other.str) + 1]; 
            strcpy(str, other.str);
            cout << "Copy Assignment: Deep copied at " << (void*)str << "\n";
        }
        return *this;
    }

    void modifyChar(int index, char newChar) {
        if (index >= 0 && index < strlen(str)) {
            str[index] = newChar;
        }
    }

    void display() const {
        cout << "[Address: " << (void*)str << "] String: " << str << "\n";
    }
};

int main() {
    MyString str1("Pizza");
    cout << "str1: ";
    str1.display();

    cout << "\n---  Initialization using Copy Constructor ---\n";
    MyString str2 = str1; 
    cout << "str2: ";
    str2.display();

    cout << "\n--- Deep Copy Check ---\n";
    cout << "Modifying str2's first character.\n";
    str2.modifyChar(0, 'W');
    
    cout << "str1: "; 
    str1.display(); 
    cout << "str2: "; 
    str2.display(); 

    cout << "\n--- Copy Assignment Operator ---\n";
    MyString str3("Person");
    cout << "str3 before assignment: ";
    str3.display();
    
    str3 = str1;
    cout << "str3 after assignment: ";
    str3.display();

    cout << "\n---Destructors Called ---\n";
    return 0;
}