#include <iostream>
using namespace std;

class Employee {
protected:
    int employeeID;
    double salary;
};

class PartTimeEmployee : protected Employee {
public:
    PartTimeEmployee(int id, double sal) {
        employeeID = id;
        salary = sal;
    }
    double calculatePay(int hours) {
        return hours * salary;
    }
    void show() {
        cout << employeeID << endl;
        cout << salary << endl;
    }
};

int main() {
    PartTimeEmployee p(101, 500);
    p.show();
    cout << p.calculatePay(4);
    return 0;
}

