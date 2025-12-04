#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string name;
    Animal(string n) {
        name = n;
    }
    void makeSound() {
        cout << "Some animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void bark() {
        cout << "Dog barking" << endl;
    }
};

int main() {
    Animal a("Generic Animal");
    a.makeSound();

    Dog d("Buddy");
    cout << d.name << endl;
    d.makeSound();
    d.bark();

    return 0;
}

