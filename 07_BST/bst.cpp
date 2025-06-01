#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* add(Node* tree, int x) {
        if (tree == nullptr) {
            return new Node(x);
        }
        if (x < tree->data)
            tree->left = add(tree->left, x);
        else
            tree->right = add(tree->right, x);
        return tree;
    }

    void inorder(Node* tree) {
        if (tree == nullptr) return;
        inorder(tree->left);
        cout << "Agac Elemanlari: " << tree->data << endl;
        inorder(tree->right);
    }

    int minValue(Node* tree) {
        while (tree->left != nullptr)
            tree = tree->left;
        return tree->data;
    }

    int maxValue(Node* tree) {
        while (tree->right != nullptr)
            tree = tree->right;
        return tree->data;
    }

    Node* remove(Node* tree, int x) {
        if (tree == nullptr)
            return nullptr;

        if (x < tree->data)
            tree->left = remove(tree->left, x);
        else if (x > tree->data)
            tree->right = remove(tree->right, x);
        else {
            if (tree->left == nullptr && tree->right == nullptr) {
                delete tree;
                return nullptr;
            }
            else if (tree->left == nullptr) {
                Node* temp = tree->right;
                delete tree;
                return temp;
            }
            else if (tree->right == nullptr) {
                Node* temp = tree->left;
                delete tree;
                return temp;
            }
            else {
                int minVal = minValue(tree->right);
                tree->data = minVal;
                tree->right = remove(tree->right, minVal);
            }
        }
        return tree;
    }

public:
    BST() {
        root = nullptr;
    }

    void ekle(int x) {
        root = add(root, x);
    }

    void sil(int x) {
        root = remove(root, x);
    }

    void dolas() {
        inorder(root);
    }

    int minDeger() {
        return minValue(root);
    }

    int maxDeger() {
        return maxValue(root);
    }
};

int main() {
    BST agac;

    agac.ekle(14);
    agac.ekle(10);
    agac.ekle(6);
    agac.ekle(5);
    agac.ekle(2);
    agac.ekle(1);
    agac.ekle(8);
    agac.ekle(7);
    agac.ekle(11);

    cout << "Agac dolasim:" << endl;
    agac.dolas();

    cout << "\n\n5 elemanini sil\n";
    agac.sil(5);

    cout << "Agac dolasim:" << endl;
    agac.dolas();

    cout << "\nMin Deger: " << agac.minDeger() << endl;
    cout << "Max Deger: " << agac.maxDeger() << endl;

    return 0;
}
