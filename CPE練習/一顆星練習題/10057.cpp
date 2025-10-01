#include<bits/stdc++.h>
using namespace std;

int main( ) {
    int n, number_of_n;

    while (cin >> n) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        int high = arr[(n + 1) / 2];
        int low = arr[(n - 1) / 2];

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= low && arr[i] <= high) count ++;
        }
        cout << low << " " << count << " " << high - low + 1 << endl;
    }
}