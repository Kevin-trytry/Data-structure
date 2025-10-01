#include<iostream>
using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
	cin.tie(0);

    long long int people, check;
    
    while(cin >> people >> check) {
        long long int days = 0;
        while (days < check) {
            days += people;
            people++;
        }
        people--;
        
        cout << people << endl;
    }

    return 0;
}