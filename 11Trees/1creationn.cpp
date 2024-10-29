#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Node
{
public:
    int key;
    string name;
    Node *left;
    Node *right;

    Node(int key, string name)
    {
        this->key = key;
        this->name = name;
        left = NULL;
        right = NULL;
    }

    string getString(int key)
    {
        // return (name + " has the key " + to_string(key));
        return (name + " has the key " + to_string(key) + " \n");
    }
};

class BinaryTree
{
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    void addNode(int key, string name)
    {
        Node *newNode = new Node(key, name);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *current = root;
            Node *parent;
            while (true)
            {
                parent = current;
                if (key < current->key)
                {
                    current = current->left;
                    if (current == NULL)
                    {
                        parent->left = newNode;
                        return;
                    }
                }
                else
                {
                    current = current->right;
                    if (current == NULL)
                    {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    void printTree(Node *node)
    {
        if (node != NULL)
        {
            printTree(node->left);
            cout << node->getString(node->key);
            printTree(node->right);
        }
    }
    void printTree()
    {
        printTree(root);
    }
};

int main()
{
    BinaryTree tree;
    tree.addNode(1, "Node 1");
    tree.addNode(2, "Node 2");
    tree.addNode(3, "Node 3");
    tree.addNode(4, "Node 4");
    tree.addNode(5, "Node 5");

    tree.printTree();

    return 0;
}