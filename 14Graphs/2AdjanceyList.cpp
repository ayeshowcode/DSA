#include <iostream>
using namespace std;

// Structure to represent a node in the adjacency list
struct Node
{
    int vertex;
    Node *next;
};

// Function to add an edge between two vertices
void addEdge(Node **adj, int i, int j)
{
    // Create a new node for vertex j and add it to the list for vertex i
    Node *newNode = new Node; // Dynamically allocate memory for the new node
    newNode->vertex = j;      // Set the vertex value
    newNode->next = adj[i];   // Point to the current head of the list for vertex i
    adj[i] = newNode;         // Update the head of the list for vertex i

    // Since the graph is undirected, do the same for vertex j
    newNode = new Node;     // Create another new node
    newNode->vertex = i;    // Set the vertex value
    newNode->next = adj[j]; // Point to the current head of the list for vertex j
    adj[j] = newNode;       // Update the head of the list for vertex j
}

// Function to display the adjacency list
void displayAdjList(Node **adj, int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << ": "; // Print the vertex
        Node *temp = adj[i];
        while (temp != nullptr)
        {
            cout << temp->vertex << " "; // Print its adjacent vertices
            temp = temp->next;           // Move to the next node
        }
        cout << endl;
    }
}

// Function to delete all dynamically allocated memory
void freeMemory(Node **adj, int V)
{
    for (int i = 0; i < V; i++)
    {
        Node *temp = adj[i];
        while (temp != nullptr)
        {
            Node *toDelete = temp;
            temp = temp->next;
            delete toDelete; // Free each node in the list
        }
    }
    delete[] adj; // Free the array of pointers
}

// Main function
int main()
{
    int V = 4; // Number of vertices

    // Dynamically allocate memory for the adjacency list
    Node **adj = new Node *[V]; // Create an array of pointers
    for (int i = 0; i < V; i++)
    {
        adj[i] = nullptr; // Initialize all pointers to nullptr
    }

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    // Display the adjacency list
    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj, V);

    // Free allocated memory
    freeMemory(adj, V);

    return 0;
}