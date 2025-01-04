#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;  
    Node* next;    
    Node(T data):data(data),next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* bas;  
    Node<T>* son;  
public:
    Queue() :bas(nullptr),son(nullptr){}

    void enQueue(T value) {
        Node<T>* yeni = new Node<T>(value);  
        if (!son) { 
            bas = son = yeni;
        }
            son->next = yeni;  
            son = yeni;       
    }   

    void deQueue() {
        if (!bas) {
            cout << "Kuyruk Bos" << endl;
        }
        Node<T>* temp = bas;
        bas = bas->next;    // Front pointer'ı bir sonraki node'a yönlendirilir
        if (!bas) {
            son = nullptr;
        }
        delete temp;
    }
    void print() {
        if (!bas) {
            cout << "Kuyruk Bos" << endl;
        }
        Node<T>* temp = bas;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;  
    q.enQueue(5);
    q.enQueue(3);
    q.enQueue(65);
    q.enQueue(20);
    cout << "Kuyruk:";
    q.print();
    q.deQueue(); 
    cout << "Dequeue Kuyruk:";
    q.print();
    return 0;
}
