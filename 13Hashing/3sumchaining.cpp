#include <iostream>
using namespace std;
class Node
{
public:
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
    int hashFunction(int x) { return x % BUCKET; }
    float getLoadFactor() { return (float)numOfElements / BUCKET; }
    void insertItem(int key)
    {
        // check the load factor if greater than 0.5 rehash
        while (getLoadFactor() > 0.5)
        {
            rehashing();
        }
        // calculate index using hashfunction
        int index = hashFunction(key);
        // create a new node
        Node *newNode = new Node(key);
        // insert the new node
        newNode->next = table[index];
        table[index] = newNode;
        // incerement the no of elements
        numOfElements++;
    }
    void deleteItem(int key)
    {
        // calculate the index using hashfunction
        int index = hashFunction(key);

        // creating a new node
        Node *current = table[index];
        Node *prev = NULL;

        // use a while loop to traverse the linked list at table[index]
        while (current != NULL)
        {
            prev = current;
            current = current->next;
        }
        // key not found
        if (current == NULL)
            return;

        // delete the node
        // if first node
        if (prev == NULL)
            table[index] = current->next;

        // if not the first node
        else
            prev->next = current->next;
        // delete
        delete current;
        // decrement the no of elements
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
                cout << "--> " << current->key;
                current = current->next;
            }
            cout << endl;
        }
    }
    void rehashing()
    {
        // save the current size of the hash table(old Bucket) and the current table (old table) for later use
        int oldBucket = BUCKET;
        Node **oldtable = table;

        // double the size of the hash table
        BUCKET = 2 * BUCKET;

        // create a new table with the updated size and initialize all buckets to NULL
        table = new Node *[BUCKET];
        for (int i = 0; i < BUCKET; i++)
        {
            table[i] = NULL;
        }
        // reset the no of elements to zero
        numOfElements = 0;

        // traverse through each bucket in the old table
        for (int i = 0; i < oldBucket; i++)
        {
            Node *current = oldtable[i];
            while (current != NULL)
            {
                // reinsert the key into the table
                insertItem(current->key);
                // mov to the next node
                Node *temp = current;
                current = current->next;
                // free the old node
                delete temp;
            }
        }
    }
    Node *search(int key)
    {
        // compute the hash Function
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

    void clearTable()
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
    }
    bool twoSum(int start, int n, int target, int *arr)
    {
        // clear hashtable before starting
        clearTable();

        for (int i = start; i < n; i++)
        {
            int diff = target - arr[i]; // calculate the complement

            // check if the complement exists in the hashtable
            Node *complementNode = search(diff);
            if (complementNode != NULL)
            {
                cout << "pair found: (" << arr[i] << ", " << diff << ")" << endl;
            }
            // insert item
            insertItem(arr[i]);
        }
        return false;
    }
    bool threeSum(int n, int *arr)
    {
        for (int i = 0; i < n - 2; i++)
        {
            int target = -arr[i];
            if (twoSum(i + 1, n, target, arr))
            {
                cout << "triplet found with first element " << arr[i] << endl;
                return true;
            }
        }
        return false;
    }
};

// Function to match nuts and bolts using the Hash class
void nutboltmatch(char nuts[], char bolts[], int n)
{
    // Create a Hash object with enough buckets
    Hash hashTable(10);

    // Insert all nuts into the hash table
    for (int i = 0; i < n; i++)
    {
        hashTable.insertItem(nuts[i]);
    }

    // Match bolts with nuts using the hash table
    for (int i = 0; i < n; i++)
    {
        if (hashTable.search(bolts[i]) != NULL)
        {
            nuts[i] = bolts[i]; // Assign the matched bolt to the nut
        }
    }

    // Display the matched nuts and bolts
    cout << "Matched nuts and bolts are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nuts[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << bolts[i] << " ";
    }
    cout << endl;
}
int main()
{
    // Example nuts and bolts
    char nuts[] = {'@', '#', '$', '%', '^', '&'};
    char bolts[] = {'$', '%', '&', '^', '@', '#'};
    int n = sizeof(nuts) / sizeof(nuts[0]);

    // Match nuts and bolts
    nutboltmatch(nuts, bolts, n);
}