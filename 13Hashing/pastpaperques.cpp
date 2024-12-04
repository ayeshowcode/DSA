// a movie streaming platform tracks movie ratings submitted by users on a scale of 1 to 5. The platform wants to display the ratings in an ordered way based on their frequency.
//      1. use a hashtable to count the no of ratings for each score(1-5)
//      2. resize and rehash when the load factor exceeds 0.7
// Sort the ratings based on their frequency in descending order using merge sort. if two ratings have the same frequency, sort them by rating value in descending order
// input example:
// Ratings: 5,4,3,5,5,4,2,4,5,3,3,3
// output:
// sorting ratings
// 1. 5: 4 occurence
// 2. 3: 4 occurence
// 3. 4: 3 occurence
// 4. 2: 1 occurence

#include <iostream>
using namespace std;
class Node
{
public:
    int key;       // rating(value: 1-5
    int frequency; // frequency of the rating
    Node *next;

    Node(int key, int frequency) : key(key), frequency(frequency) {}
};
class HashTable
{
    int BUCKET;
    int numOfElements;
    Node **table;

public:
    HashTable(int b)
    {
        BUCKET = b;
        numOfElements = 0;
        table = new Node *[BUCKET];
        for (int i = 0; i < BUCKET; i++)
            table[i] = NULL;
    }
    int hashFunction(int key)
    {
        return key % BUCKET;
    }
    float getLoadFactor()
    {
        return (float)numOfElements / BUCKET;
    }
    void insert(int key)
    {
        while (getLoadFactor() > 0.7)
            rehash();
        int index = hashFunction(key);
        Node *current = table[index];

        // search for the key in the chain
        while (current != NULL)
        {
            if (current->key == key)
            {
                current->frequency++;
                return;
            }
            // if key not found, create a new node and insert it
            Node *newNode = new Node(key, 1);
            newNode->next = table[index];
            table[index] = newNode;
            numOfElements++;
        }
    }
    void rehash()
    {
        int oldBUCKET = BUCKET;
        Node **oldTable = table;

        BUCKET = 2 * BUCKET;
        table = new Node *[BUCKET];
        numOfElements = 0;

        // reinsert
        for (int i = 0; i < oldBUCKET; i++)
        {
            Node *current = oldTable[i];
            while (current != NULL)
            {
                for (int j = 0; j < current->frequency; j++)
                {
                    insert(current->key);
                }
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] oldTable;
    }
    void getKeyFrequencyPairs(int pairs[][2], int &size)
    {
        size = 0;
        for (int i = 0; i < BUCKET; i++)
        {
            Node *current = table[i];
            while (current != NULL)
            {
                pairs[size][0] = current->key;
                pairs[size][1] = current->frequency;
                size++;
                current = current->next;
            }
        }
    }
    void merge(int arr[][2], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1][2], rightArr[n2][2];
        for (int i = 0; i < n1; i++)
        {
            leftArr[i][0] = arr[left + i][0];
            leftArr[i][1] = arr[left + i][1];
        }
        for (int j = 0; j < n2; j++)
        {
            rightArr[j][0] = arr[mid + 1 + i][0];
            rightArr[j][1] = arr[mid + 1 + i][1];
        }

        int i = 0, j = 0;
        int k = left;

        while (i < n1 && j < n2)
        {
            // sort primarily by frequency (descending)
            // if frequency is same sort by key
            if (leftArr[i][1] > rightArr[j][1] || (leftArr[i][1] == rightArr[j][1] && leftArr[i][0] > rightArr[j][0]))
            {
                arr[k][0] = leftArr[i][0];
                arr[k][1] = leftArr[i][1];
                i++;
            }
            else
            {
                arr[k][0] = rightArr[j][0];
                arr[k][1] = rightArr[j][1];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k][0] = leftArr[i][0];
            arr[k][1] = leftArr[i][1];
            i++;
            j++;
        }
        k++;
        while (j < n2)
        {
            arr[k][0] = rightArr[j][0];
            arr[k][1] = rightArr[j][1];
            j++;
            k++;
        }
    }
    void mergeSort(int arr[][2], int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);

            merge(arr, left, mid, right);
        }
    }
};
int main()
{
}