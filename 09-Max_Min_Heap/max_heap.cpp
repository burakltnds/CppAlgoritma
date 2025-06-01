#include <iostream>
using namespace std;

#define MAX_SIZE 100

class MaxHeap {
private:
    int heap[MAX_SIZE];
    int size;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left, right, largest;

        while (true) {
            left = 2 * index + 1;
            right = 2 * index + 2;
            largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    MaxHeap() { size = 0; }

    void insert(int value) {
        if (size == MAX_SIZE) {
            cout << "Heap dolu!\n";
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    void removeMax() {
        if (size == 0) {
            cout << "Heap boş!\n";
            return;
        }
        cout << "Silinen: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(30);
    h.insert(20);
    h.insert(5);
    h.display();

    h.removeMax();
    h.display();

    return 0;
}
