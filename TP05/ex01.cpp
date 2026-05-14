#include <iostream>
using namespace std;

struct Element {
    char data;
    Element* next;
};

struct List {
    Element* head;
    Element* tail;
};

void createList(List* L) {
    L->head = nullptr;
    L->tail = nullptr;
}

void addLetter(List* L, char c) {
    Element* newNode = new Element();
    newNode->data = c;
    newNode->next = nullptr;

    if (L->head == nullptr) {
        L->head = newNode;
        L->tail = newNode;
    } else {
        L->tail->next = newNode;
        L->tail = newNode;
    }
}

void display(List* L) {
    Element* current = L->head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    List smallList, capitalList;
    createList(&smallList);
    createList(&capitalList);

    for (char c = 'a'; c <= 'z'; c++) {
        addLetter(&smallList, c);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        addLetter(&capitalList, c);
    }

    cout << "Small letters: ";
    display(&smallList);

    cout << "Capital letters: ";
    display(&capitalList);

    return 0;
}