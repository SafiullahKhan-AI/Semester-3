#include <iostream>

using namespace std;
void MinMax(int* arr, int size, int* min, int* max);

int main() {
    int arr[] = {25, 10, 45, 5, 30, 60, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    MinMax(arr, size, &min, &max);

    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    
    cout << "\n\n";
    cout << "Smallest element: " << min << "\n";
    cout << "Largest element: " << max << "\n";

    return 0;
}

void MinMax(int* arr, int size, int* min, int* max) {
    if (size <= 0)
     return; 
    
    *min = *arr;    
    *max = *arr;

    for (int i = 1; i < size; ++i) {
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
        if (*(arr + i) > *max) {
            *max = *(arr + i); 
        }
    }
}