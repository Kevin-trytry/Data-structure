#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;

long long int power(long long int base, long long int exp) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int main( ) {
    long long int x;
    string enter;
    while(cin >> x) {
        cin.ignore( );
        getline(cin, enter);

        istringstream iss(enter);
        long long int input;
        vector<long long int> coefficient;
        while (iss >> input) {
            coefficient.push_back(input);
        }
        
        long long int n = coefficient.size( ) - 1;
        long long int result = 0;
        for (int i = 0; i < coefficient.size( ) - 1; i++) {
            result += coefficient[i] * n * power(x, n - 1);
            n--;
        }

        cout << result << endl;
    }
    return 0;
}