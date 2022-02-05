#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data =  data;
        this->left =  this->right = NULL;
    }

};

node* Build_Binary_Search_Tree(node* root, int key) {

    // Base Case

    if (root == NULL) {
        node* root =  new node(key);
        return root;
    }

    // Recursive Case

    if (root->data > key) // left Side
    {
        root->left =  Build_Binary_Search_Tree(root->left, key);
    }

    if (root->data < key) // right side
    {
        root->right = Build_Binary_Search_Tree(root->right, key);
    }

    return root;
}

void BetweenRange(node* root, int s, int e) {

    // Base Case

    if (root ==  NULL) {
        return;
    }

    // Recursive Case

    BetweenRange(root->left, s, e);

    if (root->data >= s && root->data <= e) {

        cout << root->data << " " ;
    }
    BetweenRange(root->right, s, e);


}


int main() {

    node* root = NULL;

    root = Build_Binary_Search_Tree(root, 10);
    root = Build_Binary_Search_Tree(root, 5);
    root = Build_Binary_Search_Tree(root, 3);
    root = Build_Binary_Search_Tree(root, 7);
    root = Build_Binary_Search_Tree(root, 15);
    root = Build_Binary_Search_Tree(root, 13);
    root = Build_Binary_Search_Tree(root, 17);

    cout << "Nodes Between Range s to e : ";
    BetweenRange(root, 7, 17);

}
