#include <iostream>

using namespace std;

const int MAX_SIZE = 6; // 最大棋盤大小

// 自定義堆疊類別
class KnightStack {
public:
    struct Position {
        int row, col, direction;
    };

    KnightStack(int maxSize);   // 建構函數
    ~KnightStack();             // 解構函數

    void push(int row, int col, int direction);
    void pop();
    Position peek() const;
    bool isEmpty() const;

private:
    Position* stackArray;  // 模擬堆疊的陣列
    int topIndex;          // 堆疊頂端
    int maxCapacity;       // 堆疊容量
};

// KnightStack 類別的成員函數定義在類別外部

KnightStack::KnightStack(int maxSize) : maxCapacity(maxSize), topIndex(-1) {
    stackArray = new Position[maxCapacity];
}

KnightStack::~KnightStack() {
    delete[] stackArray;
}

void KnightStack::push(int row, int col, int direction) {
    if (topIndex >= maxCapacity - 1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stackArray[++topIndex] = {row, col, direction};
}

void KnightStack::pop() {
    if (topIndex == -1) {
        cout << "Stack underflow!" << endl;
        return;
    }
    --topIndex;
}

KnightStack::Position KnightStack::peek() const {
    if (topIndex == -1) {
        return {-1, -1, -1};
    }
    return stackArray[topIndex];
}

bool KnightStack::isEmpty() const {
    return topIndex == -1;
}

// 騎士的8個可能移動方向
const int knightMoves[8][2] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

bool isWithinBounds(int row, int col, int boardSize, int** board) {
    return (row >= 0 && col >= 0 && row < boardSize && col < boardSize && board[row][col] == 0);
}

void displayBoard(int boardSize, int** board) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveKnightTour(int boardSize) {
    if (boardSize <= 0) {
        cout << "No solution" << endl;
        return false;
    }

    // n = 1時，直接認定有解
    if (boardSize == 1) {
        cout << "1" << endl;
        return true;
    }

    // 動態分配棋盤
    int** board = new int*[boardSize];
    for (int i = 0; i < boardSize; ++i) {
        board[i] = new int[boardSize];
    }

    // 初始化棋盤
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = 0; // 設定所有格子為未拜訪
        }
    }

    KnightStack pathStack(boardSize * boardSize);  // 堆疊大小為棋盤大小的平方
    int currentRow = 0, currentCol = 0;
    board[currentRow][currentCol] = 1; // 設定起始位置為第1步
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
            board[currentRow][currentCol] = 0; // 取消這一步
            pathStack.pop();
            currentStep--;
        }

        if (currentStep > boardSize * boardSize) {
            displayBoard(boardSize, board);
            // 釋放動態分配的棋盤記憶體
            for (int i = 0; i < boardSize; ++i) {
                delete[] board[i];
            }
            delete[] board;
            return true;
        }
    }

    cout << "No solution" << endl;
    // 釋放動態分配的棋盤記憶體
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
