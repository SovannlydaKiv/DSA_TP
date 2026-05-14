#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productId;
    string name;
    double price;
    Product* next;
};

struct ListProduct {
    Product* head;
    Product* tail;
};

ListProduct* createEmptyList() {
    ListProduct* L = new ListProduct();
    L->head = nullptr;
    L->tail = nullptr;
    return L;
}
void addProductToBegin(ListProduct* L, int id, string name, double price) {
    Product* newNode = new Product();
    newNode->productId = id;
    newNode->name = name;
    newNode->price = price;
    newNode->next = L->head;
    L->head = newNode;
    if (L->tail == nullptr) {
        L->tail = newNode;
    }
}
void addProductToEnd(ListProduct* L, int id, string name, double price) {
    Product* newNode = new Product();
    newNode->productId = id;
    newNode->name = name;
    newNode->price = price;
    newNode->next = nullptr;

    if (L->head == nullptr) {
        L->head = newNode;
        L->tail = newNode;
    } else {
        L->tail->next = newNode;
        L->tail = newNode;
    }
}
void display(ListProduct* L) {
    Product* current = L->head;
    while (current != nullptr) {
        cout << "ID: " << current->productId
             << " | Name: " << current->name
             << " | Price: $" << current->price << endl;
        current = current->next;
    }
}
void deleteList(ListProduct* L) {
    Product* current = L->head;
    while (current != nullptr) {
        Product* temp = current;
        current = current->next;
        delete temp;
    }
    delete L;
}

int main() {
    ListProduct* L = createEmptyList();
    struct Entry { int id; string name; double price; };
    Entry products[] = {
        {1, "Pen",       2.50},
        {2, "Notebook", 75.00},
        {3, "Eraser",   1.00},
        {4, "Laptop",  999.99},
        {5, "Ruler",   15.00},
        {6, "Backpack", 55.00}
    };
    for (auto& p : products) {
        if (p.price < 50.0) {
            addProductToBegin(L, p.id, p.name, p.price);
        } else {
            addProductToEnd(L, p.id, p.name, p.price);
        }
    }
    cout << "Product list:" << endl;
    display(L);

    deleteList(L);
    return 0;
}