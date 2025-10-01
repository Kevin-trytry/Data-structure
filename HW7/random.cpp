#include<bits/stdc++.h>
using namespace std;

int main( ) {
    srand(time(NULL));
    int size = 10;
    ofstream out;
    out.open("input.txt");
    out << size << endl;
    
    for (int i = 0 ; i < size ; i++) {
        out << rand( ) % RAND_MAX << " " << endl;
    }
    out.close( );
}

