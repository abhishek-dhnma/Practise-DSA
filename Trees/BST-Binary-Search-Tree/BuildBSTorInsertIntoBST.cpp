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


void PreOrder(node* root) {

    // Base Case
    if (root == NULL) {
        cout << -1 << " ";
        return;
    }

    //Recursive Case

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);

}

void InOrder(node* root) {

    // Base Case

    if (root ==  NULL) {

        cout << -1 << " ";
        return;
    }

    // Recursive Case

    InOrder(root->left);

    cout << root->data << " " ;

    InOrder(root->right);


}

void InOrders(node* root) {

    // Base Case

    if (root ==  NULL) {

        //cout << -1 << " ";
        return;
    }

    // Recursive Case

    InOrders(root->left);

    cout << root->data << " " ;

    InOrders(root->right);


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

    cout << "PreOrder : ";
    PreOrder(root);
    cout << endl << "InOrder with -1 : ";
    InOrder(root);
    cout << endl << "InOrders without -1 :  ";
    InOrders(root);
    cout <<  endl << "BST's inOrder is Always in Sorted Form" ;

}
