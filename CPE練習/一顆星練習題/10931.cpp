#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main( ) {
    int input;
    while(1) {
        cin >> input;
        if (input == 0) {
            break;
        }

        int count = 0;
        vector<int> binary;
        while(input != 0) {
            binary.push_back(input % 2);
            input /= 2;
        }
        reverse(binary.begin(), binary.end());
        for (int i = 0; i < binary.size( ); i++) {
            if (binary[i] == 1) {
                count ++;
            }
        }

        cout << "The parity of ";
        for (int i = 0; i < binary.size( ); i++) {
            cout << binary[i];
        }
        cout << " is " << count  << " (mod 2)." << endl;
    }

    return 0;
}