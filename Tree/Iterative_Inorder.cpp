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

//Iterative Inorder
void iterativeInorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    stack<struct Node *> s;
    struct Node *node = root;
    while(true)
    {
        if(node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            if(s.empty() == true)
            {
                break;
            }
            node = s.top();
            s.pop();
            cout<<node->data<<" ";
            node = node->right;
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