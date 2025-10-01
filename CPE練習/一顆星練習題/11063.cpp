#include<iostream>
#include<map>
using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int count = 1;
    while(cin >> N) {
        int arr[N], flag = 1;
        map<int, int> table;
        for(int i = 0; i < N ; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < N; i++) {
            for(int j = i; j < N; j++) {
                table[arr[i] + arr[j]]++;
                if (table[arr[i] + arr[j]] > 1) {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag) cout << "Case #" << count << ": It is a B2-Sequence." << endl << endl;
        else cout << "Case #" << count << ": It is not a B2-Sequence." << endl << endl;

        count ++;
    }
}