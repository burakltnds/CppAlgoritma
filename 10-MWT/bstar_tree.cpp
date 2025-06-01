#include <iostream>
using namespace std;

const int MAX_KEYS = 4;

class BStarNode {
public:
    int keys[MAX_KEYS + 1]; // +1 taşma için
    BStarNode* children[MAX_KEYS + 2];
    int keyCount;
    bool leaf;

    BStarNode(bool isLeaf) {
        leaf = isLeaf;
        keyCount = 0;
        for (int i = 0; i < MAX_KEYS + 2; i++) children[i] = nullptr;
    }

    void traverse() {
        for (int i = 0; i < keyCount; i++) {
            if (!leaf) children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!leaf) children[keyCount]->traverse();
    }
};

class BStarTree {
private:
    BStarNode* root;

    void insertNonFull(BStarNode* node, int key) {
        int i = node->keyCount - 1;

        if (node->leaf) {
            while (i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->keyCount++;
        } else {
            while (i >= 0 && node->keys[i] > key) i--;

            if (node->children[i + 1]->keyCount == MAX_KEYS) {
                split(node, i + 1);
                if (key > node->keys[i + 1])
                    i++;
            }
            insertNonFull(node->children[i + 1], key);
        }
    }

    void split(BStarNode* parent, int i) {
        BStarNode* y = parent->children[i];
        BStarNode* z = new BStarNode(y->leaf);

        int mid = MAX_KEYS / 2;

        z->keyCount = MAX_KEYS - mid - 1;
        for (int j = 0; j < z->keyCount; j++)
            z->keys[j] = y->keys[j + mid + 1];

        if (!y->leaf)
            for (int j = 0; j <= z->keyCount; j++)
                z->children[j] = y->children[j + mid + 1];

        y->keyCount = mid;

        for (int j = parent->keyCount; j >= i + 1; j--)
            parent->children[j + 1] = parent->children[j];

        parent->children[i + 1] = z;

        for (int j = parent->keyCount - 1; j >= i; j--)
            parent->keys[j + 1] = parent->keys[j];

        parent->keys[i] = y->keys[mid];
        parent->keyCount++;
    }

public:
    BStarTree() {
        root = new BStarNode(true);
    }

    void insert(int key) {
        if (root->keyCount == MAX_KEYS) {
            BStarNode* s = new BStarNode(false);
            s->children[0] = root;
            split(s, 0);
            insertNonFull(s, key);
            root = s;
        } else {
            insertNonFull(root, key);
        }
    }

    void traverse() {
        cout << "B* Ağacı gezintisi: ";
        if (root) root->traverse();
        cout << endl;
    }
};

int main() {
    BStarTree tree;

    int dizi[] = {10, 20, 5, 6, 12, 30, 7, 17, 22, 35, 3};
    for (int x : dizi)
        tree.insert(x);

    tree.traverse();

    return 0;
}
