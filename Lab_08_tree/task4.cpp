
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

Node* minimum(Node* r) {
    while (r->left != NULL) r = r->left;
    return r;
}

Node* deleteNode(Node* r, int n) {
    if (r == NULL) return NULL;

    if (n < r->data)
        r->left = deleteNode(r->left, n);
    else if (n > r->data)
        r->right = deleteNode(r->right, n);
    else {
        if (r->left == NULL) {
            Node* t = r->right;
            delete r;
            return t;
        }
        if (r->right == NULL) {
            Node* t = r->left;
            delete r;
            return t;
        }

        Node* t = minimum(r->right);
        r->data = t->data;
        r->right = deleteNode(r->right, t->data);
    }
    return r;
}

void display(Node* r) {
    if (r != NULL) {
        display(r->left);
        cout << r->data << " ";
        display(r->right);
    }
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    int id;
    cout << "Enter employee ID to delete: ";
    cin >> id;

    root = deleteNode(root, id);

    cout << "Remaining IDs: ";
    display(root);
    return 0;
}

