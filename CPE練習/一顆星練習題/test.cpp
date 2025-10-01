#include<iostream>
#include<map>
using namespace std;

int main( ) {
    map<char, int> test = {
        {'a', 3}
    };

    cout << test.size( );
}