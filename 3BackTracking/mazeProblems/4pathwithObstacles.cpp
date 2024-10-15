#include <iostream>
using namespace std;
void pathwithObstacles(string p, bool *maze[], int r, int c, int dim)
{
    if (r == dim - 1 && c == dim - 1)
    {
        cout << p << " ";
        return;
    }
    if (!maze[r][c])
        return;
    if (r < dim - 1)
        pathwithObstacles(p + 'D', maze, r + 1, c, dim);

    if (c < dim - 1)
        pathwithObstacles(p + 'R', maze, r, c + 1, dim);
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
    maze[0][0] = true;
    maze[0][1] = true;
    maze[0][2] = true;

    maze[1][0] = true;
    maze[1][1] = false;
    maze[1][2] = true;

    maze[2][0] = true;
    maze[2][1] = true;
    maze[2][2] = true;
// 1 1 1 
// 1 0 1
// 1 1 1 
    pathwithObstacles("", maze, 0, 0, dim);
}