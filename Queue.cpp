#include <iostream>


struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};


class MyQueue {
private:
    Node* front;
    Node* rear;

public:

    MyQueue() : front(nullptr), rear(nullptr) {}


    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }


    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }


    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }


    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    MyQueue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element of the queue: " << myQueue.getFront() << std::endl;

    myQueue.dequeue();

    std::cout << "Front element after dequeue: " << myQueue.getFront() << std::endl;

    return 0;
}
