#include <iostream>
using namespace std;

struct NumberNode {
    int data;
    NumberNode* next;
};

struct NumberList {
    NumberNode* head;
    NumberNode* tail;
};

NumberList* createEmptyNumberList() {
    NumberList* nl = new NumberList();
    nl->head = nullptr;
    nl->tail = nullptr;
    return nl;
}

void addNumber(int num, NumberList* nl) {
    NumberNode* newNode = new NumberNode();
    newNode->data = num;
    newNode->next = nullptr;

    if (nl->head == nullptr) {
        nl->head = newNode;
        nl->tail = newNode;
    } else {
        nl->tail->next = newNode;
        nl->tail = newNode;
    }
}

void displayNumbers(NumberList* nl) {
    NumberNode* current = nl->head;
    cout << "\nAll data in the list are: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " ";
        current = current->next;
    }
    cout << "." << endl;
}

int sumNumbers(NumberList* nl) {
    int sum = 0;
    NumberNode* current = nl->head;
    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int main() {
    NumberList* numList = createEmptyNumberList();
    int input;
    int zeroCount = 0;

    while (zeroCount < 2) {
        cout << "Enter a number: ";
        cin >> input;

        if (input == 0) {
            zeroCount++;
            if (zeroCount == 1) {
                cout << "You have entered the number 0 once. Only 1 more left. We will quit the program." << endl;
            } else {
                cout << "You have entered the number 0 twice so far. The program is going to stop now." << endl;
            }
        } else {
            addNumber(input, numList);
        }
    }

    displayNumbers(numList);
    cout << "Summation of all numbers is: " << sumNumbers(numList) << endl;

    return 0;
}