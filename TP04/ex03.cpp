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
    
    ls->head    = NULL;
    ls->tail    = NULL;
    ls->pointer = NULL;

    return ls;
};

void add(Student s, ListStudent* ls) {
    Student* newStu  = new Student();
    newStu->id       = s.id;
    newStu->name     = s.name;
    newStu->year     = s.year;
    newStu->program  = s.program;
    newStu->next     = NULL;

    if (ls->head == NULL) {
        ls->head = newStu;
        ls->tail = newStu;
    } 
    else {
        ls->tail->next = newStu;
        ls->tail       = newStu;
    }
};


int main() {
    ListStudent* myList = createEmptyList();

    Student s1 = {1234, "lyda", 1, "Software Engineering", NULL};
    Student s2 = {2468, "lily", 2, "AI Technology", NULL};
    Student s3 = {1357, "alice", 4, "Computer Science", NULL};
    Student s4 = {9753, "john", 1, "Software Engineering", NULL};
    Student s5 = {8642, "bob", 3, "Data Science", NULL};

    add(s1, myList);
    add(s2, myList);
    add(s3, myList);
    add(s4, myList);
    add(s5, myList);

    return 0;
}