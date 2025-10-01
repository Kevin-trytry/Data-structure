#include<iostream>
#include<string>
#include<map>
#include<iomanip>
#include<cmath>
using namespace std;

int main( ) {
    int n; //n groups
    cin >> n;
    cout << endl;
    
    for(int i = 0; i < n; i++) {
        string input ;
        map<string, double> forest;
        double sum = 0.0;
        getline(cin, input);
        forest[input] += 1.0;
        sum += 1.0;

        while(getline(cin, input) && input != "") {
            forest[input] += 1.0;
            sum += 1.0;
        }
        
        for(std::map<string, double>:: iterator it = forest.begin( ); it != forest.end( ); it++) {
            cout << (*it).first << " " << fixed << setprecision(4) << (*it).second / sum * 100 << endl; 
        }
        cout << endl;

    }

    return 0;
}