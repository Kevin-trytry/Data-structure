// Name : B123040004 ²ø§Ó¤å
// Date : Sept.26, 2024
// Purpose : Create a class to manipulate the operation of sets
 
#include<iostream>
#include<string>
using namespace std;

class set {
    public:
        set( ); //default constructer
        set(const set&); //copy constructor 

        bool check(char ); //check function for input charactor

        set operator +(const set);    //the union operator
        set operator -(const set);    //the except operator
        set operator *(const set);    //the intercept operator
        set& operator =(const set&);  //the assignment operator
        bool operator >=(const set);  //the contain operator

        friend istream& operator >>(istream& inputStream, set& initial); //friend function for input the set
        friend ostream& operator <<(ostream& outputStream, set &output); //friend function for output the set

    private:
        bool ascii[256];
};

//default constructor
set :: set( ) {
    for (int i = 0; i < 256; i++)
    {
        ascii[i] = 0;
    }
}

//copt constructor
set :: set(const set& second) {
    for (int i = 0; i < 256; i++)
    {
        ascii[i] = second.ascii[i];
    }
}

//check function for out input charactor
bool set :: check(char input) {
    int input_ascii = int(input); // transform the input charactor into ascii form
    
    //if it is in the position, return true
    if (ascii[input_ascii] == 1) {
        return true;
    }
    return false;
}

//the union operator
set set :: operator +(const set second) { //second means another set
    set result; //declare a set that we will return
    for (int i = 0; i < 256; i++)
    {
        //check if the position is not empty
        if (ascii[i] == 1 || second.ascii[i] == 1) { 
            //not empty, then the bit is 1
            result.ascii[i] = 1; 
        }
    }
    return result;
}

//the exception operator
set set :: operator -(const set second) { //second means another set
    //declare a set that we will return
    set result; 
    for (int i = 0; i < 256; i++)
    {
        //if the position of the former one exist and the latter does not exist, then the except position is 1
        if (ascii[i] == 1 && second.ascii[i] == 0) {
            result.ascii[i] = 1;
        }
    }
    return result;
}

//the intersection operator
set set :: operator *(const set second) { //second means another set
     //declare a set that we will return
    set result; 
    for (int i = 0; i < 256; i++)
    {
        //if the element exist in both set, then the position is 1
        if (ascii[i] == 1 && second.ascii[i] == 1) {
            result.ascii[i] = 1;
        }
    }
    return result;
}

//assignment operator
set& set :: operator =(const set &second) { //second means another set
    if (this != &second) {
        for (int i = 0; i < 256; i++) {
            ascii[i] = second.ascii[i];
        }
    } 
    return *this;
}

// >> operator
istream& operator >>(istream& inputStream, set& initial) {
    string input;
    getline(cin, input);
    for (int i = 0; i < input.length( ); i++)
    {
        //ignore the '\n' charactor
        if (input[i] != '\n') {
            initial.ascii[int(input[i])] = 1;
        } 
    }
    return inputStream; 
}

// << operator
ostream& operator <<(ostream& outputStream, set& initial) { 
    outputStream << "{";
    for (int i = 0; i < 256; i++)
    {
        //if the position exist, then print out
        if (initial.ascii[i] == 1) {
            outputStream << char(i);
        }
    }
    outputStream << "}";
    return outputStream;
}

//the contain operator
bool set :: operator >=(const set second) {
    for (int i = 0; i < 256; i++) {
        //the former position does not exist but the later does, then the former does not contain the later
        if (ascii[i] == 0 && second.ascii[i] == 1) {
            return false;
        }
    }
    return true;
}

int main( ) {
    int times_of_test; //the number of groups we want to test
    cin >> times_of_test;
    cin.ignore( ); //clear up /r
    for (int i = 0; i < times_of_test; i++) {
        set A, B;   //the initial sets we input 
        char input_char; //the charactor that we want to check
        cin >> A;
        cin >> B;
        cin >> input_char;
        cin.ignore( ); //clear up /r
        cout << endl << "Test Case " << i + 1 << ":" << endl;
        cout << "A: " << A << endl;
        cout << "B: " << B << endl;
        
        //create all kinds of sets
        set C = A + B, D = A * B, E = A - B, F = B - A;
        cout << "A + B: " << C << endl;
        cout << "A * B: " << D << endl;
        cout << "A - B: " << E << endl;
        cout << "B - A: " << F << endl;

        //check if A contains B
        if (A >= B) {
            cout << "A contains B" << endl;
        }
        else { 
            cout << "A does not contain B" << endl;
        }
        
        //check if B contains A
        if (B >= A) {
            cout << "B contains A" << endl;
        }
        else {
            cout << "B does not contain A" << endl;
        }

        //check weather the designed charactor is in A
        if (A.check(input_char)) {
            cout << input_char << " is in A" << endl;
        }
        else {
            cout << input_char << " is not in A" << endl;
        }
        //check weather the designed charactor is in B
        if (B.check(input_char)) {
            cout << input_char << " is in B" << endl;
        }
        else {
            cout << input_char << " is not in B" << endl;
        }

        cout << endl;
    }

    return 0;
}