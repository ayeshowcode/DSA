#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int value;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};
class HashMap
{
private:
    Node **arr;
    int capacity;
    int size;
    Node *dummy;

public:
    HashMap()
    {
        capacity = 20;              // initial capacity of the hashtable
        size = 0;                   // initially the hashtable is empty
        arr = new Node *[capacity]; // array of pointers to nodes

        // initialize all the slots with NULL
        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;
        // creating the dummy node for marking the deleted elements
        dummy = new Node(-1, -1);
    }
    // hash function to find the index of the key
    int hashFunction(int key)
    {
        return key % capacity;
    }
    // insert the key value pair into the hashtable
    void insert(int key, int value)
    {
        // craeate a new node with the given key and value
        Node *temp = new Node(key, value);

        // compute the hash index
        int hashIndex = hashFunction(key);

        // Linear probing
        // three conditions to insert the key value pair
        // 1. the slot is empty
        // 2. the slot has the same key as the key to be inserted
        // 3. the slot has the dummy node

        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex = hashIndex % capacity;
        }

        // insert
        // two conditions to insert the key value pair
        // 1. the slot is empty
        // 2. the slot has the dummy node
        if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
        {
            size++;
        }
        arr[hashIndex] = temp;
    }
    int deleteNode(int key)
    {
        // compute the hash index
        int hashIndex = hashFunction(key);
        // Search the key in the hashtable
        while (arr[hashIndex] != NULL)
        {
            // if the key is found
            if (arr[hashIndex]->key == key)
            {
                Node *temp = arr[hashIndex];
                arr[hashIndex] = dummy;
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex = hashIndex % capacity;
        }
        // if the key is not found
        return -1;
    }
    int search(int key)
    {
        // compute the hash function
        int hashIndex = hashFunction(key);
        int counter = 0;

        // search for the key
        while (arr[hashIndex] != NULL)
        {
            // Avoid infinite loop
            if (counter++ > capacity)
            {
                return -1;
            }
            if (arr[hashIndex]->key == key)
            {
                return arr[hashIndex]->value;
            }
            hashIndex++;
            hashIndex = hashIndex % capacity;
        }
        return -1;
    }
    int sizeofMap()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (arr[i] != NULL && arr[i]->key != -1)
            {
                cout << "key = " << arr[i]->key << "value " << arr[i]->value << endl;
            }
        }
    }
};
int main()
{
    HashMap h;

    // Insert key-value pairs
    h.insert(1, 1);
    h.insert(2, 2);
    h.insert(3, 3);

    // Display the hash table
    h.display();

    // Search for a key
    cout << "Value for key 2: " << h.search(2) << endl;

    // Delete a key-value pair
    cout << "Deleted value for key 2: " << h.deleteNode(2) << endl;

    // Display the hash table after deletion
    h.display();

    // Check if the table is empty
    cout << "Is hash table empty? " << (h.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}