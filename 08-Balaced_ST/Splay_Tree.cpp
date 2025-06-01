#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};


Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}


Node* splay(Node* root, int key) {
    if (!root || root->key == key) return root;

    // Zig-Zig 
    if (key < root->key && root->left && key < root->left->key) {
        root->left->left = splay(root->left->left, key);
        root = rightRotate(root);
    }
    // Zig-Zag 
    else if (key < root->key && root->left && key > root->left->key) {
        root->left->right = splay(root->left->right, key);
        if (root->left->right)
            root->left = leftRotate(root->left);
    }
    // Zag-Zig 
    else if (key > root->key && root->right && key < root->right->key) {
        root->right->left = splay(root->right->left, key);
        if (root->right->left)
            root->right = rightRotate(root->right);
    }
    // Zag-Zag 
    else if (key > root->key && root->right && key > root->right->key) {
        root->right->right = splay(root->right->right, key);
        root = leftRotate(root);
    }

   
    if (key < root->key && root->left)
        return rightRotate(root);
    if (key > root->key && root->right)
        return leftRotate(root);

    return root;
}


Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    root = splay(root, key);

    if (root->key == key) return root; 

    Node* newNode = new Node(key);

    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }
    return newNode;
}


Node* search(Node* root, int key) {
    return splay(root, key);
}

void preOrder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int key : keys)
        root = insert(root, key);

    cout << "Preorder after inserts:\n";
    preOrder(root);

    root = search(root, 25);
    cout << "\n\nAfter searching 25 (splayed to root):\n";
    preOrder(root);

    return 0;
}
