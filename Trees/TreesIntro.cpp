#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};


void PreOrderBuild(node* root) {

	//Base Case

	if (root == NULL) {
		cout << "-1" << " ";
		return;
	}

	// Recursive Case

	cout << root->data << " ";
	PreOrderBuild(root->left);
	PreOrderBuild(root->right);

}

void InOrderBuild(node* root) {

	//Base Case

	if (root == NULL) {
		cout << "-1" << " ";
		return;
	}

	// Recursive Case


	InOrderBuild(root->left);
	cout << root->data << " ";
	InOrderBuild(root->right);

}


void PostOrderBuild(node* root) {

	//Base Case

	if (root == NULL) {
		cout << "-1" << " ";
		return;
	}

	// Recursive Case
	PostOrderBuild(root->left);
	PostOrderBuild(root->right);
	cout << root->data << " ";


}



int main() {

	node* root = NULL;

	root = new node(8);
	root->left = new node(3);
	root->right = new node(10);
	root->left->left = new node(1);
	root->left->right = new node(6);
	root->left->right->left = new node(4);
	root->left->right->right = new node(7);
	root->right->right = new node(14);
	root->right->right->left = new node(13);

	cout << "PreOrderBuild : "; PreOrderBuild(root); cout << endl;
	cout << "InOrderBuild : "; InOrderBuild(root); cout << endl;
	cout << "PostOrderBuild : "; PostOrderBuild(root); cout << endl;


	return 0;
}