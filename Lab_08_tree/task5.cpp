
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int n) {
        data = n;
        left = right = NULL;
    }
};

Node* insert(Node* r, int n) {
    if (r == NULL) return new Node(n);
    if (n < r->data) r->left = insert(r->left, n);
    else if (n > r->data) r->right = insert(r->right, n);
    return r;
}

void inorder(Node* r) {
    if (r != NULL) {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}

void preorder(Node* r) {
    if (r != NULL) {
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(Node* r) {
    if (r != NULL) {
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int a[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    cout << "In-order: ";
    inorder(root);
    cout << "\nPre-order: ";
    preorder(root);
    cout << "\nPost-order: ";
    postorder(root);

    return 0;
}

