#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insS(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insE(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insP(int value, int pos) {
        if (pos < 1) {
            cout << "\nInvalid position!" << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; ++i) {
            if (!temp) {
                cout << "\nInvalid position!" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void findNth(int n) {
        Node* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        if (n > length) {
            cout << "\nInvalid position!" << endl;
            return;
        }
        temp = head;
        for (int i = 1; i < length - n + 1; ++i) {
            temp = temp->next;
        }
        cout << "\nNth from end: " << temp->data << endl;
    }

    void revK(int k) {
        if (!head || k <= 1) return;
        Node *current = head, *prevFirst = nullptr, *first = nullptr;
        int count = 0;

        while (current) {
            count++;
            current = current->next;
        }

        current = head;
        while (count >= k) {
            first = current;
            prevFirst = nullptr;
            Node* prev = nullptr;
            Node* next = nullptr;
            for (int i = 0; i < k && current; i++) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            if (!prevFirst) {
                head = prev;
            } else {
                prevFirst->next = prev;
            }
            first->next = current;
            prevFirst = first;
            count -= k;
        }
    }

    void loopD() {
        if (!head || !head->next) return;
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                cout << "\nLoop detected. Removing loop." << endl;
                slow = head;
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = nullptr;
                return;
            }
        }
        cout << "\nNo loop detected." << endl;
    }

    void print() {
        if (!head) {
            cout << "\nList is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insS(12);
    list.insE(37);
    list.insE(99);
    list.insP(45, 2);
    list.insE(83);

    cout << "\nList after insertions: ";
    list.print();

    list.findNth(3);

    list.revK(2);
    cout << "\nList after reversing in groups of 2: ";
    list.print();

    list.loopD();

    return 0;
}
