//
//  Trees.cpp
//  MyCodes
//
//  Created by Devanshu Rajpoot on 24/04/23.
//


#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include "Trees.h"

using namespace std;

// Creating a Binary Tree

Node * createtree()
{
    int d;
    cout<<"data = ";
    cin>>d;
    if(d == -1)
        return NULL;
    Node * node = new Node(d);
    
    cout<<"left of ("<<d<<")";
    node->left = createtree();
    
    cout<<"right of ("<<d<<")";
    node->right = createtree();
    
    return node;
}

// Printing a Binary Tree

void printtree(Node * root)
{
    if(root->data == -1)
        return;
    cout<<root->data <<endl;
    if(root->left != NULL)
    {
        //cout<<root->left->data <<endl;
        printtree(root->left);
        
    }
    if(root->right != NULL)
    {
        //cout<<root->right->data <<endl;
        printtree(root->right);
    }
}

// Level order traversal

void levelprint(Node * root)
{
    queue<Node *> q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
    }
}

// Reverse Level order traversal

void Reverselevelprint(Node * root)
{
    queue<Node *> q;
    stack<int> s;
    
    q.push(root);
    q.push(NULL);
    
    
    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        if(temp != NULL)
            s.push(temp->data);
        else
            s.push(-1);
        
        if(temp == NULL)
        {
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if(temp->right)
                q.push(temp->right);
            
            if(temp->left)
                q.push(temp->left);
        }
    }
    
    while(!s.empty())
    {
        
        if(s.top() != -1)
            cout<<s.top()<<" ";
        else
            cout<<endl;
        s.pop();
    }
    
}

// Printing Inorder Traversal

void printinorder(Node * root)
{
    if(root == NULL)
        return;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

// Printing Preorder Traversal

void printpreorder(Node * root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}

// Printing Postorder Traversal

void printpostorder(Node * root)
{
    if(root == NULL)
        return;
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}

// Count Leaves in Binary Tree

int countLeaves(Node* root)
{
  // Your code here
  if(root == NULL)
  return 0;
  
  int ans = 0;
  if(root->left == NULL && root->right == NULL)
  return 1;
  
  ans += countLeaves(root->left);
  ans += countLeaves(root->right);
  
  return ans;
}


