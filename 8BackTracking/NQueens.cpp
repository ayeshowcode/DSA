#include <iostream>
using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int **board, int row, int col, int N)
{
    int i, j;

    // Check the column for any queen
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the upper diagonal on the right side
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;
 
    return true;
}

// Function to print the board
void printSolution(int **board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// Backtracking function to solve the N-Queens problem
bool solveNQueens(int **board, int row, int N)
{
    // If all queens are placed
    if (row >= N)
        return true;

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            // Place a queen
            board[row][col] = 1;

            // Recursively try to place queens in the remaining rows
            if (solveNQueens(board, row + 1, N))
                return true;

            // If placing queen at board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If no column worked, return false
    return false;
}

// Function to solve the N-Queens problem and print the solution
void solve(int N)
{
    // Dynamically allocate memory for the N x N board
    int **board = new int *[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[N];

    // Initialize the board with 0s
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQueens(board, 0, N))
        cout << "No solution exists." << endl;
    else
        printSolution(board, N);

    // Free the dynamically allocated memory
    for (int i = 0; i < N; i++)
        delete[] board[i];
    delete[] board;
}

int main()
{
    int N;
    cout << "Enter the value of N (size of the board): ";
    cin >> N;
    solve(N);
    return 0;
}
