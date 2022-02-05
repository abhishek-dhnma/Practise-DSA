#include <iostream>
#include <string>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = this->right  = NULL;
    }
};

node* Build(string s) {

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
            root->left = Build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = Build(r);
        }
        return root;
    }
    return NULL;

}

void PrintSiblings(node* root) {

    // BASE CASE
    if (root == NULL) {
        //cout<<-1<<" ";
        return;
    }

    // RECURSIVE CASE

    if ( !root->left && root->right ) {
        cout << root->right->data << " ";
    }

    if ( root->left && !root->right) {
        cout << root->left->data << " ";
    }

    PrintSiblings(root->left);
    PrintSiblings(root->right);
}

int main() {

    node* root = NULL;
    root = Build("true");

    PrintSiblings(root);

}
