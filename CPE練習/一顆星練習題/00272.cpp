#include<iostream>
#include<string>
using namespace std;

int main( ) {
    string str;
    string input;
    while(getline(cin, str) && !cin.eof( )) {
        input += str;
        input.push_back('\n');
    }
    
    int flag = 0;
    string result;
    for (int i = 0; i < input.size( ); i++) {
        if (input[i] == '"' && flag == 0) {
            result.push_back('`');
            result.push_back('`');
            flag = 1;
        } 
        else if(input[i] == '"' && flag == 1) {
            result.push_back('\'');
            result.push_back('\'');
            flag = 0;
        }
        else result.push_back(input[i]);
    }
    result.pop_back( );

    cout << result;

    return 0;
}