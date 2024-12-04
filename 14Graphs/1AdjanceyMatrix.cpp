// C++ program to demonstrate Adjacency Matrix
// representation of an undirected and unweighted graph
#include <iostream>
using namespace std;

void addEdge(int mat[][4], int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

void displayMatrix(int mat[][4], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    // Create a graph with 4 vertices and no edges
    // Note that all values are initialized as 0
    const int V = 4;
    int mat[V][V] = {0}; // Initialize all elements to 0

    // Now add edges one by one
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    /* Alternatively, we can also create the matrix directly
       if we know all edges in advance:

       int mat[V][V] = {{ 0, 1, 0, 0 },
                        { 1, 0, 1, 0 },
                        { 0, 1, 0, 1 },
                        { 0, 0, 1, 0 }};
    */

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat, V);

    return 0;
}