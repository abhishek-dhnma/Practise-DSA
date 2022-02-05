#include <iostream>
#include<queue>
using namespace std;


// NODE CLASS
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


// TREE BUILDING FUNCTION

node* BuildTree() {

    int x;
    cin >> x;

    // BASE CASE

    if (x == -1) {
        node* root = NULL;
        // If data = -1 means thier is no node so send it NULL root
        return root;
    }

    node* root = new node(x);


    // RECUSRIVE CASE

    root->left  = BuildTree();
    root->right = BuildTree();

    return root;

}


// PRE ORDER PRNTING FUNCTION

void PreOrderPrint(node* root) {

    // BASE  CASE
    if (root == NULL) {
        cout << -1 << " ";
        return;
    }


    // RECURSIVE CASE

    cout << root->data << " ";
    PreOrderPrint(root->left);
    PreOrderPrint(root->right);

}


// LEVEL ORDER PRINTING FUCNTION

void LevelOrdePrint(node* root) {

    queue<node*> q;
    // Queue is Node* type because we are storing pointers in the queue

    q.push(root);

    node* front = NULL;

    while (!q.empty()) {
        front = q.front();
        q.pop();

        cout << front->data << " ";

        if (front->left) {
            q.push(front->left);
        }

        if (front->right) {
            q.push(front->right);
        }
    }
}

// MAIN FUNCTION

int main() {

    node* root = NULL;

    root = BuildTree();

    cout << "PreOrderPrint: ";
    PreOrderPrint(root);
    cout << endl << "Level Order Printing Without desire output: ";
    LevelOrdePrint(root);

}
