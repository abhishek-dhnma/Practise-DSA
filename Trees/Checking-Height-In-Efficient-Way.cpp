#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data =  data;
        this->left = this->right = NULL;
    }
};


node* BuiltTree() {

    int x;
    cin >> x;

    // BASE CASE
    if (x == -1) {
        node* root = NULL;
        return NULL;
    }

    // RECURSIVE CASE
    node* root = new node(x);

    root->left = BuiltTree();
    root->right = BuiltTree();

    return root;

}


int Height(node* root) {

    // BASE CASE
    if (root == NULL) {
        return -1;
    }

    // RECURSIVE CASE

    int HL = Height(root->left);
    int HR = Height(root->right);

    return 1 + max(HL, HR);

}

bool CheckHeight(node* root) {

    // BASE CASE
    if (root == NULL) {
        return true;
    }

    // RECURSIVE CASE

    bool CH_Left = CheckHeight(root->left); // Checking left subtree height

    bool CH_Right = CheckHeight(root->right); // checking right subtree height

    bool CH_RooT = abs(Height(root->left) - Height(root->right)) <= 1 ? true : false; // checking Root

    return CH_Left && CH_Right && CH_RooT;

}

// HERE WE ARE DOING OUR WORK SEPERATELY WE TRAVERSE ENTIRE TREE 1st FOR CHECKING HEIGHT IF ITS TRUE OT NO
// AND AGAIN WE TRAVERSE TREE FOR CALCULATING HEIGHT OF ROOTS SO TIME COMPLEXITY = O(N2);
// BUT WE CAN DO IT EFFICIENTLY BY CHECKING HEIGHT AND CALCULATING HEIGHT SIMULTANEOUSLY BY USING PAIRS

class PAIRS {
public:
    bool isBalanced;
    int isHeight;
};

PAIRS CheckHeightEfficiently(node* root) {

    PAIRS p;

    // BASE CASE
    if (root == NULL) {
        p.isBalanced = true;
        p.isHeight = -1;
        return p;
    }


    // RESURSIVE CASE

    PAIRS CHE_left = CheckHeightEfficiently(root->left);
    PAIRS CHE_Right = CheckHeightEfficiently(root->right);

    bool CHE_height =  abs(CHE_left.isHeight - CHE_Right.isHeight) <= 1 ? true : false;

    p.isBalanced = CHE_left.isBalanced && CHE_Right.isBalanced && CHE_height;
    p.isHeight = 1 + max(CHE_left.isHeight, CHE_Right.isHeight);


    return p;

}

int main() {

    node* root = NULL;
    root = BuiltTree();

    CheckHeight(root) ? cout << "true" : cout << "false";
    cout << endl;
    CheckHeightEfficiently(root).isBalanced ? cout << "true" : cout << "false";


}
