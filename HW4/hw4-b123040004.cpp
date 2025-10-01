// Name : B123040004 莊志文
// Date : 2024/10/19
// Purpose : Print out the ways of going through the checkerboard of the knight by recursion
#include <iostream>

using namespace std;

// The 8 possible knight moves on the chessboard
const int knightMoves[8][2] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

// Check if the position is within the bounds of the chessboard and hasn't been visited
bool isWithinBounds(int row, int col, int boardSize, int** board) {
    return (row >= 0 && col >= 0 && row < boardSize && col < boardSize && board[row][col] == 0);
}

// Display the current state of the chessboard with the steps of the knight's tour
void displayBoard(int boardSize, int** board) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " ";  // Print each step number on the board
        }
        cout << endl;
    }
}

// Recursive function to solve the knight's tour problem
bool solveKnightTourRecursive(int** board, int boardSize, int step, int currentRow, int currentCol) {
    if (step == boardSize * boardSize) {  // Base case: all cells are visited
        return true;
    }

    // Try all 8 possible knight moves
    for (int i = 0; i < 8; ++i) {
        int nextRow = currentRow + knightMoves[i][0];
        int nextCol = currentCol + knightMoves[i][1];

        // Check if the next move is valid and the position hasn't been visited
        if (isWithinBounds(nextRow, nextCol, boardSize, board)) {
            board[nextRow][nextCol] = step + 1;  // Mark the move on the board

            // Recur to check if the knight can move further
            if (solveKnightTourRecursive(board, boardSize, step + 1, nextRow, nextCol)) {
                return true;
            }
            else {
                board[nextRow][nextCol] = 0;  // Backtrack if the move fails
            }
        }
    }

    return false;  // Return false if no valid moves are available
}

// Function to initialize the board and solve the knight's tour
bool solveKnightTour(int boardSize) {
    if (boardSize <= 0) {  // Handle edge case where the board size is invalid
        cout << "No solution" << endl;
        return false;
    }

    // Base case: n = 1, a single-cell board always has a solution
    if (boardSize == 1) {
        cout << "1" << endl;
        return true;
    }

    // Dynamically allocate a 2D array for the chessboard
    int** board = new int*[boardSize];
    for (int i = 0; i < boardSize; ++i) {
        board[i] = new int[boardSize];
    }

    // Initialize the board: all cells start as unvisited (0)
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = 0;
        }
    }

    board[0][0] = 1;  // Starting position of the knight at (0, 0)

    // Start the recursive knight tour
    if (solveKnightTourRecursive(board, boardSize, 1, 0, 0)) {
        displayBoard(boardSize, board);  // Display the solution if found

        // Free dynamically allocated memory for the board
        for (int i = 0; i < boardSize; ++i) {
            delete[] board[i];
        }
        delete[] board;

        return true;
    } 
    else {
        cout << "No solution" << endl;  // No solution found

        // Free dynamically allocated memory for the board
        for (int i = 0; i < boardSize; ++i) {
            delete[] board[i];
        }
        delete[] board;

        return false;
    }
}

int main() {
    const int MAX_SIZE = 6;  // Define the maximum board size
    for (int boardSize = 1; boardSize <= MAX_SIZE; ++boardSize) {
        cout << "n = " << boardSize << ":" << endl;  // Display board size
        solveKnightTour(boardSize);  // Solve for the given board size
        cout << endl;
    }

    return 0;
}
