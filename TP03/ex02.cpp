#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int *p = &n;  
    *p = *p + 7;   

    cout << "After adding 7: n = " << n << endl;
    return 0;
}