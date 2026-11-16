#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data, height;
    Node *left, *right;

    Node(int d) {
        data = d;
        height = 1;
        left = right = NULL;
    }
};

int height(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

int balance(Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balance(root);

    if (b > 1 && key < root->left->data)
        return rightRotate(root);

    if (b < -1 && key > root->right->data)
        return leftRotate(root);

    if (b > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void display(Node* root) {
    if (root == NULL) return;

    cout << root->data << " (Balance Factor: "
         << balance(root) << ")" << endl;

    display(root->left);
    display(root->right);
}

int main() {
    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++) {
        root = insert(root, tokens[i]);
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\n\nFinal Balanced Tree:\n";
    display(root);

    return 0;
}
