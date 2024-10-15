// BACKTRACKING

#include <iostream>
using namespace std;
int countpathwithObstacles(string p, bool *maze[], int r, int c, int dim)
{
    if (r == dim - 1 && c == dim - 1)
    {
        // cout << p << " ";
        return 1;
    }
    if (!maze[r][c])
        return 1;

    maze[r][c] = false;
    int count = 0;

    if (r < dim - 1)
        count += countpathwithObstacles(p + 'D', maze, r + 1, c, dim);

    if (c < dim - 1)
        count += countpathwithObstacles(p + 'R', maze, r, c + 1, dim);
    return count;
}
int main()
{
    bool **maze;
    int dim = 5;
    maze = new bool *[dim];
    for (int i = 0; i < dim; i++)
    {
        maze[i] = new bool[dim];
    }
    maze[0][0] = true; maze[0][1] = false; maze[0][2] = false; maze[0][3] = false; maze[0][4] = false;
    maze[1][0] = true; maze[1][1] = true; maze[1][2] = false; maze[1][3] = false; maze[1][4] = false;
    maze[2][0] = false; maze[2][1] = true; maze[2][2] = true; maze[2][3] = false; maze[2][4] = false;
    maze[3][0] = true; maze[3][1] = true; maze[3][2] = true; maze[3][3] = false; maze[3][4] = false;
    maze[4][0] = false; maze[4][1] = false; maze[4][2] = false; maze[4][3] = true; maze[4][4] = false;
    // 0 0 0 0 0
    // 1 1 0 0 0
    // 0 1 1 0 0
    // 1 1 1 0 0
    // 0 0 0 1 0
    cout << countpathwithObstacles("", maze, 0, 0, dim);
}