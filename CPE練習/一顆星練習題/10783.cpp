#include<iostream>
#include<map>
using namespace std;

int main( ) {
    int T, count = 1;
    map<int, int> result;
    cin >> T;
    while(T) {
        int a, b;
        int odd_sum = 0;
        cin >> a >> b;
        
        if (a % 2 == 0 && b % 2 == 0) {
            a += 1;
            b -= 1;
        }
        else if (a % 2 != 0 && b % 2 == 0) b -= 1;
        else if (a % 2 == 0 && b % 2 != 0) a += 1;

        while (a <= b) {
            odd_sum += a;
            a += 2;
        }
        
        result[count] = odd_sum;
        count++;
        T--;
    }

    for (const auto &it : result) {
        cout << "Case "<< it.first << ": " << it.second << endl;
    }

    return 0;
}