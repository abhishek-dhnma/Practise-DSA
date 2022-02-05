#include<iostream>
#include<climits>

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


bool checkBSTRangeEfficient(node* root , int lb, int ub) {

	// BASE CASE

	if (root ==  NULL) {
		return true;
		// Empty tree is BST
	}


	// RESURSIVE CASE

	// Combine all cases in one line so shortcircuiting happen if any one false

	if ( root->data > lb and root->data < ub and
	        checkBSTRangeEfficient(root->left, lb, root->data) and
	        checkBSTRangeEfficient(root->right, root->data, ub) )
	{
		return true;
	}

	return false;

}

int main() {

	node* root = new node(10);

	root->left = new node(5);
	root->left->left  = new node(3);
	root->left->right = new node(7);

	root->right = new node(15);
	root->right->left  = new node(13);
	root->right->right = new node(17);

	checkBSTRangeEfficient(root, INT_MIN, INT_MAX) ? cout << "true" << endl :
	        cout << "false" << endl;

	return 0;
}