#include <iostream>
#include <string>
#include<queue>

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


node* BuildTree(string isTree)
{

    if (isTree == "false") {
        return NULL;
    }

    int d;
    cin >> d;

    node* newNode = new node(d);
    cin >> isTree;

    newNode->left = BuildTree(isTree);
    cin >> isTree;
    newNode->right = BuildTree(isTree);

    return newNode;
}

void LevelOrderPrint(node* root) {

    queue<node*> q;
    node* front;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        front = q.front();
        q.pop();

        if (front == NULL) {

            cout << endl;

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

int main() {

    node* root = NULL;
    root = BuildTree("true");

    LevelOrderPrint(root);


}
