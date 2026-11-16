#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node *left, *right;

    Node(string d) {
        data = d;
        left = right = NULL;
    }
};

void Inorder(Node* root) {
    if (root == NULL) return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root) {
    if (root == NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node("C Drive");

    root->left = new Node("Program Files");
    root->right = new Node("Users");

    root->left->left = new Node("Games");
    root->left->right = new Node("Applications");

    root->right->left = new Node("Desktop");
    root->right->right = new Node("Documents");

    cout << "Inorder (Left, Root, Right): ";
    Inorder(root);

    cout << "\nPreorder (Root, Left, Right): ";
    Preorder(root);

    cout << "\nPostorder (Left, Right, Root): ";
    Postorder(root);

    return 0;
}
