#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> decimal(int input) {
    int temp = input;
    vector<int> result;
    while(temp != 0) {
        result.push_back(temp % 2);
        temp /= 2;
    }
    reverse(result.begin( ), result.end( ));
    return result;
}

int hexaToDecimal(int input) {
    int result = 0, i = 0;
    while(input != 0) {
        result += (input % 10) * pow(16, i);
        input /= 10;
        i++;
    }
    return result;
}

int main( ) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        vector<int> x1, x2;
        cin >> input;

        //decimal
        int b1 = 0;
        x1 = decimal(input);
        for (int i = 0; i < x1.size( ); i++) {
            if (x1[i] == 1) b1++;
        }
        cout << endl;

        //hexedecimal
        int b2 = 0;
        int hexa_of_input = hexaToDecimal(input);
        x2 = decimal(hexa_of_input);
        for (int i = 0; i < x2.size( ); i++) {
            if (x2[i] == 1) b2++;
        }
        cout << endl;

        cout << b1 << " " << b2 << endl;
    }

    return 0;
}