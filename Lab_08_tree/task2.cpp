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

Node* insert(Node* root, int n) {
    if (root == NULL)
        return new Node(n);

    if (n < root->data)
        root->left = insert(root->left, n);
    else if (n > root->data)
        root->right = insert(root->right, n);

    return root;
}

void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main() {
    Node* root = NULL;
    int a[] = {45, 25, 65, 15, 35, 55, 75};

    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    int n;
    cout << "Enter two roll numbers: ";
    cin >> n;
    root = insert(root, n);

    cin >> n;
    root = insert(root, n);

    cout << "Sorted roll numbers: ";
    display(root);

    return 0;
}
