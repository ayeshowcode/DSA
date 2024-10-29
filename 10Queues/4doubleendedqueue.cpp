#include <iostream>
using namespace std;
#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize node with data
    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
    TreeNode *root;

    // Constructor to initialize the root to nullptr
    BinaryTree() : root(nullptr) {}

    // Function to create a binary tree from an array
    void createBinaryTree(int arr[], int size)
    {
        if (size == 0)
            return;

        root = new TreeNode(arr[0]);
        queue<TreeNode *> q;
        q.push(root);

        int i = 1;
        while (i < size)
        {
            TreeNode *current = q.front();
            q.pop();

            // Insert the left child
            if (i < size)
            {
                current->left = new TreeNode(arr[i++]);
                q.push(current->left);
            }

            // Insert the right child
            if (i < size)
            {
                current->right = new TreeNode(arr[i++]);
                q.push(current->right);
            }
        }
    }

    // Function to print the tree in level-order traversal
    void levelOrderTraversal()
    {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    BinaryTree tree;
    tree.createBinaryTree(arr, size);

    cout << "Level-order traversal of the binary tree:" << endl;
    tree.levelOrderTraversal();

    return 0;
}
