#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;

int main( ) {
    int count = 0;
    long long int input;
    while(cin >> input) {
        count++;
        vector<int> result;
        if (input == 0) {
            cout << setw(4) << count << ". " << input << endl;
            continue;
        }
        int i = 0;
        while(input != 0) {
            if (i == 0) {
                result.push_back(input % 100);
                input /= 100;
            }
            result.push_back(input % 10);
            input /= 10;
            result.push_back(input % 100);
            input /= 100;
            result.push_back(input % 100);
            input /= 100;
            result.push_back(input % 100);
            input /= 100;
            i++;
        }
        cout << setw(4) << count << ". ";
        for (int i = result.size( ) - 1; i >= 0; i--) {
            if (i % 4 == 0 && i != 0 && result[i] != 0) {
                cout << result[i] << " kuti " ;
            }
            else if (i % 4 == 3 && i != 0 && result[i] != 0) {
                cout << result[i] << " lakh ";
            }
            else if (i % 4 == 2 && i != 0 && result[i] != 0) {
                cout << result[i] << " hajar ";
            }
            else if (i % 4 == 1 && i != 0 && result[i] != 0) {
                cout << result[i] << " shata ";
            }
            else if (result[i] != 0 && i == 0){
                cout << result[i];
            }
        }
        cout << endl;
    }   

    return 0;
}