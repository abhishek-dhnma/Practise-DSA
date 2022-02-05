#include<iostream>
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


class Pair {

public:
    node* head;
    node* tail;
};


Pair Transform_BST_TO_Linkedlist(node* root) {

    Pair p;

    // BASE CASE
    if (root == NULL) {
        p.tail = p.head = NULL;
        return p;
    }


    // RECURSIVE CASE

    Pair PL = Transform_BST_TO_Linkedlist(root->left);

    if (PL.head) {
        PL.tail->right = root;
        p.head = PL.head;
    } else {
        p.head = root;
    }


    Pair PR = Transform_BST_TO_Linkedlist(root->right);

    if (PR.head) {
        root->right = PR.head;
        p.tail = PR.tail;
    } else {
        p.tail = root;
    }

    return p;
}

void Print_LL(node* head) {

    while (head) {
        cout << head->data ;
        head = head->right;
        if (head) {
            cout << "->";
        }
    }

    cout << endl;
}

int main() {

    node* root = new node(10);

    root->left = new node(5);
    root->left->left  = new node(3);
    root->left->right = new node(7);

    root->right = new node(15);
    root->right->left  = new node(13);
    root->right->right = new node(17);


    //Pair p = Transform_BST_TO_Linkedlist(root);
    //Print_LL( p.head );

    Print_LL(Transform_BST_TO_Linkedlist(root).head);


    return 0;
}