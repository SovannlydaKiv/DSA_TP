#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;             
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

