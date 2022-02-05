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

node* FindMaximum(node* root) {

    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}


node* DeleteFromBST(node* root, int key) {

    // BASE CASE
    if (root == NULL)
    {
        return NULL;
    }


    // RECURSIVE CASE

    if (root->data == key) {
        if ( !root->left && !root->right ) // Means You are at Leaf Node or Last Node
        {
            delete root;
            root = NULL;

        } else if ( !root->left && root->right) // Means You are at node which have only right side
        {
            node* temp = root->right;
            delete root;
            root = temp;

        } else if ( root->left && !root->right) // Means You are at node which have only left side
        {
            node* temp = root->left;
            delete root;
            root = temp;

        } else // node has two child
        {
            node* LeftMaxiNode = FindMaximum(root->left); // Find max in left subtree or also min ini right subtree
            // swap leftMaxNode With your key data
            swap(LeftMaxiNode->data, root->data);
            root->left =  DeleteFromBST(root->left, key);

        }

    } else if (root->data > key) { // left Side Tree

        root->left = DeleteFromBST(root->left, key);

    } else { // Right Side Tree

        root->right = DeleteFromBST(root->right, key);
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
    cout << endl;
    int key = 7;
    root = DeleteFromBST(root, key);
    InOrder(root);
    cout << endl;
    root = DeleteFromBST(root, 13);
    InOrder(root);
    cout << endl;
    root = DeleteFromBST(root, 10);
    InOrder(root);
    cout << endl;

}
