// Name : B123040004 ²ø§Ó¤å
// Date : 2024/10/20
// Purpose : Using linked list to perform the polynomial adding and multiplying 

#include<bits/stdc++.h>
using namespace std;

//The node to save the coefficient and exponent
class PolyNode {
    public:
        PolyNode( ); // default constructor 
        PolyNode(int , int); // initial constructor
        
        int coefficient;  
        int exponent;
        PolyNode *next;
};

//default constructor
PolyNode :: PolyNode ( ) : coefficient(0) , exponent(0) , next(nullptr){

}

// initial constructor
PolyNode :: PolyNode(int initial_coefficient , int initial_exponent) : 
        coefficient(initial_coefficient) , exponent(initial_exponent) , next(nullptr) { 
}

//polynomial class
class Poly {
    public:
        Poly( ); //constructor
        ~Poly(); // destructor

        PolyNode *first; //pointer to record the first node

        void addNode(int , int ); // function to add new node
        void deleteNode(PolyNode *, PolyNode *); // function to delete node
        const Poly operator+ (const Poly&); // operator to add two polynomial
        const Poly operator* (const Poly&); // operator to multiply two polynomial
        void clear( ); // function to clear up all the list 
        Poly& operator= (const Poly&); // the assignment operator

        void printPoly( ); // print out the polynomial
};

//constructor
Poly :: Poly( ) : first(nullptr) { 
    
}

// destructor
Poly::~Poly() {
    clear( );
}

// Function to add a new node
void Poly::addNode(int input_coefficient, int input_exponent) {
    if (input_coefficient == 0) return; // if the coefficient is 0, don't insert

    if (first == nullptr) { // if the polynomial is empty, add new node to first
        first = new PolyNode(input_coefficient, input_exponent);
        return;
    }

    // Traverse the list to find the correct position
    PolyNode* current = first; // current to record the current porision
    PolyNode* previous = nullptr; // previous to record the previous position 
    while (current != nullptr && current -> exponent > input_exponent) { //visit the list until the exponent is less than or equal to the input_exponent
        previous = current;
        current = current-> next;
    }

    // If exponent is equal, add the coefficients
    if (current != nullptr && current->exponent == input_exponent) {
        current -> coefficient += input_coefficient;
        if (current -> coefficient == 0) { // if the coefficient is 0, delete the node
            deleteNode(previous, current);
        }
    }
    // If not found, insert a new node
    else {
        PolyNode* temp = new PolyNode(input_coefficient, input_exponent);
        if (previous == nullptr) { // if the previous is at first position, insert a new node before the initial first
            // Insert at the beginning
            temp -> next = first;
            first = temp;
        }
        else { // if it is in the last position, insert in the last position
            previous -> next = temp;
            temp -> next = current;
        }
    }
}

// function to delete a node
void Poly :: deleteNode(PolyNode* previous , PolyNode* current) {
    if (previous == nullptr) first = current -> next; // delete the first node
    else previous -> next = current -> next; // delete a normal node
    delete current;
}

//function to add two polynomial
const Poly Poly :: operator+ (const Poly& second_Poly) {
    Poly result; //the result of adding two polynomial

    // insert the first polynomial
    PolyNode * temp = first; // temp pointer to go through the first polynomial
    while (temp != nullptr) {
        result.addNode(temp -> coefficient, temp -> exponent);
        temp = temp -> next;
    }
    
    // insert another polynomial
    temp = second_Poly.first; // temp pointer to go through the first polynomial
    while (temp != nullptr) {
        result.addNode(temp -> coefficient, temp -> exponent);
        temp = temp -> next;
    }

    return result;
}

// multiplying two polynomial
const Poly Poly :: operator* (const Poly& second_Poly) {
    Poly result; // result of multiplying the two polynomial
    PolyNode *left = first; // pointer in order to visit every node of first polynomial

    while (left != nullptr) {
        PolyNode *right = second_Poly.first; // pointer in order to visit every node of second polynomial
        while (right != nullptr) {
            result.addNode((left -> coefficient) * (right -> coefficient) , (left -> exponent) + (right -> exponent));
            right = right -> next;
        }
        left = left -> next;
    } 

    return result;
}

// function to clear the whole list
void Poly :: clear( ) {
    PolyNode* current = first; // current to visit the list 
    while (current != nullptr) {
        PolyNode* toDelete = current; // toDelete is the node that we want to delete
        current = current->next;
        delete toDelete;
    }
    first = nullptr;
}

Poly& Poly :: operator= (const Poly& second) {
    // if it assign to itself, return itself
    if (this == &second) return *this;

    // clear the initial polynomial
    clear( );

    // copy the node in the second polynomial to first one
    PolyNode *current = second.first; // current to visit every element in the second polynomial
    while (current != nullptr) {
        addNode(current -> coefficient , current -> exponent);
        current = current -> next; 
    }

    return *this; 
}

// function to print out the coefficient and exponent
void Poly::printPoly() {
    PolyNode* current = first; 
    if (first == nullptr) { // If the list is empty, print out 0 0
        cout << "0 0" << endl;
        return;
    }
    while (current != nullptr) {  // not empty, print our the coefficient and exponent of each node
        cout << current->coefficient << " " << current->exponent << endl;
        current = current->next;
    }
    cout << endl;
}

int main( ) {
    int P, Q; // P¡BQ means how many terms of the two polynomial respectively
    int count = 1; // record the n-th test case
    while (true) {
        int input_coefficient, input_exponent; // the coefficient and exponent the user inputs
        cout << "How many terms in polynomial A ? ";
        cin >> P;
        //first polynomial
        Poly first_poly;
        for (int i = 0 ; i < P ; i++) {
            cin >> input_coefficient >> input_exponent;
            first_poly.addNode(input_coefficient , input_exponent);
        }
    
        //second polynomial
        cout << "How many terms in polynomial B ? ";
        cin >> Q;
        Poly second_poly;
        for (int i = 0 ; i < Q ; i++) {
            cin >> input_coefficient >> input_exponent;
            second_poly.addNode(input_coefficient , input_exponent);
        }

        // if both of P and Q are 0, stop the program
        if (P == 0 && Q == 0) break;

        Poly add_result = first_poly + second_poly; // add_result to save the adding
        Poly multiply_result2 = first_poly * second_poly; //multiply to save the multiplying

        // print out the n-th case result
        cout << "Case" << count << " :" << endl;
        cout << "ADD" << endl;
        add_result.printPoly( ); 
        cout << "MULTIPLY" << endl;
        multiply_result2.printPoly( );

        count++;
    }
    

    return 0;
}