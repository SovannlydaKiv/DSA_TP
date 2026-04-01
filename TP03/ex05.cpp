#include <iostream>
using namespace std;

void findMaxMin(int* arr, int *max, int *min) {
    *max = arr[0]; 
    *min = arr[0]; 

    for (int i = 1; i < 7; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

int main() {
    int arr[7];
    cout << "Enter 7 integers: ";
    for (int i = 0; i < 7; i++) cin >> arr[i];

    int maxVal, minVal;
    findMaxMin(arr, &maxVal, &minVal);
    cout << "Max = " << maxVal << ", Min = " << minVal << endl;

    return 0;
}