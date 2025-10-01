#include<iostream>
#include<map>
using namespace std;

int main( ) {
    int T;
    cin >> T;
    while(T--) {
        int M, N, Q;
        cin.ignore( );
        cin >> M >> N >> Q;
        char square[M][N];
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> square[i][j];
            } 
        }

        cout << M << " " << N << " " << Q << endl;
        
        for (int i = 0; i < Q; i++) {
            int center_x , center_y;
            cin.ignore( );
            cin >> center_x >> center_y;
            int side = 1;
            bool flag = true;
            map<char, int> number_of_char;

            while(flag) {
                side += 2;
                if ((center_x - side / 2 < 0 || center_y - side / 2 < 0) || center_x + side / 2 > M - 1 || center_y + side / 2 > N - 1) {
                    side -= 2;
                    break;
                }

                for (int j = center_x - side / 2; j <= center_x + side / 2; j++) {
                    for (int k = center_y - side / 2; k <= center_y + side / 2; k++) {
                        number_of_char[square[j][k]]++;
                    }
                }
                if (number_of_char.size( ) > 1) {
                    flag = false;
                    side -= 2;
                    break;
                }
            }

            cout << side << endl;
        } 
    }

    return 0;
}