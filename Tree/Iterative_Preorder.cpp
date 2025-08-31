#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//Iterative Preorder
void iterativePreorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    stack<struct Node *> s;
    s.push(root);
    while(!s.empty())
    {
        struct Node *node = s.top();
        s.pop();
        cout<<node->data<<" ";
        if(node->right != NULL)
        {
            s.push(node->right);
        }
        if(node->left != NULL)
        {
            s.push(node->left);
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
}