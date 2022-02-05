// USING TRIPLE AND CALCULATE SIMULTANEOUSLY IsBST - MaxVal - MinVal

#include <iostream>
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


void InOrder(node* root) {

	// Base Case

	if (root ==  NULL) {

		//cout << -1 << " ";
		return;
	}

	// Recursive Case

	InOrder(root->left);

	cout << root->data << " " ;

	InOrder(root->right);

}

int FindMaximum(node* root) {

	if (root == NULL) {
		return INT_MIN;
	}
	while (root->right != NULL) {
		root = root->right;
	}

	return root->data;
}

int FindMinimum(node* root) {

	if (root == NULL) {
		return INT_MAX;
	}
	while (root->left != NULL) {
		root = root->left;
	}

	return root->data;
}


class Triple {
public:
	bool isBST;
	int MaxVal;
	int MinVal;
};

Triple CheckBSTEfficiently(node* root) {

	Triple T;

	// BASE CASE
	if (root == NULL) {
		// Empty tree is BST
		T.isBST = true;
		T.MinVal = INT_MAX;
		T.MaxVal = INT_MIN;
		return T;
	}


	// RECURSIVE CASE

	Triple T_LeftSubtree = CheckBSTEfficiently(root->left);

	Triple T_RightSubtree = CheckBSTEfficiently(root->right);

	bool CheckRoot = root->data > T_LeftSubtree.MaxVal &&
	                 root->data < T_RightSubtree.MinVal;

	T.isBST =  T_LeftSubtree.isBST && T_RightSubtree.isBST && CheckRoot ;

	T.MaxVal = max(root->data, T_RightSubtree.MaxVal);
	T.MinVal = min(root->data , T_LeftSubtree.MinVal);


	return T;
}

int main() {

	node* root = new node(10);

	root->left = new node(5);
	root->left->left  = new node(3);
	root->left->right = new node(7);

	root->right = new node(15);
	root->right->left  = new node(13);
	root->right->right = new node(17);

	cout << "InOrder : ";
	InOrder(root);
	cout << endl;
	CheckBSTEfficiently(root).isBST ? cout << "Its a BST" : cout << "Its not a BST";

}
