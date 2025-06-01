#include <iostream>
using namespace std;

#define MAX_SIZE 100

class MinHeap {
private:
    int heap[MAX_SIZE];
    int size;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left, right, smallest;

        while (true) {
            left = 2 * index + 1;
            right = 2 * index + 2;
            smallest = index;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == index) break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    MinHeap() { size = 0; }

    void insert(int value) {
        if (size == MAX_SIZE) {
            cout << "Heap dolu!\n";
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    void removeMin() {
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
    MinHeap h;
    h.insert(40);
    h.insert(20);
    h.insert(30);
    h.insert(10);
    h.display();

    h.removeMin();
    h.display();

    return 0;
}
