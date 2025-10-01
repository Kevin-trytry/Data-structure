#include<iostream>
using namespace std;

int sumOfDigits(int input) {
    if (input / 10 == 0) {
        return input;
    }
    else {
        int result = 0;
        while(input != 0) {
            result += input % 10;
            input /= 10;
        }
        return sumOfDigits(result);
    }
}

int main( ) {
    while(1) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        cout << sumOfDigits(N) << endl;
    }

    return 0;
}