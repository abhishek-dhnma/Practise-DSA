#include <iostream>
#include<queue>
#include <vector>

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

node* BuildTree(string s) {

    // RECURSIVE TREE

    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);

        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = BuildTree(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = BuildTree(r);
        }
        return root;
    }
    return NULL;

}


//function to print paths from the root node to every leaf node
void print(vector<int> v) {

    int n = v.size();

    for (int i = 0 ; i < n ; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


// Recursive function to find paths from the root node to every leaf node
void  RootToLead(node* root, vector<int>& v) {

    // BASE CASE
    if (root == NULL) {
        return;
    }

    //RECURSIVE CASE

    // include the current node to the path
    v.push_back(root->data);

    // if a leaf node is found, print the path
    if (root->left ==  NULL && root->right == NULL) {
        print(v);
    }

    // recur for the left and right subtree
    RootToLead(root->left, v);
    RootToLead(root->right, v);

    // backtrack: remove the current node after the left, and right subtree are done
    v.pop_back();

}




int main() {

    node* root = NULL;

    root = BuildTree("true");

    vector<int> v;

    RootToLead(root, v);

}