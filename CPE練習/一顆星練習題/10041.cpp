#include<iostream>
#include<algorithm>
using namespace std;

int main( ) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        int arr[r];
        for (int j = 0; j < r; j++) {
            cin >> arr[j];
        }
        sort(arr, arr + r);
                
        int mid;
        if (r % 2 == 0) {
            mid = (arr[r / 2 - 1] + arr[(r / 2)]) / 2;
        }
        else {
            mid = arr[r / 2];
        }

        int distance_total = 0;
        for (int j = 0; j < r; j++) {
            distance_total += abs(mid - arr[j]);
        }

        cout << distance_total << endl;
    }

    return 0;
}