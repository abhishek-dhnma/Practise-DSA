#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node (int data) {
        this->data = data;
        this->left = this->right = NULL;
    }

};


node* BuildTree(int preodr[], int inodr[], int start, int end, int& i ) {

    // BASE CASE

    if (start > end) {
        return NULL;
    }

    // RECURSIVE CASE

    // preorder
    int first = preodr[i]; // extrate first val from prorder array
    i++;

    node* root = new node(first); // make that first root from preorder array

    int k = -1; // it helps us to iterate over inorder

    for (int j = start; j <= end ; j++) { // find first of preoder in inorder
        if (first == inodr[j]) {
            k = j;
            break;
        }
    }

    root->left = BuildTree(preodr, inodr , start, k - 1, i ); //Build LeftSubtree
    root->right = BuildTree(preodr, inodr, k + 1, end, i); // Build RightSubtree


    return root;
}


void preorder(node* root) {

    // BASE CASE
    if (root == NULL) {
        cout << -1 << " ";
        return;
    }


    // RECUSRIVE CASE

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}


int main() {

    int preodr[] = {10, 20, 40, 50, 70, 30, 60};
    int inodr[]  = {40, 20, 70, 50, 10, 30, 60};
    int n = sizeof(inodr) / sizeof(int);

    int i = 0 ;
    node* root = BuildTree(preodr, inodr, 0, n - 1, i);


    preorder(root);


}
