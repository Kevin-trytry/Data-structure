#include<iostream>
#include<cmath>
using namespace std;

int main( ) {
    int a, b;

    while(cin >> a >> b) {
        if (a == 0 && b == 0) break;

        if (round(sqrt(a)) * round(sqrt(a)) < a) {
            a = round(sqrt(a)) + 1;
        }
        else {
            a = round(sqrt(a));
        }
        
        if (round(sqrt(b)) * round(sqrt(b)) > b) {
            b = round(sqrt(b)) - 1;
        }
        else {
            b = round(sqrt(b));
        }
        
        cout << b - a + 1 << endl;
    }

    return 0;
}