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


void modifyBSTUtil(node* root, int &sum) {

    if (root == NULL) {
        return;
    }

    modifyBSTUtil(root->right, sum);

    sum = sum + root->data;
    root->data = sum;

    modifyBSTUtil(root->left, sum);
}


void inorder(node * root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    int sum = 0;
    modifyBSTUtil(root, sum);

    inorder(root);

    cout << endl;

}
