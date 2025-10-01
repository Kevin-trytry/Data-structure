#include<iostream>
using namespace std;

//function to find GCD
int GCD(int x, int y) {
    if (x > y) {
        //Euclidean algorithm
        while (y != 0) {
            int temp = x;
            x = y;
            y = temp % y;
        }
        return x;
    }
    else if (x < y) {
        //Euclidean algorithm
         while (x != 0) {
            int temp = y;
            y = x;
            x = temp % x;
        }
        return y;
    }
    else return x;
}

int main( ) {
    while(1) {
        int G = 0, N;       
        cin >> N;
        if (N == 0) {
            break;
        }
        //find summation of GCD
        for(int i = 1; i <= N; i++) {
            for(int j = i + 1; j <= N; j++) {
                G += GCD(i, j);
            }
        }
        cout << G << endl;
    }

    return 0;
}