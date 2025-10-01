#include<iostream>
#include<cmath>
using namespace std;

//judge if input is a prime
bool judgePrime(int input) {
    if (input != 2) {
        for (int i = 2; i <= sqrt(input); i++) {
            if (input % i == 0) {
                return false;
            }
        }
    }
    return true;
}

bool judgeEmirp(int input) {
    int reverse = 0, temp = input;
    //reverse the input number
    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }

    if(judgePrime(reverse) && reverse != input) {
        return true;
    }
    return false;
}

int main( ) {
    int input;
    while(cin >> input && !cin.eof()) {
        if (!judgePrime(input)) {
            cout << input << " is not prime." << endl;
        }
        else {
            if (judgeEmirp(input)) {
                cout << input << " is emirp." << endl;
            }
            else {
                cout << input << " is prime." << endl;
            }
        }
    }
    
    return 0;
}