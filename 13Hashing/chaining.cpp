#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *next;

    Node(int key) : key(key), next(NULL) {}
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
    int hashFunction(int x)
    {
        return x % BUCKET;
    }
    float getLoadFactor()
    {
        return (float)numOfElements / BUCKET;
    }
    void insertItem(int key)
    {
        // rehash if load factors exceeds 0.5
        while (getLoadFactor() > 0.5)
        {
            rehashing();
        }
        // computer the bucket index
        int index = hashFunction(key);

        // create a new Node for the key
        Node *newNode = new Node(key);

        // insert the new node at the head of the chain
        newNode->next = table[index];
        table[index] = newNode;

        numOfElements++;
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        // start at the head of chain
        Node *current = table[index];
        Node *prev = NULL;

        // Traverse the chain to find the key
        while (current != NULL && current->key != key)
        {
            prev = current;
            current = current->next;
        }
        // key not found
        if (current == NULL)
        {
            return;
        }
        // key found remove the node
        if (prev == NULL)
        {
            // key is at the head of the chain
            table[index] = current->next;
        }
        else
        {
            // key is in the middle or end of the chain
            prev->next = current->next;
        }
        delete current;
        numOfElements--;
    }
    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << i;
            Node *current = table[i];
            while (current != NULL)
            {
                cout << " --> " << current->key;
                current = current->next;
            }
            cout << endl;
        }
    }
    void rehashing()
    {
        int oldBucket = BUCKET;
        BUCKET = 2 * BUCKET; // double the no of buckets

        Node **oldTable = table;

        table = new Node *[BUCKET];
        for (int i = 0; i < BUCKET; i++)
        {
            table[i] = NULL;
        }
        numOfElements = 0; // Reset the elements count

        // Reinsert all keys from the old table into the new table
        for (int i = 0; i < oldBucket; i++)
        {
            Node *current = oldTable[i];
            while (current != NULL)
            {
                insertItem(current->key);
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
    bool searchItem(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];

        while (current != NULL)
        {
            if (current->key == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};
int main()
{
    int bucketSize;
    cout << "Enter the initial number of buckets: ";
    cin >> bucketSize;

    // Create a hash table with the given bucket size
    Hash hashTable(bucketSize);

    int choice, key;

    while (true)
    {
        cout << "\nHash Table Menu:\n";
        cout << "1. Insert Item\n";
        cout << "2. Delete Item\n";
        cout << "3. Search Item\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Insert an item
            cout << "Enter the key to insert: ";
            cin >> key;
            hashTable.insertItem(key);
            cout << "Key " << key << " inserted successfully.\n";
            break;

        case 2: // Delete an item
            cout << "Enter the key to delete: ";
            cin >> key;
            hashTable.deleteItem(key);
            cout << "Key " << key << " deleted successfully (if it existed).\n";
            break;

        case 3: // Search for an item
            cout << "Enter the key to search: ";
            cin >> key;
            if (hashTable.searchItem(key))
                cout << "Key " << key << " found in the hash table.\n";
            else
                cout << "Key " << key << " not found in the hash table.\n";
            break;

        case 4: // Display the hash table
            cout << "Hash Table:\n";
            hashTable.displayHash();
            break;

        case 5: // Exit
            cout << "Exiting the program. Goodbye!\n";
            exit(0);
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}