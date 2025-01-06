#include <iostream>
using namespace std;

template <class T>
struct	Node {
	T data;
	Node <T> * sonraki;
	Node(T data):data(data),sonraki(nullptr){}
};

template <class T>                                                                                                                                                        
class LinkedList {
	Node<T>* head;
public:
	LinkedList() :head(nullptr){}
	void bastanEkle(T value) {
		Node<T>* yeni = new Node<T>(value);
		yeni->sonraki = head;
		head = yeni;
	}
	void sondanEkle(T value) {
		if (!head) {
			bastanEkle(value);
		}
		Node<T>* yeni = new Node<T>(value);
		Node<T> *temp = head;
		while (temp->sonraki) {
			temp = temp->sonraki;
		}
		temp->sonraki = yeni;
	}
	void arayaEkle(T value, int index) {
	if(index == 0){
		bastanEkle(value);
	}
	Node<T>* yeni = new Node<T>(value);
	Node<T>* temp = head;
	for (int i = 0; i < index - 1 && temp;i++) {
		temp = temp->sonraki;
	}
	if (!temp) {
		sondanEkle(value);
	}
	yeni->sonraki = temp->sonraki;
	temp->sonraki = yeni;
	}
	void bastanSil() {				
		if (!head) {
			cout << "Liste Bos" << endl;
	}
		Node<T>* temp = head;
		head = head->sonraki;
		delete temp;
	}
	void sondanSil(){
		if (!head) {
			cout << "Liste Bos" << endl;
		}
		Node<T>* temp = head;
		while (temp->sonraki->sonraki) {
			temp = temp->sonraki;
		}
		delete temp->sonraki;
		temp->sonraki = nullptr;
	}
	void listele() {
		if (!head) {
			cout << "Liste Bos" << endl;
		}
		Node<T>* temp = head;
		while (temp) {
			cout << temp->data << "->";
			temp = temp->sonraki;
		}
		cout << "NULL" << endl;
	}
};

template <class T>
class Stack {
	Node<T>* top;
public:
	Stack():top(nullptr){}
	
	void push(T value) {
		Node<T>* yeni = new Node<T>(value);
		yeni->sonraki = top;
		top = yeni;
	}
	void pop() {
		if (!top) {
			cout << "Yigin Bos" << endl;
		}
		Node<T>* temp = top;
		top = top->sonraki;
		delete temp;
	}
	void display() {
		if (!top) {
			cout << "Yigin Bos" << endl;
		}
		Node<T>* temp = top;
		while (temp) {
			cout << temp->data << endl;
			temp = temp->sonraki;
		}
	}
 };
template <class T>                                                                                                                                                               
class Queue {
	Node<T>* bas;
	Node<T>* son;
public:
	Queue():bas(nullptr),son(nullptr){}
	void enQueue(T value) {
		Node <T> *yeni = new Node<T>(value);
		if (!son) {
			bas = son = yeni;
		}
		son->sonraki = yeni;
		son = yeni;
	}
	void deQueue() {
		if (!bas) {
			cout << "Kuyruk Bos" << endl;
			return ;
		}
		Node<T>* temp = bas;
		bas = bas->sonraki;
		if (!bas) {
		son = nullptr;
		}
		delete temp;

	}
	void display() {
		if (!bas) {
			cout << "Kuyruk Bos" << endl;
		}
		Node<T>* temp = bas;
		cout << "BAS->";
		while (temp) {
			cout << temp->data <<"->";
			temp = temp->sonraki;
		}
		cout << "SON" << endl;
	}




};


int main() {
	LinkedList<int> l1;
	Stack<int> s1;
	Queue<int>q1;
	cout << "Linked List:" << endl;
	l1.bastanEkle(5);
	l1.sondanEkle(15);
	l1.arayaEkle(10,1);
	l1.listele();
	cout << "Stack:"<<endl;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.pop();
	s1.display();
	cout << "Queue:" << endl;
	q1.enQueue(100);
	q1.enQueue(200);
	q1.enQueue(300);
	q1.deQueue();
	q1.display();
	return 0;
}
