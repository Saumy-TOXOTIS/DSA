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

//Iterative Postorder
void iterativePostorder_2stack(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    stack<struct Node *> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        struct Node *node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left != NULL)
        {
            s1.push(node->left);
        }
        if(node->right != NULL)
        {
            s1.push(node->right);
        }
    }
    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

void iterativePostorder_1stack(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    stack<struct Node *> s;
    struct Node *curr = root;
    struct Node *prev = NULL;
    do
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        while(curr == NULL && !s.empty())
        {
            curr = s.top();
            if(curr->right == NULL || curr->right == prev)
            {
                cout<<curr->data<<" ";
                s.pop();
                prev = curr;
                curr = NULL;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
    while(!s.empty());
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
}