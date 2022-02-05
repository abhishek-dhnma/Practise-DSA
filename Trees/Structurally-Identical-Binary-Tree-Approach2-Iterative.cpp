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
    // It done using TWO QUEUE AND IN LEVEL ORDER Way (L->R ) and checkig conditions

    queue<node*> q;
    queue<node*> p;

    q.push(root1);
    p.push(root2);


    while (!q.empty() && !p.empty()) {

        node* front_q = q.front();
        node* front_p = p.front();

        q.pop();
        p.pop();

        // If you also want to check data for the both trees

        /*        if(front_q->data != front_p->data){
                    return false;
                }
        */

        // Left Children
        if ( front_q->left && front_p->left) {
            q.push(front_q->left);
            p.push(front_p->left);
        } else if (front_q->left  || front_p->left) {
            return false;
        }

        // Right Children
        if ( front_q->right && front_p->right) {
            q.push(front_q->right);
            p.push(front_p->right);
        } else if (front_q->right || front_p->right) {
            return false;
        }

    }
    return true;


}

int main() {

    node* root1 = NULL;
    root1 = BuildTree("true");

    node* root2 = NULL;
    root2 = BuildTree("true");

    cout << endl;
    ChecktwoTrees(root1, root2) ? cout << "true" : cout << "false";
}