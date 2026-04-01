#include <iostream>
using namespace std;

void exchange(float *a, float *b) {
    float temp = *a; 
    *a = *b;         
    *b = temp;        
}

int main() {
    float a = 5.5 , b = 9.9;
    cout << "Before: a = " << a << ", b = " << b << endl;
    exchange(&a, &b);
    cout << "After:  a = " << a << ", b = " << b << endl;

    return 0;
}