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


// LEVEL ORDER PRINTING FUCNTION WITHOUT FORMATTING

void LevelOrdePrint(node* root) {

    queue<node*> q;
    // Queue is Node* type because we are storing pointers/roots in the queue

    q.push(root);

    node* front;

    while (!q.empty()) {
        front = q.front();
        q.pop();

        if (!front) {
            cout << endl;
        }

        cout << front->data << " ";

        if (front->left) {
            q.push(front->left);
        }

        if (front->right) {
            q.push(front->right);
        }
    }
}

// Level Order Printing Function Expected Output / WITH FORMATTING

void LevelOrdePrintExpectedOutput(node* root) {

    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        node* front = q.front();
        q.pop();

        if (front == NULL) {

            cout << endl;

            // Here, We are checking if queue is empty or not like in last row/level of tree our queue will become empty
            // after poping it out, If we not put this condition is will go in to loop Again & again we pushing NULL
            // And processing it SAME LOOP (LTE)

            if (!q.empty()) {
                q.push(NULL);
            }

        } else {

            cout << front->data << " ";

            if (front->left) {
                q.push(front->left);
            }

            if (front->right) {
                q.push(front->right);
            }


        }

    }


}

// MAIN FUNCTION

int main() {

    node* root = NULL;

    root = BuildTree();

    cout << "PreOrderPrint: ";
    PreOrderPrint(root);
    cout << endl << "Level Order Printing Without desire output: " << endl;
    LevelOrdePrint(root);
    cout << endl << "Level Order Printing With desire output: " << endl;
    LevelOrdePrintExpectedOutput(root);

}
