
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void displayTree(Node* root) {
    if (root == NULL)
        return;

    cout << "Person: " << root->name << endl;

    cout << "Left Child: ";
    if (root->left != NULL)
        cout << root->left->name << endl;
    else
        cout << "None" << endl;

    cout << "Right Child: ";
    if (root->right != NULL)
        cout << root->right->name << endl;
    else
        cout << "None" << endl;

    cout << "----------------------" << endl;

    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    Node* root = new Node("Grandfather");

    root->left = new Node("Father");
    root->right = new Node("Uncle");

    root->left->left = new Node("Me");
    root->left->right = new Node("Sister");

    root->right->left = new Node("Cousin");
    root->right->right = new Node("Cousin 2");

    displayTree(root);

    return 0;
}

