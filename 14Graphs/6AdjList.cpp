#include <iostream>
using namespace std;

class adjNode
{
public:
    int vertex;
    adjNode *next;
    adjNode(int v) : vertex(v), next(NULL) {}
};

class AdjList
{
private:
    int v;           // Number of vertices
    adjNode **graph; // Array of adjacency lists

public:
    // Constructor
    AdjList(int vertices)
    {
        v = vertices;
        graph = new adjNode *[v];
        for (int i = 0; i < v; i++)
            graph[i] = NULL;
    }

    // Add an edge
    void addEdge(int source, int destination)
    {
        // Add edge from source to destination
        adjNode *newNode = new adjNode(destination);
        newNode->next = graph[source];
        graph[source] = newNode;

        // Add edge from destination to source (for undirected graph)
        newNode = new adjNode(source);
        newNode->next = graph[destination];
        graph[destination] = newNode;
    }

    // Delete an edge
    void deleteEdge(int source, int destination)
    {
        // Remove edge from source to destination
        adjNode *temp = graph[source];
        adjNode *prev = NULL;

        while (temp != NULL && temp->vertex != destination)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            if (prev == NULL)
                graph[source] = temp->next;
            else
                prev->next = temp->next;
            delete temp;
        }

        // Remove edge from destination to source
        temp = graph[destination];
        prev = NULL;

        while (temp != NULL && temp->vertex != source)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            if (prev == NULL)
                graph[destination] = temp->next;
            else
                prev->next = temp->next;
            delete temp;
        }
    }

    // Print the graph
    void printGraph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << ": ";
            adjNode *temp = graph[i];
            while (temp != NULL)
            {
                cout << "--> " << temp->vertex;
                temp = temp->next;
            }
            cout << endl; // Add a newline after each vertex list
        }
    }

    // DFS Traversal
    void dfs(int vertex, bool *visited)
    {
        cout << vertex << " ";
        visited[vertex] = true;

        // Traverse all neighbors
        adjNode *temp = graph[vertex];
        while (temp != NULL)
        {
            if (!visited[temp->vertex])
                dfs(temp->vertex, visited);
            temp = temp->next;
        }
    }

    // BFS Traversal
    void bfs(int start)
    {
        // Custom queue implementation
        int queue[100];          // Static array to act as a queue
        int front = 0, rear = 0; // Pointers to front and rear of the queue

        bool *visited = new bool[v](); // Visited array

        // Start BFS from the starting node
        visited[start] = true;
        queue[rear++] = start; // Enqueue the starting node

        while (front < rear)
        {                                 // While queue is not empty
            int current = queue[front++]; // Dequeue
            cout << current << " ";

            // Traverse neighbors
            adjNode *temp = graph[current];
            while (temp)
            {
                if (!visited[temp->vertex])
                {
                    visited[temp->vertex] = true;
                    queue[rear++] = temp->vertex; // Enqueue
                }
                temp = temp->next;
            }
        }
        delete[] visited;
    }

    // Destructor to free memory
    ~AdjList()
    {
        for (int i = 0; i < v; i++)
        {
            adjNode *temp = graph[i];
            while (temp != NULL)
            {
                adjNode *next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] graph;
    }
};

int main()
{
    // Create a graph with 5 vertices
    AdjList graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    // Print the graph
    cout << "Graph representation (Adjacency List):" << endl;
    graph.printGraph();

    // Perform DFS
    cout << "\nDFS traversal starting from vertex 0: ";
    bool visited[5] = {false};
    graph.dfs(0, visited);

    // Perform BFS
    cout << "\n\nBFS traversal starting from vertex 0: ";
    graph.bfs(0);

    // Delete an edge
    cout << "\n\nDeleting edge (1, 3)..." << endl;
    graph.deleteEdge(1, 3);

    // Print the graph after deleting the edge
    cout << "Graph representation after deleting edge (1, 3):" << endl;
    graph.printGraph();

    return 0;
}