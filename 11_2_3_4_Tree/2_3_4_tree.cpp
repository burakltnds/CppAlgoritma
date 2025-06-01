#include <iostream>
using namespace std;

const int MAX_KEYS = 3;

class Node234 {
public:
    int keys[MAX_KEYS];
    Node234* children[MAX_KEYS + 1];
    int keyCount;
    bool leaf;

    Node234(bool isLeaf) {
        keyCount = 0;
        leaf = isLeaf;
        for (int i = 0; i < MAX_KEYS + 1; i++)
            children[i] = nullptr;
    }

    void traverse() {
        for (int i = 0; i < keyCount; i++) {
            if (!leaf)
                children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!leaf)
            children[keyCount]->traverse();
    }

    bool isFull() { return keyCount == MAX_KEYS; }
};

class Tree234 {
private:
    Node234* root;

    void splitChild(Node234* parent, int index) {
        Node234* y = parent->children[index];
        Node234* z = new Node234(y->leaf);

        z->keys[0] = y->keys[2];
        if (!y->leaf) {
            z->children[0] = y->children[2];
            z->children[1] = y->children[3];
        }
        z->keyCount = 1;
        y->keyCount = 1;

        for (int j = parent->keyCount; j >= index + 1; j--)
            parent->children[j + 1] = parent->children[j];

        parent->children[index + 1] = z;

        for (int j = parent->keyCount - 1; j >= index; j--)
            parent->keys[j + 1] = parent->keys[j];

        parent->keys[index] = y->keys[1];
        parent->keyCount++;
    }

    void insertNonFull(Node234* node, int key) {
        int i = node->keyCount - 1;

        if (node->leaf) {
            while (i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->keyCount++;
        } else {
            while (i >= 0 && node->keys[i] > key)
                i--;
            i++;

            if (node->children[i]->isFull()) {
                splitChild(node, i);
                if (key > node->keys[i]) i++;
            }

            insertNonFull(node->children[i], key);
        }
    }

public:
    Tree234() {
        root = new Node234(true);
    }

    void insert(int key) {
        if (root->isFull()) {
            Node234* s = new Node234(false);
            s->children[0] = root;
            splitChild(s, 0);
            root = s;
        }
        insertNonFull(root, key);
    }

    void traverse() {
        cout << "2-3-4 Ağacı (Sıralı): ";
        if (root != nullptr)
            root->traverse();
        cout << endl;
    }
};

int main() {
    Tree234 tree;

    int dizi[] = {10, 20, 5, 6, 12, 30, 7, 17, 3, 22, 35};
    for (int x : dizi)
        tree.insert(x);

    tree.traverse();

    return 0;
}
