// Name : B123040004 莊志文
// Date : 2024/10/09
// Purpose : Print out the ways of going through the checkerboard of the knight
#include <iostream>

using namespace std;

const int MAX_SIZE = 6; // Maximum board size

class KnightStack {
public:
    struct Position {
        int row, col, direction;
    };

    KnightStack(int maxSize);   // Constructor
    ~KnightStack();             // Destructor

    void push(int row, int col, int direction); // Push position onto stack
    void pop();                                // Pop position from stack
    Position peek() const;                     // Peek top position
    bool isEmpty() const;                      // Check if stack is empty

private:
    Position* stackArray;  // Array to simulate stack
    int topIndex;          // Top of the stack
    int maxCapacity;       // Stack capacity
};


KnightStack::KnightStack(int maxSize) : maxCapacity(maxSize), topIndex(-1) {
    stackArray = new Position[maxCapacity]; // Allocate memory for stack
}

KnightStack::~KnightStack() {
    delete[] stackArray; // Deallocate memory
}

void KnightStack::push(int row, int col, int direction) {
    if (topIndex >= maxCapacity - 1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stackArray[++topIndex] = {row, col, direction}; // Push position
}

void KnightStack::pop() {
    if (topIndex == -1) {
        cout << "Stack underflow!" << endl;
        return;
    }
    --topIndex; // Pop position
}

KnightStack::Position KnightStack::peek() const {
    if (topIndex == -1) {
        return {-1, -1, -1}; // Return invalid position if stack is empty
    }
    return stackArray[topIndex]; // Return top position
}

bool KnightStack::isEmpty() const {
    return topIndex == -1; // Check if stack is empty
}

// Knight's 8 possible moves
const int knightMoves[8][2] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

// Check if position is within bounds and not visited
bool isWithinBounds(int row, int col, int boardSize, int** board) {
    return (row >= 0 && col >= 0 && row < boardSize && col < boardSize && board[row][col] == 0);
}

// Display the board
void displayBoard(int boardSize, int** board) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Solve the Knight's Tour problem
bool solveKnightTour(int boardSize) {
    if (boardSize <= 0) {
        cout << "No solution" << endl;
        return false;
    }

    // If board size is 1, solution is trivial
    if (boardSize == 1) {
        cout << "1" << endl;
        return true;
    }

    // Dynamically allocate the board
    int** board = new int*[boardSize];
    for (int i = 0; i < boardSize; ++i) {
        board[i] = new int[boardSize];
    }

    // Initialize the board
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = 0; // Set all squares as unvisited
        }
    }

    KnightStack pathStack(boardSize * boardSize);  // Stack size is the square of the board size
    int currentRow = 0, currentCol = 0;
    board[currentRow][currentCol] = 1; // Set starting position as step 1
    pathStack.push(currentRow, currentCol, 0);

    int currentStep = 2;

    while (!pathStack.isEmpty()) {
        KnightStack::Position currentPosition = pathStack.peek();
        currentRow = currentPosition.row;
        currentCol = currentPosition.col;
        int direction = currentPosition.direction;

        bool moved = false;

        for (int d = direction; d < 8; ++d) {
            int nextRow = currentRow + knightMoves[d][0];
            int nextCol = currentCol + knightMoves[d][1];

            if (isWithinBounds(nextRow, nextCol, boardSize, board)) {
                board[nextRow][nextCol] = currentStep;
                pathStack.pop();
                pathStack.push(currentRow, currentCol, d + 1);
                pathStack.push(nextRow, nextCol, 0);
                currentStep++;
                moved = true;
                break;
            }
        }

        if (!moved) {
            board[currentRow][currentCol] = 0; // Undo this step
            pathStack.pop();
            currentStep--;
        }

        if (currentStep > boardSize * boardSize) {
            displayBoard(boardSize, board);
            // Free dynamically allocated memory
            for (int i = 0; i < boardSize; ++i) {
                delete[] board[i];
            }
            delete[] board;
            return true;
        }
    }

    cout << "No solution" << endl;
    // Free dynamically allocated memory
    for (int i = 0; i < boardSize; ++i) {
        delete[] board[i];
    }
    delete[] board;
    return false;
}

int main() {
    for (int i = 1; i <= MAX_SIZE; i++) {
        cout << "n = " << i << ":" << endl;
        solveKnightTour(i);
        cout << endl;
    }

    return 0;
}

