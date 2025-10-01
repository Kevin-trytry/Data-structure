#include<iostream>
#include<vector>
using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long input1, input2;
    
    while(cin >> input1 >> input2) {
        if (input1 == 0 && input2 == 0) break;

        long long int carries = 0;
        long long int c = 0;
        while(input1 > 0 || input2 > 0 || c > 0) {
            int s = input1 % 10 + input2 % 10 + c;
            if (s >= 10) carries++;
            input1 /= 10;
            input2 /= 10;
            c = s / 10;
        }
        
        if (carries == 0) cout << "No carry operation." << endl;
        else if (carries == 1) cout << "1 carry operation." << endl;
        else cout << carries << " carry operations." << endl;
    }
}