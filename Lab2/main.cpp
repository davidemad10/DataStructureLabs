#include <iostream>
using namespace std;

// Stack using Array
class StackArray {
    int top;
    int capacity;
    int* arr;

public:
    StackArray(int size) {
        top = -1;
        capacity = size;
        arr = new int[size];
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
        }
        top++;
        arr[top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        }
        --top;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
        }
        for (int i = top; i >= 0; --i)
            cout << arr[i] << " ";
            cout << endl;
    }

    ~StackArray() { delete[] arr; }
};

// Stack using Linked List
class StackLinkedList {
    struct Node {
        int data;
        Node* next;
    };

    Node* top;

public:
    StackLinkedList() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node{value, top};
        top = newNode;
    }

    void pop() {
        if (!top) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (!top) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~StackLinkedList() {
        while (top)
            pop();
    }
};

// Queue using Array
class QueueArray {
    int front, rear, capacity;
    int* arr;

public:
    QueueArray(int size) : front(-1), rear(-1), capacity(size) {
        arr = new int[size];
    }

    void enQueue(int value) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    void deQueue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        ++front;
    }

    int getFront() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (rear == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~QueueArray() { delete[] arr; }
};

// Queue using Linked List
class QueueLinkedList {
    struct Node {
        int data;
        Node* next;
    };

    Node *front, *rear;

public:
    QueueLinkedList() : front(nullptr), rear(nullptr) {}

    void enQueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void deQueue() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    int getFront() {
        if (!front) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (!rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~QueueLinkedList() {
        while (front)
            deQueue();
    }
};

int main() {
    // Test Stack using Array
    StackArray stackArr(5);
    stackArr.push(10);
    stackArr.push(20);
    stackArr.display();
    stackArr.pop();
    stackArr.display();

    // Test Stack using Linked List
    StackLinkedList stackLL;
    stackLL.push(30);
    stackLL.push(40);
    stackLL.display();
    stackLL.pop();
    stackLL.display();

    // Test Queue using Array
    QueueArray queueArr(5);
    queueArr.enQueue(50);
    queueArr.enQueue(60);
    queueArr.display();
    queueArr.deQueue();
    queueArr.display();

    // Test Queue using Linked List
    QueueLinkedList queueLL;
    queueLL.enQueue(70);
    queueLL.enQueue(80);
    queueLL.display();
    queueLL.deQueue();
    queueLL.display();

    return 0;
}
