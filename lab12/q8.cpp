#include <iostream>
#include <cmath>
using namespace std;

class Area {
public:
    double area(double side) {
        return side * side;
    }
    double area(double length, double width) {
        return length * width;
    }
    double areaCircle(double radius) {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Area a;
    cout << a.area(5) << endl;
    cout << a.area(4, 6) << endl;
    cout << a.areaCircle(3) << endl;
    return 0;
}

