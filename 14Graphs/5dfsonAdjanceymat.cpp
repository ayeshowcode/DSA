#include <iostream>
using namespace std;
class Graph
{
private:
    int n;
    int g[10][10];

public:
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
    void displayAdjanceyMat()
    {
        cout << "Adjancey Matrix:" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << endl;
            for (int j = 0; j < 10; j++)
            {
                cout << g[i][j] << " ";
            }
        }
    }
    void addEdge(int x, int y)
    {
        // Check if the vertex exists in the graph
        if (x >= n || y >= n)
        {
            cout << "Vertex does not exist" << endl;
            return;
        }
        // Check if the vertex is connecting to itself
        if (x == y)
        {
            cout << "Cannot add an edge to the same vertex" << endl;
            return;
        }
        // Add the edge
        g[x][y] = 1;
        g[y][x] = 1; // For undirected graph
    }
    void removeEdges(int x, int y)
    {
        // Check if the vertex exists in the graph
        if (x >= n || y >= n)
        {
            cout << "Vertex does not exist" << endl;
            return;
        }
        // Check if the vertex is connecting to itself
        if (x == y)
        {
            cout << "Cannot remove an edge to the same vertex" << endl;
            return;
        }
        // Remove the edge
        g[x][y] = 0;
        g[y][x] = 0; // For undirected graph
    }
    void addVertex()
    {
        n++;
        int i;

        // initializing the new elements to zero
        for (int i = 0; i < n; i++)
        {
            g[i][n - 1] = 0;
            g[n - 1][i] = 0;
        }
    }
    void removeVertex(int x)
    {
        if (x > n)
        {
            cout << "vertex not present " << endl;
            return;
        }
        else
        {
            while (x < n)
            {
                for (int i = 0; i < n; i++)
                    g[i][x] = g[i][x + 1];
                for (int i = 0; i < n; i++)
                    g[x][i] = g[x + 1][i];
            }
            x++;
        }
        n--;
    }
    void dfs(int start, bool *visited)
    {
        cout << start << " ";
        // set the current node as visited
        visited[start] = true;
        // for every node of the graph
        for (int i = 0; i < n; i++)
        {
            // if some node is adjacent to the current node
            // and it has not already been visited
            if (g[start][i] == 1 && !visited[i])
            {
                dfs(i, visited);
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
    g.displayAdjanceyMat();
    cout << endl;

    // Perform DFS traversal
    cout << "\nPerforming DFS traversal starting from vertex 0: ";
    bool visited[10] = {false}; // Initialize visited array
    g.dfs(0, visited);
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
    g.displayAdjanceyMat();
    cout << endl;

    // Remove a vertex
    cout << "\nRemoving vertex 3 from the graph..." << endl;
    g.removeVertex(3);

    // Display the adjacency matrix after removing a vertex
    cout << "\nAdjacency Matrix after removing vertex 3:" << endl;
    g.displayAdjanceyMat();
    cout << endl;

    // Perform DFS traversal again
    cout << "\nPerforming DFS traversal starting from vertex 0 after modifications: ";
    for (int i = 0; i < 10; i++)
        visited[i] = false; // Reset visited array
    g.dfs(0, visited);
    cout << endl;

    return 0;
}