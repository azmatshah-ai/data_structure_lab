
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

class BST {
    Node* root;

    Node* insert(Node* r, int n) {
        if (r == NULL) return new Node(n);
        if (n < r->data) r->left = insert(r->left, n);
        else if (n > r->data) r->right = insert(r->right, n);
        return r;
    }

    bool search(Node* r, int n) {
        if (r == NULL) return false;
        if (r->data == n) return true;
        if (n < r->data) return search(r->left, n);
        return search(r->right, n);
    }

    Node* minimum(Node* r) {
        while (r->left != NULL) r = r->left;
        return r;
    }

    Node* remove(Node* r, int n) {
        if (r == NULL) return NULL;

        if (n < r->data) r->left = remove(r->left, n);
        else if (n > r->data) r->right = remove(r->right, n);
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
            r->right = remove(r->right, t->data);
        }
        return r;
    }

    void in(Node* r) {
        if (r != NULL) {
            in(r->left);
            cout << r->data << " ";
            in(r->right);
        }
    }

    void pre(Node* r) {
        if (r != NULL) {
            cout << r->data << " ";
            pre(r->left);
            pre(r->right);
        }
    }

    void post(Node* r) {
        if (r != NULL) {
            post(r->left);
            post(r->right);
            cout << r->data << " ";
        }
    }

    void clear(Node* r) {
        if (r != NULL) {
            clear(r->left);
            clear(r->right);
            delete r;
        }
    }

public:
    BST() { root = NULL; }
    ~BST() { clear(root); }

    void add(int n) {
        if (search(root, n))
            cout << "Duplicate ID!\n";
        else {
            root = insert(root, n);
            cout << "Product inserted.\n";
        }
    }

    void find(int n) {
        if (search(root, n)) cout << "Product found.\n";
        else cout << "Product not found.\n";
    }

    void erase(int n) {
        if (!search(root, n))
            cout << "Product not found.\n";
        else {
            root = remove(root, n);
            cout << "Product deleted.\n";
        }
    }

    void inorder() { in(root); cout << endl; }
    void preorder() { pre(root); cout << endl; }
    void postorder() { post(root); cout << endl; }
};

int main() {
    BST tree;
    int choice, id;

    do {
        cout << "\n1.Insert  2.Search  3.Delete\n";
        cout << "4.In-order  5.Pre-order  6.Post-order  7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            tree.add(id);
            break;
        case 2:
            cout << "Enter product ID: ";
            cin >> id;
            tree.find(id);
            break;
        case 3:
            cout << "Enter product ID: ";
            cin >> id;
            tree.erase(id);
            break;
        case 4: tree.inorder(); break;
        case 5: tree.preorder(); break;
        case 6: tree.postorder(); break;
        case 7: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}

