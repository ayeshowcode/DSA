// BACKTRACKING

#include <iostream>
using namespace std;
void pathwithObstacles(string p, bool *maze[], int r, int c, int dim, int *path[], int step)
{
    if (r == dim - 1 && c == dim - 1)
    {
        path[r][c]=step;
        for(int i = 0; i< dim; i++)
        {
            for(int j = 0; j < dim; j++)
                cout << path[i][j] <<" ";
         cout << endl;
        }
         cout << p << " " << endl;
        return;
    }
    if (!maze[r][c])
        return;

    maze[r][c] = false;
    path[r][c] = step;

    if (r < dim - 1)
        pathwithObstacles(p + 'D', maze, r + 1, c, dim, path, step+1);

    if (c < dim - 1)
        pathwithObstacles(p + 'R', maze, r, c + 1, dim, path, step+1);

    if (r > 0)
        pathwithObstacles(p + 'U', maze, r - 1, c, dim, path, step+1);

    if (c > 0)
        pathwithObstacles(p + 'L', maze, r, c - 1, dim, path, step+1);
    maze[r][c] = true;
    path[r][c] = 0;
}
int main()
{
    bool **maze;
    int dim = 3;
    maze = new bool *[dim];
    for (int i = 0; i < dim; i++)
    {
        maze[i] = new bool[dim];
    }
    maze[0][0] = true; maze[0][1] = true; maze[0][2] = true; 
    maze[1][0] = true;maze[1][1] = true;maze[1][2] = true;
    maze[2][0] = true;maze[2][1] = true; maze[2][2] = true;
    // 1 1 1
    // 1 0 1
    // 1 1 1
    int **path;
    path = new int *[dim];
    for(int i = 0; i< dim; i++)
    path[i]=new int [dim];
    pathwithObstacles("", maze, 0, 0, dim, path, 1);
}