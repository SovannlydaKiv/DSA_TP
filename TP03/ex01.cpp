#include <iostream>
using namespace std;

int main() {
    int n1 = 7, n2 = 3, n3 = 15;
    int *p1 = &n1, *p2 = &n2, *p3 = &n3;

    cout << "n1: address = " << p1 << ", value = " << *p1 << endl;
    cout << "n2: address = " << p2 << ", value = " << *p2 << endl;
    cout << "n3: address = " << p3 << ", value = " << *p3 << endl;

    *p3 = *p1 + *p2;
    cout << "After update, n3 = " << n3 << endl;  
    return 0;
}