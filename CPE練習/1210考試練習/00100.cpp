#include<bits/stdc++.h>
using namespace std;

int calculateLength(int num) {
    int length = 1;
    while (num != 1) {
        if (num % 2 == 1) num = 3 * num + 1;
        else num /= 2;
        length++; 
    }
    return length;
}

int main( ) {
    int i, j;
    while(cin >> i >> j) {
        int max_length = 0;
        if (i <= j) {
            for (int k = i ; k <= j ; k++) {
                int result = calculateLength(k);
                if (result > max_length) max_length = result;
            }
        }  
        else {
            for (int k = j ; k <= i ; k++) {
                int result = calculateLength(k);
                if (result > max_length) max_length = result;
            }
        }
        cout << i << " " << j << " " << max_length << endl;
    }
    
    return 0;
}