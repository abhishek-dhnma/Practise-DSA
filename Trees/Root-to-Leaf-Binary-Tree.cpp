// https://www.includehelp.com/data-structure-tutorial/root-to-leaf-path-having-sum-x-in-the-given-tree.aspx
/*
We can solve this recursively like the below algorithm:

We keep calculating sum from the root and if reaching any node the cumulative sum becomes X, then we find a path having sum X.

Initially, cur_sum is 0 which stores cumulative sum for paths.

Algorithm :

Function hasPathSumRecur(node, sum X , cur_sum):
    If root is NULL
        return FALSE;
    Add current node value to cur_sum
    If current node is a leaf node & && cur_sum  equals to X
        return TRUE as we find a path;
    Otherwise recur for both the subtrees and
    if we find any one satisfying then return TRUE else FALSE
*/

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

void printAns(vector<int>& ans) {

    for (int i = 0 ; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void printKPathRec(node* root, int k, vector<int>& ans, int cur_sum) {

    if (root == NULL) {
        return;
    }

    cur_sum = cur_sum + root->data;
    ans.push_back(root->data);

    if ( !root->left && !root->right && cur_sum == k) {
        printAns(ans);
    }

    printKPathRec(root->left, k, ans, cur_sum);
    printKPathRec(root->right, k, ans, cur_sum);

    ans.pop_back();

}



void printKPath(node* root, int k) {

    vector<int> ans;
    printKPathRec(root, k, ans, 0);
}


int main() {

    node* root = NULL;

    root = BuildTree("true");

    int k;
    cin >> k;

    printKPath(root, k);
}