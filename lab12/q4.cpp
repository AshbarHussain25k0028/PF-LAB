#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string brand;
    int speed;
    Vehicle(string b, int s) {
        brand = b;
        speed = s;
    }
};

class Car : public Vehicle {
public:
    int numberOfDoors;
    Car(string b, int s, int d) : Vehicle(b, s) {
        numberOfDoors = d;
    }
};

int main() {
    Car c("Toyota", 180, 4);
    cout << c.brand << endl;
    cout << c.speed << endl;
    cout << c.numberOfDoors << endl;
    return 0;
}

