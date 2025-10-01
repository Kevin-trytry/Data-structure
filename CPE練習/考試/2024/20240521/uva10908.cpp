#include<bits/stdc++.h>
using namespace std;

int main( ) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int count = 0 ; count < T ; count++) {
        int M, N, Q;
        cin >> M >> N >> Q;
        char test_square[M][N];
        for (int i = 0 ; i < M ; i++) {
            cin.ignore( );
            for (int j = 0 ; j < N ; j++) {
                cin >> test_square[i][j];
            }
        }

        int result[Q];
        for (int i = 0 ; i < Q ; i++) {
            int length = 1;
            int r, c;
            bool flag = true;
            cin >> r >> c;
            while(flag) {
                int initial_x = r - (length + 2) / 2, initial_y = c - (length + 2) / 2;
                for (int j = initial_x ; j < initial_x + length + 2 ; j++) {
                    for (int k = initial_y ; k < initial_y + length + 2 ; k++) {
                        if (test_square[j][k] != test_square[r][c] || (j < 0 || k < 0) || (j >= M || k >= N)) {
                            flag = false;
                            break;
                        }
                    }
                }

                if (flag) length += 2;
            }
            result[i] = length;
        }
        cout << M << " " << N << " " << Q << endl;
        for (int j = 0 ; j < Q ; j++) {
            cout << result[j] << endl;
        }
    }
}