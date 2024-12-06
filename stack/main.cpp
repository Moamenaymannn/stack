#include <iostream>

using namespace std;

class stack {
private:
    int size;
    int value;
    int *items;

    void resize() {
        int reSize = size * 2;
        int *newAr = new int[reSize];

        for (int i = 0; i < value; i++) {
            newAr[i] = items[i];
        }

        delete[] items;
        items = newAr;
        size = reSize;
    }

public:
    stack(int start = 4) {
        size = start;
        value = 0;
        items = new int[start];
    }

    ~stack() {
        delete[] items;
    }

    void push(int data) {
        if (value == size) {
            resize();
        }
        items[value++] = data;
    }

    int pop() {
        if (value == 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        int temp = items[--value];
        cout << "Data\t" << temp << endl;
        return temp;
    }

    void display() {
        if (value == 0) {
            cout << "Stack is Empty" << endl;
            return;
        }

        for (int i = 0; i < value; i++) {
            cout << "Items:\t" << items[i] << endl;
        }
    }
};

int main() {
    stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.display();

    return 0;
}


