#include <iostream>
using namespace std;

class Circle {

private:
    float radius;

public:
    Circle(float r = 0) {
        radius = r;
    }

    float getArea() {
        return 3.14 * radius * radius;
    }

    void getData() {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }

    friend void compareTwoCircles(Circle c1, Circle c2);
};

void compareTwoCircles(Circle c1, Circle c2) {

    float a1 = c1.getArea();
    float a2 = c2.getArea();

    cout << "\nArea of Circle 1: " << a1 << endl;
    cout << "Area of Circle 2: " << a2 << endl;

    if (a1 > a2) {
        cout << "\nCircle 1 has the larger area: " << a1 << endl;
    } else if (a2 > a1) {
        cout << "\nCircle 2 has the larger area: " << a2 << endl;
    } else {
        cout << "\nBoth circles have the same area." << endl;
    }
}

int main() {
    Circle c1, c2;

    cout << "*-* Enter data for Circle 1: *-*" << endl;
    c1.getData();

    cout << "\n*-* Enter data for Circle 2: *-*" << endl;
    c2.getData();

    compareTwoCircles(c1, c2);

    return 0;
}
