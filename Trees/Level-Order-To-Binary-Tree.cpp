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


node* BuildTree(){

    int x;
    cin >> x;

    queue<node*> q;
    node* root = new node(x);
    q.push(root);

    while (!q.empty()) {

        node* front = q.front();
        q.pop();

        int leftData;
        cin >> leftData;

        if (leftData != -1) {
            node* left = new node(leftData);
            front->left = left;
            q.push(left);
        }

        int rightData;
        cin >> rightData;

        if (rightData != -1 ) {
            node* right = new node(rightData);
            front->right = right;
            q.push(right);
        }

    }

    return root;

}




// Level Order Printing Function Expected Output

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

    LevelOrdePrintExpectedOutput(root);


}
