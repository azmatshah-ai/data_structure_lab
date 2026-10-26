#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node *left, *right;

    Node(int n) {
        id = n;
        left = right = NULL;
    }
};

Node* insert(Node* root, int n) {
    if (root == NULL)
        return new Node(n);

    if (n < root->id)
        root->left = insert(root->left, n);
    else if (n > root->id)
        root->right = insert(root->right, n);

    return root;
}

void search(Node* root, int n) {
    int count = 0;

    while (root != NULL) {
        count++;

        if (root->id == n) {
            cout << "Book Found" << endl;
            cout << "Comparisons: " << count;
            return;
        }

        if (n < root->id)
            root = root->left;
        else
            root = root->right;
    }

    cout << "Book Not Found" << endl;
    cout << "Comparisons: " << count;
}

int main() {
    Node* root = NULL;
    int a[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    int n;
    cout << "Enter book ID: ";
    cin >> n;

    search(root, n);

    return 0;
}
