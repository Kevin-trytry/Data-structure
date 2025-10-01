#include<bits/stdc++.h>
using namespace std;

int bubbleSort(int arr[], int length) {
    int count = 0;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }

    return count;
}

int main( ) {
    int N;
    cin >> N;
    while (N--) {
        int L;
        cin >> L;
        int arr[L] = {0};
        for (int i = 0; i < L; i++) {
            cin >> arr[i];
        }

        cout << "Optimal train swapping takes " << bubbleSort(arr, L) <<  " swaps." << endl;
    }

    return 0;
}