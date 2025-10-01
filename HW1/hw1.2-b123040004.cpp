// Name : B123040004 ²ø§Ó¤å
// Date : Sept.19, 2024
// Purpose : print out the factorial and the maximum is 50!

#include<iostream>
using namespace std;

//calaulate the factorial
void factorial(int N) {
    int result[100]; //build up an large enough array to save the digits
    for (int i = 0; i < 100; i++) { //initialization
        result[i] = 0;
    }
    result[99] = 1; // set up 0! number
    
    
    for(int i = 1; i <= N; i++) { //record the number being calculated
        int number_of_digits; //number_of_digits is to record how many digits is not 0 
        for(int i = 0; i < N; i++) {
            if (result[i] != 0) {
                number_of_digits = N - i + 1;
                break;
            }
        }

        for(int j = 99; j >= N - number_of_digits; j--) { //multiplication
            result[j] *= i;
        }
        
        //calculate the carry
        for (int j = 99; j >= number_of_digits; j--) {
            int temp = result[j];  //set up a temp to save a digit
            result[j] = temp % 10; //get the number of the current digit
            temp /= 10;            //pick up the carry
            result[j - 1] += temp; //sum up the carry to the next digit
        }

        //print out the number
        int flag = 0;
        cout << i << "!=" ;
        for (int j = 0; j < 100; j++) {
            if(result[j] != 0) flag = 1;      
        
            if (flag == 0) continue;
            else cout << result[j] ; 
        }
        cout << endl;
    }
    
}

int main( ) {
    int N; //The maximum factorial number
    cout << "Please the number to print out the factorial from 1 to N (1 <= N <= 50, enter 0 to finish) : ";
    cout << endl;
    cin >> N;
    while (N != 0) { //If N is not 0, keep entering the factorial number
        factorial(N); //call the factorial function
        cout << endl;
        cout << "Please the number to print out the factorial from 1 to N (1 <= N <= 50, enter 0 to finish) :";
        cout << endl;
        cin >> N;
    }
    
    return 0;
}