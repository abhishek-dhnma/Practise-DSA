#include <iostream>
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

    int data;
    cin >> data;

    if (data ==  -1) {
        return NULL;
    }

    node* root = new node(data);

    root->left = BuildTree();
    root->right = BuildTree();

    return root;

}

int heightoftree(node* root) {

    if (root == NULL) {
        return -1;
    }

    int LT = heightoftree(root->left);
    int RT = heightoftree(root->right);

    return 1 + max(LT, RT);

}


int DiameterOfTree(node* root) {

    if (root == NULL) {
        return 0;
    }


    // Pass Through Root
    int H = heightoftree(root->left) + heightoftree(root->right) + 2;
    // Left Diameter
    int LD = DiameterOfTree(root->left);
    // Right Diameter
    int RD = DiameterOfTree(root->right);

    return max(H, max(LD, RD));

}



int main() {

    node* root = NULL;

    root = BuildTree();

    cout << "Heigth Of Tree: " << heightoftree(root) << endl;

    cout << "Diameter Of Tree: " <<  DiameterOfTree(root);
}
