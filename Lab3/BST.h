#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val = 404) : val(val), left(NULL), right(NULL) {}
};

struct MinMaxNode
{
    Node *minNode;
    Node *maxNode;
    MinMaxNode(Node *minNode = NULL, Node *maxNode = NULL) : minNode(minNode), maxNode(maxNode) {}
    bool operator==(const MinMaxNode &a) const
    {
        return a.minNode->val == this->minNode->val && a.maxNode->val == this->maxNode->val;
    }
};

class BST
{
  private:
    Node *head;

  public:
    BST();
    Node *getRoot();
    void add(int value);
    Node *search(int value);
    MinMaxNode findMinMaxNode();
    Node *secondLargestElement();
    ~BST();
    bool eachInternalNodeHasOneChild();
    Node *lowestCommonAncestor(int value1, int value2);
    Node *largestLessOrEqual(int value);
    Node* subSearch(int value, Node *root);
};
