#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main( ) {
    int S;
    cin >> S;
    while(S) {
        int N, m;
        double p, result;
        cin >> N >> p >> m;
        result = p * pow(1 - p, m - 1) / (1 - pow(1 - p, N));
        cout << fixed << setprecision(4) << result << endl;
        S--;
    }

    return 0;
}