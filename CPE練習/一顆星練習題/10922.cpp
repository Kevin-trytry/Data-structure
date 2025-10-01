#include<iostream>
#include<string>
using namespace std;

long long int find9degree(long long num, int degree) {
    if(num > 9) {
        long long int next_num = 0;
        while(num > 0) {
            next_num += num % 10;
            num /= 10;
        }
        return find9degree(next_num, degree + 1); 
    }
    return degree;
}

int main( ) {
    while(1) {
        string input;
        long long int sum = 0;
        int final_plus = 0;

        cin >> input;
        if (input[0] == '0') {
            break;
        }

        for (int i = 0; i < input.length( ); i++) {
            sum += int(input[i] - '0'); //In ASCII, '0' is 48, '1' is 49, so we need to minus 48('0') to get the true value 
        }
        
        final_plus = find9degree(sum, 1);

        if(sum % 9 == 0) {
            cout << input << " is a multiple of 9 and has 9-degree " << final_plus << "." << endl;
        }
        else {
            cout << input << " is not a multiple of 9." << endl;
        }
    }
    return 0;
}