#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};


// InPut : 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

class Pair {

public:
    bool isBalanced;
    int isHeight;
};

Pair isHeightBalancedOptimised(node *root)
{
    // Write your code here
    Pair p;

    if (root == NULL) {
        p.isBalanced = true;
        p.isHeight = -1;
        return p;

    }

    Pair CL = isHeightBalancedOptimised(root->left);
    Pair CR = isHeightBalancedOptimised(root->right);

    bool H = abs(CL.isHeight - CR.isHeight) <= 1 ? true : false;

    p.isBalanced = CL.isBalanced && CR.isBalanced && H;
    p.isHeight = 1 + max(CL.isHeight , CR.isHeight);

    return p;
}

int main()
{
    node *root = build("true");

    cout << boolalpha << isHeightBalancedOptimised(root).isBalanced;

    return 0;

// InPut : 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
}
