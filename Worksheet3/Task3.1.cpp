#include <iostream>
using namespace std;

class Time {
private:
    int h;
    int m;
    int s;

public:
    Time() {
        h = 0;
        m = 0;
        s = 0;
    }

    Time(int hour, int minute, int second) : h(hour), m(minute), s(second) {
        if (h > 24 || m > 60 || s > 60) {
            throw "Invalid time: hour should be <= 24, minute and second should be <= 60";
        }
    }

    Time operator +(Time t) {
        Time temp;
        int total_seconds = s + t.s;
        int newminute = total_seconds / 60;
        temp.s = total_seconds % 60;
        int total_minutes = m + t.m + newminute;
        int newhour = total_minutes / 60;
        temp.m = total_minutes % 60;
        temp.h = h + t.h + newhour;
        if (temp.h >= 24) {
            temp.h = temp.h % 24;
        }
        if (temp.m >= 60) {
            temp.m = temp.m % 60;
        }
        return temp;
    }

    bool operator >(Time t) {
        if (h > t.h) {
            return true;
        } else if (h == t.h && m > t.m) {
            return true;
        } else if (h == t.h && m == t.m && s > t.s) {
            return true;
        }
        return false;
    }

    void display() {
        cout << "\nhour = " << h << endl;
        cout << "\nminute = " << m << endl;
        cout << "\nsecond = " << s << endl;
    }
};

int main() {
    int a, b, c;
    int d, e, f;

    try {
        cout << "Enter first timestamp: ";
        cin >> a >> b >> c;

        cout << "Enter second timestamp: ";
        cin >> d >> e >> f;

        Time t1(a, b, c);
        Time t2(d, e, f);

        Time result = t1 + t2;

        cout << "Resulting timestamp after addition: ";
        result.display();

        if (t1 > t2) {
            cout << "First time is greater than the second time." << endl;
        } else {
            cout << "Second time is greater than or equal to the first time." << endl;
        }

    } catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}
