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

vector<vector<int>> ans;
void LevelOrder(node* root ) {

    queue<node*> q;

    q.push(root);

    int i = 0;

    while (!q.empty()) {

        int n = q.size();
        vector<int> r(n);

        for ( int j = 0; j < n ; j++) {

            node* front = q.front();
            q.pop();
            int cur = i % 2 == 0 ? j : n - j - 1;
            r[cur] = front->data;

            if (front->left) {
                q.push(front->left);
            }

            if (front->right) {
                q.push(front->right);
            }

        }
        i++;
        ans.push_back(r);

    }

}

void Print(vector<vector<int>> vect) {

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
    }
}


int main() {

    node* root = NULL;

    root = BuildTree("true");

    LevelOrder(root);

    Print(ans);

}