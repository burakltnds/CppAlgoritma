#include <iostream>
using namespace std;

const int T = 3; // Minimum derece (2T-1 en fazla anahtar)

class BTreeNode {
public:
    int keys[2*T - 1];
    BTreeNode* children[2*T];
    int keyCount;
    bool leaf;

    BTreeNode(bool leaf);
    void traverse();
    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
};

class BTree {
    BTreeNode* root;
public:
    BTree() { root = nullptr; }
    void traverse() {
        if (root != nullptr) root->traverse();
    }
    void insert(int key);
};

BTreeNode::BTreeNode(bool leaf) {
    this->leaf = leaf;
    keyCount = 0;
    for (int i = 0; i < 2*T; i++) children[i] = nullptr;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keyCount; i++) {
        if (!leaf) children[i]->traverse();
        cout << keys[i] << " ";
    }
    if (!leaf) children[i]->traverse();
}

void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode(true);
        root->keys[0] = key;
        root->keyCount = 1;
    } else {
        if (root->keyCount == 2*T - 1) {
            BTreeNode* s = new BTreeNode(false);
            s->children[0] = root;
            s->splitChild(0, root);
            int i = (s->keys[0] < key) ? 1 : 0;
            s->children[i]->insertNonFull(key);
            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}

void BTreeNode::insertNonFull(int key) {
    int i = keyCount - 1;
    if (leaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = key;
        keyCount++;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;
        if (children[i+1]->keyCount == 2*T - 1) {
            splitChild(i+1, children[i+1]);
            if (keys[i+1] < key) i++;
        }
        children[i+1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->leaf);
    z->keyCount = T - 1;

    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j + T];

    if (!y->leaf)
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j + T];

    y->keyCount = T - 1;

    for (int j = keyCount; j >= i+1; j--)
        children[j+1] = children[j];

    children[i+1] = z;

    for (int j = keyCount - 1; j >= i; j--)
        keys[j+1] = keys[j];

    keys[i] = y->keys[T - 1];
    keyCount++;
}

int main() {
    BTree t;
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "B Ağacı Gezintisi: ";
    t.traverse();
    cout << endl;
    return 0;
}
