#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        prev = NULL;
        next = NULL;
        this->data = data;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    Node* searchData(int data) {
        Node* search = head;
        while (search != NULL) {
            if (search->data == data) {
                return search;
            }
            search = search->next;
        }
        return NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void display() {
        Node* curr = head;
        if (curr == NULL) {
            cout << "No Data in linkedList" << endl;
        } else {
            while (curr != NULL) {
                cout << curr->data << "->";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
    }

    int insertAfter(int data, int afterData) {
        Node* curr = searchData(afterData);
        if (curr == NULL) {
            cout << "Error: " << afterData << " not found in the list." << endl;
            return -1;
        }

        Node* newNode = new Node(data);
        newNode->prev = curr;
        newNode->next = curr->next;

        if (curr->next != NULL) {
            curr->next->prev = newNode;
        } else {
            tail = newNode;
        }

        curr->next = newNode;
        size++;
        return 1;
    }

    int insertBefore(int data, int beforeData) {
        Node* curr = searchData(beforeData);
        if (curr == NULL) {
            cout << "Error: " << beforeData << " not found in the list." << endl;
            return -1;
        }

        Node* newNode = new Node(data);
        newNode->next = curr;
        newNode->prev = curr->prev;

        if (curr->prev != NULL) {
            curr->prev->next = newNode;
        } else {
            head = newNode;
        }

        curr->prev = newNode;
        size++;
        return 1;
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();

    list.insertAfter(25, 20);
    list.display();

    list.insertBefore(5, 10);
    list.display();

    list.insertAfter(35, 30);
    list.display();

    list.insertBefore(2, 5);
    list.display();

    return 0;
}
