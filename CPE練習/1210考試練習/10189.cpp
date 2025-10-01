#include<bits/stdc++.h>
using namespace std;

void checkMines(string map[ ], int row, int col, int M, int N) {
    if (row - 1 >= 0 && col - 1 >= 0 && map[row - 1][col - 1] != '*') map[row - 1][col - 1]++;
    if (row - 1 >= 0 && map[row - 1][col] != '*') map[row - 1][col]++;
    if (row - 1 >= 0 && col + 1 < N && map[row - 1][col + 1] != '*') map[row - 1][col + 1]++;
    if (col - 1 >= 0 && map[row][col - 1] != '*') map[row][col - 1]++;
    if (col + 1 < N && map[row][col + 1] != '*') map[row][col + 1]++;
    if (row + 1 < M && col - 1 >= 0 && map[row + 1][col - 1] != '*') map[row + 1][col - 1]++;
    if (row + 1 < M && map[row + 1][col] != '*') map[row + 1][col]++;
    if (row + 1 < M && col + 1 < N && map[row + 1][col + 1] != '*') map[row + 1][col + 1]++;
}

int main( ) {
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    int field = 1;
    bool firstCase = true;

    while(1) {
        cin >> M >> N;
        if (M == 0 && N == 0) break;

        if (!firstCase) cout << endl;
        firstCase = false;

        string map[M];
        
        for (int i = 0 ; i < M ; i++) {
            getline(cin >> ws, map[i]);
            for (int j = 0 ; j < N ; j++) if (map[i][j] == '.') map[i][j] = 48;
        }
        for (int i = 0 ; i < M ; i++) {
            for (int j = 0 ; j < N ; j++) if (map[i][j] == '*') checkMines(map, i, j, M, N);
        }
        
        cout << "Field #" << field++ << ":" << endl;
        for (int i = 0 ; i < M ; i++) cout << map[i] << endl;
    }
}