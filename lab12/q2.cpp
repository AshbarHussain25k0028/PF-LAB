#include <iostream>
#include <string>
using namespace std;

class Student {
    int id;
    string name;
    int grade;
public:
    Student(int i, string n, int g) {
        id = i;
        name = n;
        grade = g;
    }
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s1(101, "Ash", 10);
    s1.display();
    return 0;
}

