#include <iostream>
#include <string>
using namespace std;

class Printer {
public:
    void printInfo(string name) {
        cout << name << endl;
    }
    void printInfo(string name, int age) {
        cout << name << " " << age << endl;
    }
    void printInfo(string name, int age, string city) {
        cout << name << " " << age << " " << city << endl;
    }
};

int main() {
    Printer p;
    p.printInfo("Ash");
    p.printInfo("Ash", 20);
    p.printInfo("Ash", 20, "Karachi");
    return 0;
}

