#include <iostream>
using namespace std;

int main() {
    int num;
    while (true) {
        cout << "Enter a positive integer (-1 to exit): ";
        cin >> num;

        if (num == -1) {
            cout << "Ending Program"<<endl;
            break;
        }
        if (num <= 0) {
            cout << "Invalid input ,Enter a positive integer!" <<endl;
            continue; 
        }

        cout << "Factors of " << num << " are: ";
        int sum = 0;
        for (int i = 1; i <= num; ++i) {
            if (num % i == 0) {
                cout << i << ", ";
                sum += i;     
            }
        }
        
        cout << "\n\nSum of factors: " << sum << endl;
    }
    return 0;
}