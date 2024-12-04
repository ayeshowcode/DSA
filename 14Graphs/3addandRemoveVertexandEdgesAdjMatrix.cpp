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
        // check if the vertex exists in the graph
        if (x >= n || y >= n)
        {
            cout << "vertex doesnot exist" << endl;
        }
        // check if the vertex is connecting to itself
        if (x == y)
            cout << "same vertex" << endl;
        else
        {
            g[x][y] = 0;
            g[y][x] = 0;
        }
    }
    void removeEdges(int x, int y)
    {
        // check if the vertex exists in the graph
        if (x >= n || y >= n)
        {
            cout << "vertex doesnot exist" << endl;
        }
        // check if the vertex is connecting to itself
        if (x == y)
            cout << "same vertex" << endl;
        else
        {
            g[x][y] = 1;
            g[y][x] = 1;
        }
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
};
int main()
{
}