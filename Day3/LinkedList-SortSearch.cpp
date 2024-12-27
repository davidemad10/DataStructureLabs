#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T data) {
        prev = NULL;
        next = NULL;
        this->data = data;
    }
};

template <class T>
class LinkedList {
    void swapNodes(Node<T> *node1, Node<T> *node2){
        
        if (node1 == node2) {
            return;
        }

        Node<T>* prev1 = node1->prev;
        Node<T>* next2 = node2->next;

        if (prev1) prev1 -> next = node2;
        if (next2) next2 -> prev = node1;

        node1 -> next = next2;
        node1 -> prev = node2;

        node2 -> next = node1;
        node2 -> prev = prev1;
        
        if (node1 == head) head = node2;
        if (node2 == tail) tail = node1;

    }

public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
        //cout<<"Test"<<endl;
    }
    int binarySearch(T target){
        int mid,start = 0,end = size-1 ;
        Node<T>* search = head;
        int counter = 0;
        do {
            mid = ((end - start) / 2) + start;
            while (counter != mid ){
                if (counter < mid){
                    counter++;
                    search = search -> next ;
                }else{
                    counter--;
                    search = search -> prev;
                }
            }
            if (search -> data == target ) return mid;  
            else if (search -> data > target) end = mid - 1;
            else start = mid + 1;
        }while(start<=end);
        return -1;
    }


    LinkedList<T> linearSearch(T data) {
        Node<T>* search = head;
        LinkedList<T> result;
        int counter = 0;
        while (search != NULL) {
            if (search->data == data) {
                result.insert(counter);
            }
            search = search->next;
            counter++;
        }
        return result; 
    }

    void insert(T data) {
        Node<T>* newNode = new Node<T>(data);

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
        Node<T>* curr = head;
        if (curr == NULL) {
            cout << "No Data in linkedList" << endl;
        } else {
            while (curr != NULL) {
                cout << curr->data << "->";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    void bubbleSort(){
        bool sort = false;
        Node<T>* node1;
        if (size == 0 or size == 1) return;
        for (int outer = 0; !sort ; outer++){
            node1 = head;
            sort = true;
            for (int inner = 0; inner < size - 1 - outer; inner++){
                if ((node1 -> data) > (node1 -> next -> data)) {
                    swapNodes(node1,node1 -> next);
                    sort = false ;
                }else
                    node1 = node1 -> next;

            }
        }
    }

    ~LinkedList(){
        //cout<<"Dtest"<<endl;
    }


};


int main(){
    LinkedList<int> l1;
    // l1.insert(8); //0
    l1.insert(9); //1
    l1.insert(4); //2
    // l1.insert(1); //3
    // l1.insert(2); //4
    // l1.insert(3); //5
    // LinkedList<int> l2;
    // l2 = l1.linearSearch(1);
    // l2.display();
    l1.bubbleSort();
    l1.display();
    return 0;
}