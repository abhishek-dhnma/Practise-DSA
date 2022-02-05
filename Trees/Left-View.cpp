#include<iostream>
#include<queue>

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

int maxLevel = -1;

void rightViewRecursive(node* root, int curlevel) {

    // BASE CASE

    if (root == NULL) {
        return;
    }


    // RECUSRIVE CASE

    if (maxLevel < curlevel) {

        cout << root->data << " ";
        maxLevel = curlevel;
    }


    rightViewRecursive(root->left, curlevel + 1);
    rightViewRecursive(root->right, curlevel + 1);
}


int main() {

    node* root = NULL;
    root = BuildTree();


    rightViewRecursive(root, 0);

    return 0;
}