#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int x) {
        data = x;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node* n) {
    return (n == nullptr) ? 0 : n->height;
}

int getBalance(Node* n) {
    return (n == nullptr) ? 0 : getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Sol rotasyon (RR)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // Aynı eleman eklenmez

    // Yükseklik güncelle
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Denge kontrol
    int balance = getBalance(root);

    // LL durumu
    if (balance > 1 && key < root->left->data)
        return rotateRight(root);

    // RR durumu
    if (balance < -1 && key > root->right->data)
        return rotateLeft(root);

    // LR durumu
    if (balance > 1 && key > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL durumu
    if (balance < -1 && key < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);  
    root = insert(root, 25);  
    root = insert(root, 50);
    root = insert(root, 5);   

    cout << "AVL agac (Inorder dolasimi): ";
    inorder(root);
    cout << endl;

    return 0;
}
