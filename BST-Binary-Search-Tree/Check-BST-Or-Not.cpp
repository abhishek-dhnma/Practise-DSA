#include <iostream>
#include<climits>
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

int FindMaximum(node* root) {

    if (root == NULL) {
        return INT_MIN;
    }
    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

int FindMinimum(node* root) {

    if (root == NULL) {
        return INT_MAX;
    }
    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}


bool CheckBST(node* root) {

    // BASE CASE
    if (root == NULL) {
        // Empty tree is BST
        return true;
    }


    // RECURSIVE CASE

    bool LeftSubtree = CheckBST(root->left);

    bool RightSubtree = CheckBST(root->right);

    bool CheckRoot = (root->data > FindMaximum(root->left) && root->data < FindMinimum(root->right)) ? true : false ;

    return LeftSubtree and RightSubtree and CheckRoot;
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
    cout << endl;
    CheckBST(root) ? cout << "Its a BST" : cout << "Its not a BST";

}
