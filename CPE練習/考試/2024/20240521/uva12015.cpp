#include<bits/stdc++.h>
using namespace std;

int main( ) {
    ios::sync_with_stdio(0);
    cout.tie(nullptr);

    int relevance;
    int T;
    
    string input_string;
    vector<vector<string>> result;
    cin >> T;
    for (int i = 0 ; i < T ; i++) {
        vector<string> cases;
        int MAX_relevance = 0;
        for (int j = 0 ; j < 10 ; j++) {
            cin.ignore( );
            cin >> input_string;
            cin.ignore( );
            cin >> relevance;
            if (relevance > MAX_relevance) {
                while(!cases.empty( )) {
                    cases.pop_back( );
                }
                cases.push_back(input_string);
                MAX_relevance = relevance;
            }
            else if (relevance == MAX_relevance) cases.push_back(input_string); 
        }
        result.push_back(cases);
    }

    for (int i = 0 ; i < T ; i++) {
        cout << "Case #" << i + 1 << ":" << endl;
        for (int j = 0 ; j < result[i].size( ) ; j++) {
            cout << result[i][j] << endl;
        }
    }

    return 0;
}  