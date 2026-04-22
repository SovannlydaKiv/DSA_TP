#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int year;
    string program;
    Student* next;
};

struct ListStudent {
    Student* head;
    Student* tail;
    Student* pointer;
};

ListStudent* createEmptyList() {
    ListStudent* ls = new ListStudent();
    ls->head = nullptr;
    ls->tail = nullptr;
    ls->pointer = nullptr;
    return ls;
}

void add(Student s, ListStudent* ls) {
    Student* newNode = new Student();
    newNode->id = s.id;
    newNode->name = s.name;
    newNode->year = s.year;
    newNode->program = s.program;
    newNode->next = nullptr;

    if (ls->head == nullptr) {
        ls->head = newNode;
        ls->tail = newNode;
    } else {
        ls->tail->next = newNode;
        ls->tail = newNode;
    }
}

void displayAll(ListStudent* ls) {
    if (ls->head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Student* current = ls->head;
    cout << "\n--- Student List ---" << endl;
    while (current != nullptr) {
        cout << "ID: " << current->id<< " , Name: " << current->name<< " , Year: " << current->year<< " , Program: " << current->program << endl;
        current = current->next;
    }
    cout << "--------------------" << endl;
}

int main() {
    ListStudent* studentList = createEmptyList();

    Student s1 = {1234, "lyda", 1, "Software Engineering",nullptr};
    Student s2 = {2468, "lily", 2, "AI Technology", nullptr};
    Student s3 = {1357, "alice", 4, "Computer Science", nullptr};
    Student s4 = {9753, "john", 1, "Software Engineering", nullptr};
    Student s5 = {8642, "bob", 3, "Data Science", nullptr};

    add(s1, studentList);
    add(s2, studentList);
    add(s3, studentList);
    add(s4, studentList);
    add(s5, studentList);

    cout << "[After adding 5 students]";
    displayAll(studentList);

    Student s6 = {6767, "anastasia", 4, "Information Technology", nullptr};
    Student s7 = {2020, "oliver", 1, "Computer Science", nullptr};

    add(s6, studentList);
    add(s7, studentList);

    cout << "\n[After adding 2 more students]";
    displayAll(studentList);

    return 0;
}