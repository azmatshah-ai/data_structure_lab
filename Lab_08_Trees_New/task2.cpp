#include <iostream>
#include <queue>
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

void BFS(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    Node* root = new Node("Electronics");

    root->left = new Node("Clothing");
    root->right = new Node("Mobiles");

    root->left->left = new Node("Laptops");
    root->left->right = new Node("Men");

    root->right->left = new Node("Women");
    root->right->right = new Node("Accessories");

    cout << "BFS Traversal: ";
    BFS(root);

    return 0;
}
