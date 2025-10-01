#include<iostream>
#include<string>
using namespace std;


int main( ) {
    while(1) {
        string input;
        cin >> input;
        if (input[0] == '0') {
            break;
        }

        int even_sum = 0, odd_sum = 0;
        for(int i = 0; i < input.length( ); i++) {
            if (i % 2 == 0) {
                even_sum += int(input[i] - '0');
            }
            else {
                odd_sum += int(input[i] - '0');
            }
        }
        if ((even_sum - odd_sum) % 11 == 0) {
            cout << input << " is a multiple of 11." << endl;
        }
        else {
            cout << input << " is not a multiple of 11." << endl;
        }
    }

    return 0;
}