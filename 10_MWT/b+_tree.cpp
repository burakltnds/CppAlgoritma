#include <iostream>
using namespace std;

const int MAX_KEYS = 3;

class BPlusNode {
public:
    bool isLeaf;
    int keys[MAX_KEYS];
    BPlusNode* children[MAX_KEYS + 1];
    BPlusNode* next; 

    int keyCount;

    BPlusNode(bool leaf) {
        isLeaf = leaf;
        keyCount = 0;
        next = nullptr;
        for (int i = 0; i <= MAX_KEYS; i++) children[i] = nullptr;
    }
};

class BPlusTree {
private:
    BPlusNode* root;

    void insertInternal(int key, BPlusNode* node, BPlusNode* child);

    void splitLeaf(BPlusNode* leaf, int key, BPlusNode*& newLeaf, int& newKey);

    void traverseLeaves(BPlusNode* node) {
        while (!node->isLeaf) node = node->children[0];
        while (node) {
            for (int i = 0; i < node->keyCount; i++)
                cout << node->keys[i] << " ";
            node = node->next;
        }
    }

public:
    BPlusTree() { root = new BPlusNode(true); }

    void insert(int key);

    void print() {
        cout << "Yaprak düğümler: ";
        traverseLeaves(root);
        cout << endl;
    }
};

void BPlusTree::insert(int key) {
    BPlusNode* node = root;
    if (node->keyCount == MAX_KEYS) {
        BPlusNode* newRoot = new BPlusNode(false);
        newRoot->children[0] = root;
        insertInternal(key, newRoot, nullptr);
        root = newRoot;
    } else {
        insertInternal(key, node, nullptr);
    }
}

void BPlusTree::insertInternal(int key, BPlusNode* node, BPlusNode* child) {
    if (node->isLeaf) {
        int i = node->keyCount - 1;
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->keyCount++;

        if (node->keyCount > MAX_KEYS) {
            BPlusNode* newLeaf;
            int newKey;
            splitLeaf(node, key, newLeaf, newKey);

            if (node == root) {
                BPlusNode* newRoot = new BPlusNode(false);
                newRoot->keys[0] = newKey;
                newRoot->children[0] = node;
                newRoot->children[1] = newLeaf;
                newRoot->keyCount = 1;
                root = newRoot;
            } else {
                insertInternal(newKey, node, newLeaf);
            }
        }
    } else {
        int i = 0;
        while (i < node->keyCount && key > node->keys[i]) i++;

        insertInternal(key, node->children[i], child);

        if (child != nullptr) {
            for (int j = node->keyCount; j > i; j--) {
                node->keys[j] = node->keys[j - 1];
                node->children[j + 1] = node->children[j];
            }
            node->keys[i] = child->keys[0];
            node->children[i + 1] = child;
            node->keyCount++;
            child = nullptr;
        }

        if (node->keyCount > MAX_KEYS) {
            cout << "(Dikkat: iç düğüm bölünmesi eksik, örnek basitleştirilmiş.)" << endl;
        }
    }
}

void BPlusTree::splitLeaf(BPlusNode* leaf, int key, BPlusNode*& newLeaf, int& newKey) {
    newLeaf = new BPlusNode(true);
    int mid = (MAX_KEYS + 1) / 2;

    for (int i = mid, j = 0; i < MAX_KEYS; i++, j++) {
        newLeaf->keys[j] = leaf->keys[i];
        newLeaf->keyCount++;
    }
    leaf->keyCount = mid;

    newLeaf->next = leaf->next;
    leaf->next = newLeaf;

    newKey = newLeaf->keys[0];
}

int main() {
    BPlusTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    tree.print(); 

    return 0;
}
