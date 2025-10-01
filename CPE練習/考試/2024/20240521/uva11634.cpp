#include<bits/stdc++.h>
using namespace std;

int main( ) {
    int input;
    while (cin >> input && input != 0) {
        int count = 0;
        bool check[10001] = {false};
        while (!check[input]) {
            count++;
            check[input] = true;
            input *= input;
            input /= 100;
            input %= 10000;
        }
        cout << count << endl;
    }
}