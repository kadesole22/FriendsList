#include <iostream>

template<typename T>
class Node {
public:
    //This gives each node 2 pointers one at next and one at previous
    T data;
    Node* next;
    Node* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr){}
    };

template<typename T>
class Queue {
private:
    // 2 nodes the Head and Tail node
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    //this will initialize a Queue with the head and tail pointing to null and of size 0 so we know its empty
    Queue() : head(nullptr), tail(nullptr), size(0) {}
    //This is a destruct that will see if its empty if its not it will dequeue the nodes
    //used to save memory when going out of scope
    ~Queue() {
        while (!isEmpty()){
            dequeue();
        }
    }


    //This function will add a new element to the tail of the queue
    void enqueue(const T& data) {
        //Creates a new node
        Node<T>* newNode = new Node<T>(data);
        //Checks if the list is empty if it is, sets the new element as the head and tail
        if(isEmpty()) {
            head = tail = newNode;
        //if its not empty it updates the pointers by having the next pointer of the tail point to the new node
        //Then it changes the previous pointer of the new node to point to the tail.After all of this it will
        //change the tail node to the new node because it will be the new end/tail of the list
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    //This function will remove elements from the queue
    void dequeue() {
        if(isEmpty()) {
            std::cerr << "Queue is Empty Silly!\n";
            return;
        } //Story head in a temp location so we can modify it without harm
        Node<T>* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        } else{
            tail = nullptr;
        }
        delete temp;
        size--;
    }
    //This will compare the size to 0 if the size is 0 it returns true showing
    // it is empty
    bool isEmpty() const {
        return size == 0;
        }
    //This check if the list is empty if its not it will dequeue
    void makeEmpty() {
        while(!isEmpty()){
            dequeue();
        }
    }
    //This will check to see the top element
    T peek() const{
        if(isEmpty()) {
            std::cerr << "Queue is Empty Silly!\n";
            return T();
        }
        return head->data;
    }
    //This will print the entire list
    void print() const {
        Node<T>* current = head;
        std::cout<< "\nFriends List: \n";
        while (current != nullptr){
            std:: cout << current -> data << " \n";
            current = current->next;
        }
        std:: cout << std::endl;
    }
    //This will print the entire list but reversed
    void reversePrint() const {
        Node<T>* current = tail;
        std::cout << "\nFriends List Reversed: \n";
        while (current != nullptr) {
            std::cout << current->data << " \n";
            current = current->prev;
        }
        std::cout << std::endl;
    }

};
