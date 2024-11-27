#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *lchild, *rchild;
    Node(int key) : key(key), lchild(NULL), rchild(NULL) {}
};

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return new Node(key);
    if (node->key > key)
        node->lchild = insert(node->lchild, key);
    else
        node->rchild = insert(node->rchild, key);
    return node;
}
Node *findMin(Node *node)
{
    while (node && node->lchild)
        node = node->lchild;
    return node;
}
Node *deleteNode(Node *node, int key)
{
    if (node == NULL)
        return node;
    if (node->key == key)
    {
        if (node->lchild == NULL)
        {
            Node *temp = node->rchild;
            delete node;
            return temp;
        }
        if (node->rchild == NULL)
        {
            Node *temp = node->lchild;
            delete node;
            return temp;
        }
        else
        {
            Node *temp = findMin(node->rchild);
            node->key = temp->key;
            node->rchild = deleteNode(node->rchild, temp->key);
        }
    }
    else
    {
        if (node->key > key)
            node->lchild = deleteNode(node->lchild, key);
        if (node->key < key)
            node->rchild = deleteNode(node->rchild, key);
    }
}
int MinValue(Node *root)
{
    if (root == NULL)
        return -1; 
    Node *curr = root;
    while (curr->lchild)
        curr = curr->lchild;
    return curr ? curr->key : -1;
}
int maxValue(Node *root)
{
    if (root == NULL)
        return -1;
    Node *curr = root;
    while (curr->rchild)
        curr = curr->rchild;
    return curr ? curr->key : -1;
}
Node *saerch(Node *node, int key)
{
    if (node == NULL || node->key == key)
    return node;
    if (node->key < key)
        return saerch(node->rchild, key);
    return saerch(node->lchild, key);
}
int findFloor(Node *node, int key)
{
    int floor = -1;
    if (node == NULL)
        return -1;
    if (node->key == key)
        return node->key;

    if (node->key > key)
        findFloor(node->lchild, key);
    floor = findFloor(node->rchild, key);

    if (floor <= key && floor != -1)
        return floor;
}
int findCeil(Node *node, int key)
{
    int ceil = -1;
    if (node == NULL)
        return -1;
    if (node->key == key)
        return node->key;
    if (node->key < key)
        findCeil(node->rchild, key);

    ceil = findCeil(node->lchild, key);

    if (ceil >= key && ceil != -1)
        return ceil;
}
int maxDepth(Node *node)
{
    if (node)
        return max(maxDepth(node->lchild), maxDepth(node->rchild));
}
void printCurrentLevel(Node *node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        cout << node->key;
    else if (level > 1)
    {
        printCurrentLevel(node->lchild, level - 1);
        printCurrentLevel(node->rchild, level - 1);
    }
}
void levelOrderTraversal(Node *node)
{
    int height = maxDepth(node);
    for (int i = 1; i <= height; i++)
        printCurrentLevel(node, i);
}
bool isFull(Node *root)
{
    if (root)
        return true;
    if (!root->lchild && !root->rchild)
        return true;
    if (root->lchild && root->rchild)
        return isFull(root->lchild) && isFull(root->rchild);
    return false;
}
bool isComplete(Node *root, int index, int nodeCount)
{
    if (root == NULL)
        return true;
    if (index > nodeCount)
        return false;
    return isComplete(root->lchild, 2 * index + 1, nodeCount) && isComplete(root->rchild, 2 * index + 2, nodeCount);
}
Node *mirror(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *left = mirror(root->lchild);
    Node *right = mirror(root->rchild);

    root->lchild = right;
    root->rchild = left;

    return root;
}
// Function to find the minimum node in a BST
Node *findMin(Node *node)
{
    if (node == nullptr)
        return nullptr;

    while (node->lchild)
        node = node->lchild;

    return node;
}

// Function to find the maximum node in a BST
Node *findMax(Node *node)
{
    if (node == nullptr)
        return nullptr;

    while (node->rchild)
        node = node->rchild;

    return node;
}

// Recursive function to find the predecessor of a given key
Node *findPredecessor(Node *root, Node *&predecessor, int key)
{
    if (root == nullptr)
        return nullptr;

    if (root->key == key)
    {
        if (root->lchild)
        {
            predecessor = findMax(root->lchild);
        }
    }
    else if (key < root->key)
    {
        findPredecessor(root->lchild, predecessor, key);
    }
    else
    {
        predecessor = root;
        findPredecessor(root->rchild, predecessor, key);
    }
    return predecessor;
}

// Recursive function to find the successor of a given key
Node *findSuccessor(Node *root, Node *&successor, int key)
{
    if (root == nullptr)
        return nullptr;

    if (root->key == key)
    {
        if (root->rchild)
        {
            successor = findMin(root->rchild);
        }
    }
    else if (key < root->key)
    {
        successor = root;
        findSuccessor(root->lchild, successor, key);
    }
    else
    {
        findSuccessor(root->rchild, successor, key);
    }
    return successor;
}
int main()
{
}