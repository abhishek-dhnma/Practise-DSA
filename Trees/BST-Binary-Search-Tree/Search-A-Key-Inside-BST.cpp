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



void InOrder(node* root) {

    // Base Case

    if (root ==  NULL) {

        //cout << -1 << " ";
        return;
    }

    // Recursive Case

    InOrder(root->left);

    cout << root->data << " " ;

    InOrder(root->right);


}

bool SearchBST(node* root, int key) {

    // BASE CASE
    if (root == NULL) {
        return false;
    }

    // RECURSIVE CASE


    if (root->data == key) {
        return true;
    }
    else if (root->data > key) {

        return SearchBST(root->left, key);

    }
    else {

        return SearchBST(root->right, key);

    }


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
    root = BuildTree(root, 57);

    InOrder(root);

    int key = 57;
    SearchBST(root, key) ? cout << endl << "true" : cout << endl << "false";


}
