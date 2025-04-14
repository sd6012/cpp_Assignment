#include <iostream>
using namespace std;

class Queue {
public:
    int arr[6];
    int front;
    int back;
    int capacity;

    Queue(int size = 6) : capacity(size), front(0), back(0) {}

    void enqueue(int value) {
        if (back == capacity) {
            cout << "Queue Overflow!" << endl;
        } else {
            arr[back++] = value;
        }
    }

    int dequeue() {
        if (front == back) {
            cout << "Queue Underflow!" << endl;
            return -1;
        } else {
            return arr[front++];
        }
    }

    void reverseFirstK(int K) {
        if (K <= 0 || K > back - front) {
            cout << "Invalid K!" << endl;
            return;
        }

        for (int i = 0; i < K / 2; i++) {
            int temp = arr[front + i];
            arr[front + i] = arr[front + K - i - 1];
            arr[front + K - i - 1] = temp;
        }
    }

    void interleave() {
        int n = back - front;
        if (n < 2) {
            cout << "Not enough elements to interleave!" << endl;
            return;
        }

        int mid = front + n / 2;
        int temp[6];

        int i = front, j = mid, k = 0;
        while (i < mid && j < back) {
            temp[k++] = arr[i++];
            temp[k++] = arr[j++];
        }

        while (i < mid) {
            temp[k++] = arr[i++];
        }

        while (j < back) {
            temp[k++] = arr[j++];
        }

        for (int i = 0; i < n; i++) {
            arr[front + i] = temp[i];
        }
    }

    void printQueue() {
        if (front == back) {
            cout << "Queue is empty!" << endl;
        } else {
            for (int i = front; i < back; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);

    cout << "\nQueue after enqueue operations: ";
    q.printQueue();

    q.reverseFirstK(3);
    cout << "\nQueue after reversing first 3 elements: ";
    q.printQueue();

    q.interleave();
    cout << "\nQueue after interleaving halves: ";
    q.printQueue();

    cout << "\nDequeued: " << q.dequeue() << endl;
    cout << "\nQueue after dequeue operation: ";
    q.printQueue();

    q.enqueue(30);
    cout << "\nQueue after attempting to enqueue 30: ";
    q.printQueue();

    return 0;
}
