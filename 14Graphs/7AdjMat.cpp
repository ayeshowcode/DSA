#include <iostream>
using namespace std;

class Graph
{
private:
    int n;         // Number of vertices
    int g[10][10]; // Adjacency matrix

public:
    // Constructor
    Graph(int x)
    {
        n = x;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                g[i][j] = 0;
            }
        }
    }

    // Display the adjacency matrix
    void displayAdjacencyMat()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Add an edge between two vertices
    void addEdge(int x, int y)
    {
        if (x >= n || y >= n)
        {
            cout << "Vertex does not exist!" << endl;
            return;
        }
        if (x == y)
        {
            cout << "Cannot add an edge to the same vertex!" << endl;
            return;
        }
        g[x][y] = 1;
        g[y][x] = 1; // For undirected graph
    }

    // Remove an edge between two vertices
    void removeEdges(int x, int y)
    {
        if (x >= n || y >= n)
        {
            cout << "Vertex does not exist!" << endl;
            return;
        }
        if (x == y)
        {
            cout << "Cannot remove an edge to the same vertex!" << endl;
            return;
        }
        g[x][y] = 0;
        g[y][x] = 0; // For undirected graph
    }

    // Add a new vertex
    void addVertex()
    {
        n++;
        for (int i = 0; i < n; i++)
        {
            g[i][n - 1] = 0;
            g[n - 1][i] = 0;
        }
    }

    // Remove a vertex
    void removeVertex(int x)
    {
        if (x >= n)
        {
            cout << "Vertex not present!" << endl;
            return;
        }
        for (int i = x; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
                g[j][i] = g[j][i + 1];
            for (int j = 0; j < n; j++)
                g[i][j] = g[i + 1][j];
        }
        n--;
    }

    // Depth First Search (DFS)
    void dfs(int start, bool *visited)
    {
        cout << start << " ";
        visited[start] = true;

        for (int i = 0; i < n; i++)
        {
            if (g[start][i] == 1 && !visited[i])
            {
                dfs(i, visited);
            }
        }
    }

    // Breadth First Search (BFS) with custom queue
    void bfs(int start)
    {
        bool visited[10] = {false}; // Keep track of visited nodes
        int queue[10];              // Custom queue implemented as an array
        int front = 0, rear = 0;    // Front and rear pointers for the queue

        // Start BFS from the starting node
        visited[start] = true;
        queue[rear++] = start; // Enqueue the starting node

        while (front < rear) // While the queue is not empty
        {
            int current = queue[front++]; // Dequeue a vertex
            cout << current << " ";

            // Traverse all adjacent vertices
            for (int i = 0; i < n; i++)
            {
                if (g[current][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    queue[rear++] = i; // Enqueue the vertex
                }
            }
        }
    }
};

int main()
{
    cout << "Creating a graph with 5 vertices..." << endl;
    Graph g(5);

    // Add edges to the graph
    cout << "Adding edges to the graph:" << endl;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Display the adjacency matrix
    cout << "\nAdjacency Matrix after adding edges:" << endl;
    g.displayAdjacencyMat();

    // Perform DFS traversal
    cout << "\nPerforming DFS traversal starting from vertex 0: ";
    bool visited[10] = {false};
    g.dfs(0, visited);
    cout << endl;

    // Perform BFS traversal
    cout << "\nPerforming BFS traversal starting from vertex 0: ";
    g.bfs(0);
    cout << endl;

    // Add a new vertex
    cout << "\nAdding a new vertex to the graph..." << endl;
    g.addVertex();

    // Add edges for the new vertex
    cout << "Adding edges for the new vertex (vertex 5):" << endl;
    g.addEdge(5, 2);
    g.addEdge(5, 4);

    // Display the adjacency matrix after adding the new vertex
    cout << "\nAdjacency Matrix after adding a new vertex and edges:" << endl;
    g.displayAdjacencyMat();

    // Remove a vertex
    cout << "\nRemoving vertex 3 from the graph..." << endl;
    g.removeVertex(3);

    // Display the adjacency matrix after removing a vertex
    cout << "\nAdjacency Matrix after removing vertex 3:" << endl;
    g.displayAdjacencyMat();

    // Perform DFS traversal again
    cout << "\nPerforming DFS traversal starting from vertex 0 after modifications: ";
    for (int i = 0; i < 10; i++)
        visited[i] = false; // Reset visited array
    g.dfs(0, visited);
    cout << endl;

    // Perform BFS traversal again
    cout << "\nPerforming BFS traversal starting from vertex 0 after modifications: ";
    g.bfs(0);
    cout << endl;

    return 0;
}