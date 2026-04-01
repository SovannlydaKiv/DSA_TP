#include <iostream>
using namespace std;

int main() {
    float nums[7];
    cout << "Enter 7 float numbers: ";
    for (int i = 0; i < 7; i++) cin >> nums[i];

    float *ptr = nums;  

    cout << "Numbers: ";
    for (int i = 0; i < 7; i++) {
        cout << *(ptr + i) << " ";  
    }
    cout << endl;

    float sum = 0, product = 1;
    for (int i = 0; i < 7; i++) {
        sum     += *(ptr + i);
        product *= *(ptr + i);
    }
    cout << "Sum = " << sum << endl;
    cout << "Product = " << product << endl;

    return 0;
}