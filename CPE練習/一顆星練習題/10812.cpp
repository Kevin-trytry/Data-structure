#include<iostream>
using namespace std;

int main( ) {
    int N;
    cin >> N;
    
    while(N) {
        int s, d;
        cin >> s >> d;

        if (s < d || (s + d) % 2 != 0) cout << "impossible" << endl;
        else {
            cout << (s + d) / 2 << " " << (s + d) / 2 - d << endl;
        }

        N--;
    }

    return 0;
}