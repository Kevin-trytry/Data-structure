#include<iostream>
#include<map>
#include<string>
using namespace std;

int main( ) {
    map<char, char> alphabet = {
        {'2', '`'}, {'3', '1'}, {'4', '2'}, {'5', '3'}, {'6', '4'}, {'7', '5'}, {'8', '6'}, {'9', '7'}, {'0', '8'}, {'-', '9'}, {'=', '0'},
        {'e', 'q'}, {'r', 'w'}, {'t', 'e'}, {'y', 'r'}, {'u', 't'}, {'i', 'y'}, {'o', 'u'}, {'p', 'i'}, {'[', 'o'}, {']', 'p'}, {'\\', '['},
        {'d', 'a'}, {'f', 's'}, {'g', 'd'}, {'h', 'f'}, {'j', 'g'}, {'k', 'h'}, {'l', 'j'}, {';', 'k'}, {'\'', 'l'},
        {'c', 'z'}, {'v', 'x'}, {'b', 'c'}, {'n', 'v'}, {'m', 'b'}, {',', 'n'}, {'.', 'm'}, {'/', ','}
    };

    while(!cin.eof( )) {
        string input;
        getline(cin, input);
        if (!input.empty( )) input.push_back('\n');
        for (int i = 0; i < input.size( ); i++) {
            if (input[i] == ' ' || input[i] == '\n') {
                cout << input[i];
                continue;
            }
            else {
                cout << alphabet[input[i]];
                continue;
            }
        }
    }
    
    return 0;
}