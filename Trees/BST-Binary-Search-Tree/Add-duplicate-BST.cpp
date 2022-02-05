/* https://www.geeksforgeeks.org/double-tree/ */

#include <iostream>
using namespace std;

// CLASS NODE

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


// BUILD BST FUNCTION

node* BuildBST(node* root, int key) {

    if (root ==  NULL) {
        node* root = new node(key);
        return root;
    }

    if ( root->data > key) // left side
    {
        root->left = BuildBST(root->left, key);
    }

    if (root->data < key) // right side
    {
        root->right = BuildBST(root->right, key);
    }

    return root;
}


void AddDuplicate(node* root) {

    node* oddLeft;

    // BASE CASE

    if (root == NULL) {
        return;
    }

    // RECURSIVE CASE

    AddDuplicate(root->left);
    AddDuplicate(root->right);

    oddLeft = root->left;
    root->left = new node(root->data);
    root->left->left = oddLeft;
}



void display(node* root) {
    if (root == NULL) {
        return;
    }

    string str = "";
    str += root->left == NULL ? "END" : to_string(root->left->data) + "";
    str += " => " + to_string(root->data) + " <= ";
    str += root->right == NULL ? "END" : to_string(root->right->data) + "";
    cout << str << endl;

    display(root->left);
    display(root->right);

}

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }

    node* root = NULL;

    for (int i = 0 ; i < n ; i++)
    {
        root = BuildBST(root, arr[i]);
    }

    AddDuplicate(root);

    display(root);

    cout << endl;

}
