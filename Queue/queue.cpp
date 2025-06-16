#include <iostream>
using namespace std;

class MyQueue {
private:
    int maxSize;
    int front;
    int rear;
    int* list;

public:
    MyQueue(int size = 100) {
        maxSize = size;
        list = new int[maxSize];
        front = 0;
        rear = 0;
    }

    ~MyQueue() {
        delete[] list;
    }

    bool isEmpty() const {
        return front == rear;
    }

    bool isFull() const {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "큐가 가득 찼습니다!" << endl;
            return;
        }
        list[rear] = value;
        rear = (rear + 1) % maxSize;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "큐가 비어 있습니다!" << endl;
            return;
        }
        front = (front + 1) % maxSize;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "큐가 비어 있습니다!" << endl;
            return -1;
        }
        return list[front];
    }

    void print() const {
        cout << "[큐 내용] ";
        int i = front;
        while (i != rear) {
            cout << list[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};
