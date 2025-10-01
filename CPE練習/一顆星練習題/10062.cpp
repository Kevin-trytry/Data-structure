#include<bits/stdc++.h>
using namespace std;

int main( ) {
    string input;
    while (getline(cin, input)) {
        map<char, int> char_num;

        for (int i = 0; i < input.size( ); i++) {
            if (input[i] != '\r' && input[i] != '\n') char_num[input[i]]++;
        }

        map<int, vector<int>> result;
        for (auto it : char_num) {
            vector<char> temp;
            temp.assign(result[it.second].begin( ), result[it.second].end( ));
            temp.push_back(it.first);
            sort(temp.begin( ), temp.end());
            reverse(temp.begin( ), temp.end( ));
            result[it.second].assign(temp.begin( ), temp.end( ));
        }

        for (auto it : result) {
            vector<int> temp = it.second;
            for (int i = 0; i < temp.size( ); i++) {
                cout << temp[i] << " " << it.first << endl;
            }
        }

        cout << endl;
    }
}