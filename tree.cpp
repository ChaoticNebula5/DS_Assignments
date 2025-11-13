#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* newNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = nullptr;
    return temp;
}


Node* insert(Node* root, int value) {
    if (root == nullptr)
        return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}


bool searchRecursive(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return (key < root->data)
               ? searchRecursive(root->left, key)
               : searchRecursive(root->right, key);
}

bool searchIterative(Node* root, int key) {
    while (root) {
        if (key == root->data)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}


Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left)
        root = root->left;
    return root;
}


Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right)
        root = root->right;
    return root;
}


Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right)
        return findMin(node->right);
    Node* succ = nullptr;
    while (root) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}


Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left)
        return findMax(node->left);
    Node* pred = nullptr;
    while (root) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}


Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root); cout << endl;
    cout << "Preorder Traversal: ";
    preorder(root); cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root); cout << endl;

    cout << "\nSearch 40 (Recursive): " << (searchRecursive(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 90 (Iterative): " << (searchIterative(root, 90) ? "Found" : "Not Found") << endl;

    cout << "\nMin Element: " << findMin(root)->data << endl;
    cout << "Max Element: " << findMax(root)->data << endl;

    Node* node = root->left; // node = 30
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);
    cout << "\nInorder Successor of " << node->data << ": " << (succ ? to_string(succ->data) : "None") << endl;
    cout << "Inorder Predecessor of " << node->data << ": " << (pred ? to_string(pred->data) : "None") << endl;

    cout << "\nMax Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    cout << "\nIs BST? " << (isBST(root) ? "Yes" : "No") << endl;

    root = deleteNode(root, 70);
    cout << "\nAfter deleting 70, Inorder Traversal: ";
    inorder(root); cout << endl;

    return 0;
}