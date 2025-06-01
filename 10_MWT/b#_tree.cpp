#include <iostream>
using namespace std;

const int MAX_KEYS = 3;

class LeafNode {
public:
    int keys[MAX_KEYS];
    int count;
    LeafNode* next;

    LeafNode() {
        count = 0;
        next = nullptr;
    }

    void insert(int key) {
        int i = count - 1;
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        count++;
    }

    bool isFull() {
        return count == MAX_KEYS;
    }

    void print() {
        for (int i = 0; i < count; i++)
            cout << keys[i] << " ";
    }
};

class BSharpTree {
private:
    LeafNode* head;

public:
    BSharpTree() {
        head = new LeafNode();
    }

    void insert(int key) {
        LeafNode* current = head;

        while (current->isFull()) {
            if (current->next == nullptr)
                current->next = new LeafNode();
            current = current->next;
        }

        current->insert(key);
    }

    void traverse() {
        LeafNode* current = head;
        cout << "B# Ağacı (sadece yapraklar): ";
        while (current != nullptr) {
            current->print();
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    BSharpTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    tree.traverse();

    return 0;
}
