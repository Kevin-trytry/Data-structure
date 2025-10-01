#include<bits/stdc++.h>
using namespace std;

int main( ) {
    string input;
    while(getline(cin >> ws, input)) {
        vector<pair<int, int>> table;
        int ascii[257] = {0};
        for(int i = 0 ; i < input.length( ) ; i++) {
            ascii[int(input[i])]++;
        }
        for (int i = 0 ; i < 257 ; i++) {
            if (ascii[i] != 0) table.push_back(make_pair(i, ascii[i]));
        }

        sort(table.begin( ), table.end( ), [](const pair<int, int>& a, const pair<int, int> &b){
            if(a.second == b.second) return a.first > b.first;
            else return a.second < b.second;
        });
        
        for (int i = 0 ; i < table.size( ) ; i++) {
            cout << table[i].first << " " << table[i].second << endl << endl;
        }
    }
}