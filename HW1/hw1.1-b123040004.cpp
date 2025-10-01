// Name : B123040004 莊志文
// Date : Sept.10, 2024
// Purpose : Build up the odd magic square from 1 * 1 to 9 * 9

#include<iostream>
using namespace std;

void buildMatrix(int n); 
void printMatrix(int **, int);
void deleteTheMatrix(int **, int);

//create the magic square
void buildMatrix(int n) {
	// build up a 2D dynamic array
	int **ArrPtr; 
	ArrPtr = new int*[n]; 
	for (int i = 0; i < n; i++) {
		ArrPtr[i] = new int[n];
	}
	
	//initialization
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == n / 2) { //fill int1 in the NO.2 column of the first row 
				ArrPtr[i][j] = 1;
				continue;
			}
			ArrPtr[i][j] = 0;
		}
	}
	
	int x = 0, y = n / 2; //determine the initial position
	for (int i = 1; i < n * n; i++)
	{
		//save the prevoius position
		int current_x = x, current_y = y; //save the position that we stand
		int k = i + 1; //set up the initial value
		x -= 1, y -= 1; //find the left-up position

		//judge the positive or negative of the coordinate
		if (x < 0) { //if less than 0, than move n steps 
			x += n;
		}
		if (y < 0) {
			y += n;
		}

		//judge weather the left-up position occupied by a data
		if (ArrPtr[x][y] == 0) { //if the position is empty, than fill in k
			ArrPtr[x][y] = k;
		}
		else { //if not empty, fill in k under last number
			ArrPtr[current_x + 1][current_y] = k;
			x = current_x + 1;
			y = current_y;
		}
	}

	printMatrix(ArrPtr, n); //print out the matrix
	deleteTheMatrix(ArrPtr, n); //delete the dynamic matrix
}

//print out the matrix 
void printMatrix(int **arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(3); //set the space for the numbers to fill in
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//delete the dynamic array
void deleteTheMatrix(int **arr, int n) {
	for (int i = 0; i < n; i++) {
		delete arr[i];
	}
	delete [ ] arr;
}

int main( ) {
	//print out the matrix from 1 to 9
	for(int i = 1; i <= 9; i += 2) { 
		cout << i << " x " << i << " Å]¤è°}: " << endl;
		buildMatrix(i);
		cout << endl;
	}

	return 0;
}
