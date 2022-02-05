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

node* BuildTree() {

    int data;
    cin >> data;

    if (data ==  -1) {
        return NULL;
    }

    node* root = new node(data);

    root->left = BuildTree();
    root->right = BuildTree();

    return root;

}

void PreOrderBuild(node* root) {

    //Base Case

    if (root == NULL) {
        cout << "-1" << " ";
        return;
    }

    // Recursive Case

    cout << root->data << " ";
    PreOrderBuild(root->left);
    PreOrderBuild(root->right);

}

int main() {

    node* root = NULL;

    root = BuildTree();
    cout << "Preorder: ";
    PreOrderBuild(root);

}
