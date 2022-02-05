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



bool ChecktwoTrees(node* root1, node* root2) {

    if (root1 == NULL && root2 == NULL) {
        // Both are empty : True
        return true;

    } else if ( root1 == NULL || root2 == NULL) {
        // Anyone of these Dont have Root : False
        return false;

    } else {


        bool x = ChecktwoTrees(root1->left, root2->left);
        bool y = ChecktwoTrees(root1->right, root2->right);
        return x and y;

        // return ChecktwoTrees(root1->left, root2->left) && ChecktwoTrees(root1->right, root2->right)
    }

}

int main() {

    node* root1 = NULL;
    root1 = BuildTree("true");

    node* root2 = NULL;
    root2 = BuildTree("true");

    ChecktwoTrees(root1, root2) ? cout << "true" : cout << "false";
}