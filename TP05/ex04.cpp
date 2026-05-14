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

void searchByName(ListProduct* L, string targetName) {
    Product* current = L->head;
    bool found = false;
    while (current != nullptr) {
        if (current->name == targetName) {
            cout << "Found -> ID: " << current->productId
                 << " | Name: " << current->name
                 << " | Price: $" << current->price << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "No product found with name: " << targetName << endl;
    }
}

void searchByPrice(ListProduct* L, double p) {
    cout << "Section 1 - Products with price lower than $" << p << ":" << endl;
    Product* current = L->head;
    while (current != nullptr) {
        if (current->price < p) {
            cout << "  ID: " << current->productId
                 << " | Name: " << current->name
                 << " | Price: $" << current->price << endl;
        }
        current = current->next;
    }

    cout << "Section 2 - Products with price more than $" << p << ":" << endl;
    current = L->head;
    while (current != nullptr) {
        if (current->price > p) {
            cout << "  ID: " << current->productId
                 << " | Name: " << current->name
                 << " | Price: $" << current->price << endl;
        }
        current = current->next;
    }
}

void updateByProductId(ListProduct* L, int id, string newName, double newPrice) {
    Product* current = L->head;
    while (current != nullptr) {
        if (current->productId == id) {
            current->name = newName;
            current->price = newPrice;
            cout << "Product ID " << id << " updated successfully." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Product ID " << id << " not found." << endl;
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

    cout << "=== All Products ===" << endl;
    display(L);

    cout << "\n=== Search by Name: Laptop ===" << endl;
    searchByName(L, "Laptop");

    cout << "\n=== Search by Price: $50 ===" << endl;
    searchByPrice(L, 50.0);

    cout << "\n=== Update Product ID 3 ===" << endl;
    updateByProductId(L, 3, "Sharpener", 3.99);

    cout << "\n=== All Products After Update ===" << endl;
    display(L);

    return 0;
}