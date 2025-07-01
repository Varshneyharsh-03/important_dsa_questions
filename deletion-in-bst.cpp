#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int x) {
        key = x;
        left = right = nullptr;
    }
};

// Helper to find minimum value node in a subtree
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    // Traverse to find the node
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        // Case 1 & 2: one or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: two children
        Node* temp = findMin(root->right); // or use max in left
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key); // delete successor
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Example usage
int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50); // Deleting node with 2 children

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
