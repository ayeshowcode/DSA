#include <iostream>
using namespace std;
struct Node
{
    int key;
    int index;
    Node *next;

    Node(int key, int index) : key(key), index(index), next(NULL) {}
};
class Hash
{
    int BUCKET;
    int numOfElements;
    Node **table;

public:
    Hash(int b)
    {
        BUCKET = b;
        numOfElements = 0;
        table = new Node *[BUCKET];

        for (int i = 0; i < BUCKET; i++)
        {
            table[i] = NULL;
        }
    }
    int hashFunction(int key)
    {
        return key % BUCKET;
    }
    float getLoadFactor()
    {
        return (float)numOfElements / BUCKET;
    }
    void insert(int key, int index)
    {
        // rehash if needed
        while (getLoadFactor() > 0.5)
        {
            // call rehashing
        }
        int hashIndex = hashFunction(key);
        // create a new Node for the key
        Node *newNode = new Node(key, index);

        newNode->next = table[hashIndex];
        table[hashIndex] = newNode;
        numOfElements++;
    }
    void deleteItem(int key)
    {
        int index = hashFunction(key);

        Node *current = table[index];
        Node *prev = NULL;

        // traverse the chain to find the key
        while (current != NULL && current->key != key)
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
            return;

        if (prev == NULL)
            table[index] = current->next;
        else
            prev->next = current->next;
        delete current;
        numOfElements--;
    }
    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << i << " ";
            Node *current = table[i];
            while (current != NULL)
            {
                cout << "-->" << current->key << " (index: " << current->index << ")";
                current = current->next;
            }
            cout << endl;
        }
    }
    void Rehashing()
    {
        int oldBucket = BUCKET;
        BUCKET = 2 * BUCKET;

        Node **oldTable = table;

        table = new Node *[BUCKET];

        for (int i = 0; i < BUCKET; i++)
        {
            Node *current = table[i];
            while (current != NULL)
            {
                insert(current->key, current->index);
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
    Node *search(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];

        while (current != NULL)
        {
            if (current->key == key)
                return current;
            current = current->next;
        }
        return NULL;
    }
    void clearHashTable()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            Node *current = table[i];
            while (current != NULL)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = NULL;
        }
        numOfElements = 0;
    }
    bool twoSum(int start, int n, int k, int *arr)
    {
        clearHashTable();
        // insert first index
        insert(arr[start], start);

        for(int i = start+1; i< n; i++)
        {
            int diff = k - arr[i];
            Node* complementNode = search(diff);

            if(complementNode!=NULL)
            {
                cout << "pair found: (" << arr[i] << ", " << diff << ")" << endl;
                return true;
            }
            if(search(arr[i]) == NULL)insert(arr[i], i);
        }
        return false;
    }
    bool threeSum(int n, int *arr)
    {
        for(int i = 0; i< n-2; i++)
        {
            int target = -arr[i];
            cout << "checking for target: " << target << "with element " << arr[i] << endl;

            if(twoSum(i+1, n, target, arr))
            {
                cout << "Triplet found with first element: " << arr[i] << endl;
                return true;
            }
        }
        return false;
    }
};
int main()
{
}