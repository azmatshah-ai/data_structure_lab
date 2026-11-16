#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node *left, *right;

    Node(string n) {
        name = n;
        left = right = NULL;
    }
};

int main() {
    Node *root = new Node("HOD");

    root->left = new Node("Coordinator 1");
    root->right = new Node("Coordinator 2");

    root->left->left = new Node("Faculty 1");
    root->left->right = new Node("Faculty 2");

    root->right->left = new Node("Faculty 3");
    root->right->right = new Node("Faculty 4");

    Node* nodes[] = {
        root, root->left, root->right,
        root->left->left, root->left->right,
        root->right->left, root->right->right
    };

    for (int i = 0; i < 7; i++) {
        cout << "Member: " << nodes[i]->name << endl;

        cout << "Left Child: ";
        if (nodes[i]->left != NULL)
            cout << nodes[i]->left->name;
        else
            cout << "NULL";

        cout << "\nRight Child: ";
        if (nodes[i]->right != NULL)
            cout << nodes[i]->right->name;
        else
            cout << "NULL";

        cout << "\n\n";
    }

    return 0;
}
