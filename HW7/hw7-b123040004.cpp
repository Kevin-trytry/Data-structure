// Name : B123040004 莊志文
// Date : 2024/11/18
// Purpose : Test different ways of sorting and compare their time complexity

#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

// selection sort
void selectionSort(int arr[ ], int length) {
    for (int i = 0 ; i < length - 1 ; i++) {
        int min = i;
        for (int j = i + 1 ; j < length ; j++) {
            if (arr[min] > arr[j]) min = j;
        }

        if (min != i) swap(arr[min], arr[i]);
    }
}

// fuction for heap sort
// heapfy to build MAX heap
void heapfy(int arr[ ], int length, int parent) {
    int largest = parent; // initialize the largest is the root
    int leftChild = 2 * parent + 1; // assign left child
    int rightChild = 2 * parent + 2; // assign right child
    if (leftChild < length && arr[leftChild] > arr[largest]) largest = leftChild; // if left child is greater than root, adjust maximum key
    if (rightChild < length && arr[rightChild] > arr[largest]) largest = rightChild; // if right child is greater than root, adjust maximum key
    if (largest != parent) { // if the largest is not root
        swap(arr[largest], arr[parent]); // swap the largest one to root
        heapfy(arr, length, largest); // heapfy the adjust node
    }
}

// heap sort
void heapSort(int arr[ ], int length) {
    for (int i = length / 2 ; i >= 0 ; i--) {
        heapfy(arr, length, i); // build the maximum heap
    }
    for (int i = length - 1 ; i > 0 ; i--) {
        swap(arr[0], arr[i]); // swap the largest node and root
        heapfy(arr, i, 0); // heapfy the rest nodes
    }
}

// quick sort
void QuickSort(int arr[ ], int left, int right) {
    if (left >= right) return;

    int pivot = arr[left]; // assume the left most element is the pivot
    int i = left + 1, j = right; // i for key to find the element larget than pivot, j for the less one
    while (i <= j) { 
        while (i <= right && arr[i] < pivot) i++; // until meet the larger one, keep move i to the right
        while (j >= left && arr[j] > pivot) j--; // until meet the less one, keep move j to the left
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]); // swap the pivot and middle element
    // do quick sort for new interval divided by pivot
    QuickSort(arr, left, j - 1); 
    QuickSort(arr, j + 1, right);
}

// compare function for qsort
int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main( ) {
    srand(time(NULL));
    double start, end; // start and end to calculate the execution time
    double total_time[5];
    for (int i = 0 ; i < 5 ; i++) {
        total_time[i] = 0.0;
    }
    
    for (int times = 0 ; times < 10 ; times++) {
        // selection sort
        ifstream in; // file pointer to open the input.txt 
        int size;
        in.open("input.txt");
        in >> size; // input size
        int *arr = new int[size];
        for (int i = 0 ; i < size ; i++) {
            in >> arr[i];
        }
        in.close( );

        start = clock( ); // record the start time
        selectionSort(arr, size);
        end = clock( ); // record the end time
        total_time[0] += (end - start) / CLOCKS_PER_SEC; // sum up time

        ofstream out;
        out.open("outputA.txt"); // open outputA.txt to print out the result after sorting
        out << "Insertion Sort" << endl;
        for (int i = 0 ; i < size ; i++) {
            out << arr[i] << " ";
        }
        out.close( );


        // Heap sort
        in.open("input.txt");
        in >> size;
        for (int i = 0 ; i < size ; i++) {
            in >> arr[i];
        }
        in.close( );

        start = clock( ); // record the start time
        heapSort(arr, size);
        end = clock( ); // record the end time
        total_time[1] += (end - start) / CLOCKS_PER_SEC; // sum up time

        out.open("outputB.txt"); // open outputB.txt to print out the result after sorting
        out << "Heap Sort" << endl;
        for (int i = 0 ; i < size ; i++) {
            out << arr[i] << " ";
        }
        out.close( );


        // Quick sort
        in.open("input.txt");
        in >> size;
        for (int i = 0 ; i < size ; i++) {
            in >> arr[i];
        }
        in.close( );

        start = clock( ); // record the start time
        QuickSort(arr, 0, size - 1);
        end = clock( ); // record the end time
        total_time[2] += (end - start) / CLOCKS_PER_SEC; // sum up time

        out.open("outputC.txt"); // open outputC.txt to print out the result after sorting
        out << "Quick Sort" << endl;
        for (int i = 0 ; i < size ; i++) {
            out << arr[i] << " ";
        }
        out.close( );
    

        // C qsort( )
        in.open("input.txt");
        in >> size;
        for (int i = 0 ; i < size ; i++) {
            in >> arr[i];
        }
        in.close( );

        start = clock( ); // record the start time
        qsort(arr, size, sizeof(int), cmp);
        end = clock( ); // record the end time
        total_time[3] += (end - start) / CLOCKS_PER_SEC; // sum up time

        out.open("outputD.txt"); // open outputD.txt to print out the result after sorting
        out << "C qsort( )" << endl; 
        for (int i = 0 ; i < size ; i++) {
            out << arr[i] << " ";
        }
        out.close( );


        // C++ sort( )
        in.open("input.txt");
        in >> size;
        for (int i = 0 ; i < size ; i++) {
            in >> arr[i];
        }
        in.close( );
        start = clock( ); // record the start time
        sort(arr, arr + size);
        end = clock( ); // record the end time
        total_time[4] += (end - start) / CLOCKS_PER_SEC; // sum up time

        out.open("outputE.txt"); // open outputE.txt to print out the result after sorting
        out << "C++ sort( )" << endl;
        for (int i = 0 ; i < size ; i++) {
            out << arr[i] << " ";
        }
        out.close( );
    }

    for (int i = 0 ; i < 5 ; i++) {
        cout << total_time[i] / 10.0 << endl;
    }
    
    return 0;

}