#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* sol;
    Node* sag;
};

struct Stack {
    Node* treeNode;
    Stack* next;
};

void push(Stack*& s, Node* treeNode) {
    Stack* newStack = new Stack;
    newStack->treeNode = treeNode;
    newStack->next = s;
    s = newStack;
}

Node* pop(Stack*& s) {
    if (s == nullptr) return nullptr;
    Stack* temp = s;
    Node* result = temp->treeNode;
    s = temp->next;
    delete temp;
    return result;
}

bool isEmpty(Stack* s) {
    return s == nullptr;
}


Node* ekle(Node* agac, int x) {
    if (agac == nullptr) {
        Node* root = new Node;
        root->data = x;
        root->sol = nullptr;
        root->sag = nullptr;
        return root;
    }
    if (x < agac->data) {
        agac->sol = ekle(agac->sol, x);
    }
    else {
        agac->sag = ekle(agac->sag, x);
    }
    return agac;
}


void preOrderTraversal(Node* root) {
    if (root == nullptr) return;

    Stack* stack = nullptr;
    push(stack, root);

    while (!isEmpty(stack)) {
        Node* current = pop(stack);
        cout << current->data << " ";

        if (current->sag) push(stack, current->sag);
        if (current->sol) push(stack, current->sol);
    }
}

void inOrderTraversal(Node* root) {
    Stack* stack = nullptr;
    Node* current = root;

    while (!isEmpty(stack) || current != nullptr) {
        while (current != nullptr) {
            push(stack, current);
            current = current->sol;
        }

        current = pop(stack);
        cout << current->data << " ";
        current = current->sag;
    }
}

void postOrderTraversal(Node* root) {
    if (root == nullptr) return;

    Stack* stack1 = nullptr;
    Stack* stack2 = nullptr;

    push(stack1, root);

    while (!isEmpty(stack1)) {
        Node* current = pop(stack1);
        push(stack2, current);

        if (current->sol) push(stack1, current->sol);
        if (current->sag) push(stack1, current->sag);
    }

    while (!isEmpty(stack2)) {
        Node* current = pop(stack2);
        cout << current->data << " ";
    }
}

int main() {
    Node* agac = nullptr;
    agac = ekle(agac, 5);
    agac = ekle(agac, 2);
    agac = ekle(agac, 1);
    agac = ekle(agac, 8);
    agac = ekle(agac, 7);
    agac = ekle(agac, 11);

    cout << "Pre-order Traversal (Oncelikli Gecis):" << endl;
    preOrderTraversal(agac);

    cout << "\n\nIn-order Traversal (Sirali Gecis):" << endl;
    inOrderTraversal(agac);

    cout << "\n\nPost-order Traversal (Sonraki Gecis):" << endl;
    postOrderTraversal(agac);

    return 0;
}
