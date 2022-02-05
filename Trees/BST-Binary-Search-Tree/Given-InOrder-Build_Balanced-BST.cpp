#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data =  data;
        this->left =  this->right = NULL;
    }

};



void PreOrder(node* root) {

    // Base Case
    if (root == NULL) {
        cout << -1 << " ";
        return;
    }

    //Recursive Case

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);

}

node* BuildBalancedBST(int Arr[], int s, int e) {

    // Base Case
    if (s > e) {

        return NULL;
    }


    // Recursive Case

    int mid = s + (e - s) / 2 ;

    node* root = new node(Arr[mid]);

    root->left = BuildBalancedBST(Arr, s, mid - 1);

    root->right = BuildBalancedBST(Arr, mid + 1, e);

    return root;

}


int main() {

    node* root = NULL;

    int n;
    cin >> n;
    int Arr[n];

    for (int i = 0; i < n ; i++) {
        cin >> Arr[i];
    }

    root = BuildBalancedBST(Arr, 0, n - 1 );


    PreOrder(root);

}
