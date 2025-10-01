#include<iostream>
#include<string>
#include<map>
using namespace std;

int main( ) {
    int n;
    map<string, int> country;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        country[str]++;
        getline(cin, str);
    }
    
    for (std::map<string, int> :: iterator it = country.begin( ); it != country.end( ); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    return 0;
}