#include <iostream>
#include <string>
using namespace std;

struct Element {
    string name;
    Element* next;
};

struct List {
    Element* head;
};

void createList(List* L) {
    L->head = nullptr;
}

void addPerson(List* L, string personName) {
    Element* newNode = new Element();
    newNode->name = personName;
    newNode->next = L->head;
    L->head = newNode;
}

void display(List* L) {
    Element* current = L->head;
    while (current != nullptr) {
        cout << current->name << endl;
        current = current->next;
    }
}

int main() {
    List L;
    createList(&L);

    addPerson(&L, "Inthera");
    addPerson(&L, "Hong");
    addPerson(&L, "Kimter");
    addPerson(&L, "Sathya");
    addPerson(&L, "Naco");
    addPerson(&L, "Nika");
    addPerson(&L, "Caro");
    addPerson(&L, "Kolboth");
    addPerson(&L, "Phengroth");
    addPerson(&L, "Vanheng");

    cout << "Person list:" << endl;
    display(&L);

    return 0;
}