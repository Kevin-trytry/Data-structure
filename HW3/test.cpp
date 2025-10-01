#include <iostream>

using namespace std;

const int MAX_SIZE = 6; // �̤j�ѽL�j�p

// �۩w�q���|���O
class KnightStack {
public:
    struct Position {
        int row, col, direction;
    };

    KnightStack(int maxSize);   // �غc���
    ~KnightStack();             // �Ѻc���

    void push(int row, int col, int direction);
    void pop();
    Position peek() const;
    bool isEmpty() const;

private:
    Position* stackArray;  // �������|���}�C
    int topIndex;          // ���|����
    int maxCapacity;       // ���|�e�q
};

// KnightStack ���O��������Ʃw�q�b���O�~��

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

// �M�h��8�ӥi�ಾ�ʤ�V
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

    // n = 1�ɡA�����{�w����
    if (boardSize == 1) {
        cout << "1" << endl;
        return true;
    }

    // �ʺA���t�ѽL
    int** board = new int*[boardSize];
    for (int i = 0; i < boardSize; ++i) {
        board[i] = new int[boardSize];
    }

    // ��l�ƴѽL
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = 0; // �]�w�Ҧ���l�������X
        }
    }

    KnightStack pathStack(boardSize * boardSize);  // ���|�j�p���ѽL�j�p������
    int currentRow = 0, currentCol = 0;
    board[currentRow][currentCol] = 1; // �]�w�_�l��m����1�B
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
            board[currentRow][currentCol] = 0; // �����o�@�B
            pathStack.pop();
            currentStep--;
        }

        if (currentStep > boardSize * boardSize) {
            displayBoard(boardSize, board);
            // ����ʺA���t���ѽL�O����
            for (int i = 0; i < boardSize; ++i) {
                delete[] board[i];
            }
            delete[] board;
            return true;
        }
    }

    cout << "No solution" << endl;
    // ����ʺA���t���ѽL�O����
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
