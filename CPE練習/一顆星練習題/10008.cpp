#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int main( ) {
    int n;
    map<char, int> charactor;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin.ignore( );
        string input;
        getline(cin, input);
        for(int i = 0; i < input.size( ); i++) {
            if(input[i] >= 65 && input[i] <= 95) {
                charactor[input[i]]++;
            }
            else if(input[i] >= 97 && input[i] <= 122) {
                charactor[input[i] - 32]++;
            }
        }
    }
    
 

    for (std::map<char, int> :: iterator it = charactor.begin( ); it != charactor.end( ); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    return 0;
}