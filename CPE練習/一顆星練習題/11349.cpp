#include<iostream>
using namespace std;

int main( ) {
    int T, count = 1;
    cin >> T;
    while(T--) {
        cin.ignore( );
        long long int N;
        scanf("N = %d", &N);

        long long int test[N * N];
        int negative = 1, sym = 1;

        for (int i = 0; i < N * N; i++) {
            cin >> test[i];
            if (test[i] < 0) negative = 0;
        }

        if (negative != 0) {
            for (int i = 0; i < N * N / 2; i++) {
                if (test[i] != test[N * N - 1 -i]) {
                    sym = 0;
                    break;
                }
            }
        }

        if (negative == 1 && sym == 1) {
            cout << "Test #" << count << ": Symmetric." << endl;
        }
        else {
            cout << "Test #" << count << ": Non-symmetric." << endl;
        }

        count++;
    }

    return 0;
}