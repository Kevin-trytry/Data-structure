#include<iostream>
using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int input1, input2;
    int n;
    while(cin >> n) {
        int arr[n + 1] = {0}, t = 0, b;

        cin >> input1;
        for (int i = 1; i < n; i++) {
            cin >> input2;
            b = abs(input1 - input2);
            if (arr[b] == 0 && b >= 1 && b < n) {
                arr[b] = 1;
                t++;
            }
            input1 = input2;
        }
        
        if (t == n - 1) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;

    }
    return 0;
}