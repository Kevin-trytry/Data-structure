#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

int main( ) {
    vector<string> inputs;
    while(!cin.eof( )) {
        string str;
        getline(cin, str);
        inputs.push_back(str);
    }
    inputs.pop_back( );
    int max_length = 0;
    for (int i = 0; i < inputs.size( ); i++) {
        if (inputs[i].size( ) > max_length) max_length = inputs[i].size( );
    }

    for (int i = 0; i < max_length; i++) {
        for (int j = inputs.size( ) - 1; j >= 0; j--) {
            if (i > inputs[j].size( ) - 1) cout << ' ';
            else cout << inputs[j][i];
        }
        cout << endl;
    }

    return 0;
}