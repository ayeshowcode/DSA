#include <iostream>
using namespace std;

// Function to print the board
void printBoard(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int** board, int row, int col, int N) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) 
            return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) 
            return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) 
            return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int** board, int row, int N) {
    if (row >= N) 
        return true;  // All queens are placed successfully

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place the queen at board[row][col]
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, row + 1, N))
                return true;

            // Backtrack if placing the queen doesn't lead to a solution
            board[row][col] = 0;
        }
    }
    return false;  // No valid configuration found
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    // Dynamically allocate memory for the N x N board
    int** board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N]();
    }

    // Solve the N-Queens problem
    if (solveNQueens(board, 0, N)) {
        cout << "Solution for " << N << "-Queens:" << endl;
        printBoard(board, N);
    } else {
        cout << "No solution exists for " << N << "-Queens." << endl;
    }

    // Deallocate the memory for the board
    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
