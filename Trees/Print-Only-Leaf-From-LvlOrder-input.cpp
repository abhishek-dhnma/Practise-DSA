#include <iostream>
#include <queue>

using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->right = this->left = NULL;
    }
};

node* BuildTreeLO() {

    int d;
    cin >> d;
    node* root = new node(d);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {

        node* front = q.front();
        q.pop();

        int leftdata;
        cin >> leftdata;

        if (leftdata != -1) {
            node* left = new node(leftdata);
            front->left = left;
            q.push(left);
        }

        int rightdata;
        cin >> rightdata;

        if (rightdata != -1) {
            node* right = new node(rightdata);
            front->right = right;
            q.push(right);
        }
    }
    return root;
}

void LevelOrdePrint1(node* root) {

    queue<node*> q;
    // Queue is Node* type because we are storing pointers/roots in the queue

    q.push(root);

    node* front;

    while (!q.empty()) {

        front = q.front();
        q.pop();

        // If root not exist ONLY print NewLine

        if (!front) {
            cout << endl;
        }

        // If both Left and Right Node is not present
        // print only those

        if (!front->left && !front->right) {
            cout << front->data << " ";
        }

        if (front->left) {
            q.push(front->left);
        }

        if (front->right) {
            q.push(front->right);
        }
    }
}


int main() {

    node* root = NULL;

    root = BuildTreeLO();
    LevelOrdePrint1(root);
}