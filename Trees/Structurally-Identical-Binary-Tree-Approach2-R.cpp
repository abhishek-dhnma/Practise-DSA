/*
TIME COMPLEXITY : O(n)

if( H_tree1_n > H_tree2_m ){

 TIME COMPLEXITY : O(m)

}
if(H_tree1_n < H_tree2_m){

    TIME COMPLEXITY : O(n)
}

*/

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


bool ChecktwoTrees(node* root1, node* root2) {

    if (root1 == NULL && root2 == NULL) {
        // Both are empty : Empty tree are identical : true
        return true;
    }


    if ( root1 && root2) {
        // If they both are not empty then ?  check for left and right
        // If both are true then : true

        bool x = ChecktwoTrees(root1->left, root2->left);
        bool y = ChecktwoTrees(root1->right, root2->right);

        return x and y;
    }

    // They are both are not match then false
    return false;

}

int main() {

    node* root1 = NULL;
    root1 = BuildTree("true");

    node* root2 = NULL;
    root2 = BuildTree("true");

    LevelOrderPrint(root1);
    cout << endl;
    LevelOrderPrint(root2);

    cout << endl;
    ChecktwoTrees(root1, root2) ? cout << "true" : cout << "false";
}