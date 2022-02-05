#include <iostream>
using namespace std;


class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};


node* BuildTree(node* root, int key) {

    // BASE CASE
    if (root == NULL) {
        node* root = new node(key);

        return root;
    }


    // RECURSIVE CASE

    if (root->data > key ) // left side
    {
        root->left = BuildTree(root->left, key);
    }

    if (root->data < key) // right side
    {

        root->right = BuildTree(root->right, key);

    }
    return root;
}



node* FindMinimum(node* root) {

    if (!root) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


node* FindMaximum(node* root) {

    if (!root) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}



int main() {

    node* root = NULL;

    root = BuildTree(root, 10);
    root = BuildTree(root, 5);
    root = BuildTree(root, 3);
    root = BuildTree(root, 7);
    root = BuildTree(root, 15);
    root = BuildTree(root, 13);
    root = BuildTree(root, 17);

    InOrder(root);

    node* min = FindMinimum(root);
    cout << endl;
    cout << "MINIMUM IN BST : " << min->data << endl;
    node* maxi = FindMaximum(root);
    cout << "MAXIMUM IN BST : " << maxi->data << endl;
}
