#include "BST.h"
#include <queue>

BST::BST()
{
}

Node *BST::getRoot()
{
    /*
    Return root of your tree here.
    */
    return head;
    //throw - 1; // TODO: remove this line
}

void BST::add(int value)
{
    /*
    Add `value` into the BST tree.
    If node with `value` exists, throw -2 
    */
    Node *tmp = head;
    while(tmp->val != value)
    {
        if(value < tmp->val)
        {
            if(tmp->left != nullptr)
            {
                tmp = tmp->left;
            }
            else
            {
                tmp->left = new Node(value);
                return;
            }
        }
        else if(value > tmp->val)
        {
            if(tmp->right != nullptr)
            {
                tmp = tmp->right;
            }
            else
            {
                tmp->right = new Node(value);
                return;
            }
        }
    }
    throw -2;
}

bool BST::eachInternalNodeHasOneChild()
{
    /*
    Check if every internal node has one child.
    Internal node if node that is not a leaf.
    Return true if each internal node has one child
    otherwise return false
    */
    Node *tmp = head;
    while (tmp->left != nullptr || tmp->right != nullptr)
    {
        if(tmp->left != nullptr && tmp->right != nullptr)
        {
            return false;
        }
        if(tmp->left)
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }
    return true;
    //throw - 1; // TODO: remove this line
}

Node *BST::lowestCommonAncestor(int value1, int value2)
{
    /*
    Find lowest common ancestor of values `value1` and `value2`
    Assume both values exist in the tree
    Returns node being the lowest common ancestor, in other words
    return the smallest subtree containing both values
    */
    Node *tmp = head;
    while(true)
    {
        if(subSearch(value1, tmp->left) && subSearch(value2, tmp->left))//if true the both values are on the left
        {
            tmp = tmp->left;
        }
        else if(subSearch(value1, tmp->right) && subSearch(value2, tmp->right))//if true the both values are on the right
        {
            tmp = tmp->right;
        }
        else//if they are in different branches
        {
            return tmp;
        }
    }

    //throw - 1; // TODO: remove this line
}

Node *BST::largestLessOrEqual(int value)
{
    /*
    Return such node that its value is the biggest 
    value smaller than parameter `value`.
    You can assume this node exists.
    */

    Node *tmp = head;
    while(tmp)
    {
        if(value > tmp->val)
        {
            if(tmp->right)
            {
                tmp = tmp->right;
            }
            else
            {
                return tmp;
            }
        }
        else if(value < tmp->val)
        {
            tmp = tmp->left;
        }
        else if(value == tmp->val)
        {
            tmp = tmp->left;
            while(tmp->right)
            {
                tmp = tmp->right;
            }
            return tmp;
        }
    }

    //throw - 1; // TODO: remove this line
}

BST::~BST()
{
    Node *root = getRoot();
    queue<Node *> myqueue;
    myqueue.push(root);

    while (!myqueue.empty())
    {
        Node *node = myqueue.front();
        myqueue.pop();

        if (node->left)
            myqueue.push(node->left);
        if (node->right)
            myqueue.push(node->right);
        delete node;
    }
}

//

Node* BST::search(int value)
{
    Node *tmp = head;
    while(value != tmp->val)
    {
        if(value < tmp->val)
        {
            tmp = tmp->left;
        }
        else if(value > tmp->val)
        {
            tmp = tmp->right;
        }
        else
        {
            return nullptr;
        }
    }
    return tmp;
}

Node* BST::subSearch(int value, Node *root)
{
    Node *tmp = head;
    while(value != tmp->val)
    {
        if(value < tmp->val)
        {
            tmp = tmp->left;
        }
        else if(value > tmp->val)
        {
            tmp = tmp->right;
        }
        else
        {
            return nullptr;
        }
    }
    return tmp;
}
