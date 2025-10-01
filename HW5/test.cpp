#include<bits/stdc++.h>
using namespace std;

// The node to save the coefficient and exponent
class PolyNode {
public:
    PolyNode(); // default constructor 
    PolyNode(int, int); // initial constructor
    int coefficient; 
    int exponent;
    PolyNode* next;
};

// Default constructor
PolyNode::PolyNode() : coefficient(0), exponent(0), next(nullptr) {}

// Initial constructor
PolyNode::PolyNode(int initial_coefficient, int initial_exponent)
    : coefficient(initial_coefficient), exponent(initial_exponent), next(nullptr) {}

// Polynomial class
class Poly {
public:
    Poly(); // constructor
    Poly(const Poly&); // copy constructor
    ~Poly(); // destructor

    PolyNode* first; // pointer to record the first node

    void addNode(int, int); // function to add new node
    void deleteNode(PolyNode*, PolyNode*); // function to delete node
    const Poly operator+ (const Poly&); // operator to add two polynomials
    const Poly operator* (const Poly&); // operator to multiply two polynomials
    void clear(); // function to clear up all the list 
    Poly& operator= (const Poly&); // the assignment operator

    void printPoly(); // print out the polynomial
};

// Constructor
Poly::Poly() : first(nullptr) {}

// Copy constructor
Poly::Poly(const Poly& other) : first(nullptr) {
    PolyNode* current = other.first;
    while (current != nullptr) {
        addNode(current->coefficient, current->exponent);
        current = current->next;
    }
}

// Destructor
Poly::~Poly() {
    clear();
}

// Function to add a new node
void Poly::addNode(int input_coefficient, int input_exponent) {
    if (input_coefficient == 0) return; // if the coefficient is 0, don't insert

    if (first == nullptr) {
        first = new PolyNode(input_coefficient, input_exponent);
        return;
    }

    // Traverse the list to find the correct position
    PolyNode* current = first;
    PolyNode* previous = nullptr;

    while (current != nullptr && current->exponent > input_exponent) {
        previous = current;
        current = current->next;
    }

    // If exponent is equal, add the coefficients
    if (current != nullptr && current->exponent == input_exponent) {
        current->coefficient += input_coefficient;
        if (current->coefficient == 0) {
            deleteNode(previous, current);
        }
    }
    // If not found, insert a new node
    else {
        PolyNode* temp = new PolyNode(input_coefficient, input_exponent);
        if (previous == nullptr) {
            // Insert at the beginning
            temp->next = first;
            first = temp;
        }
        else {
            previous->next = temp;
            temp->next = current;
        }
    }
}

// Function to delete a node
void Poly::deleteNode(PolyNode* previous, PolyNode* current) {
    if (previous == nullptr) {
        // Deleting the first node
        first = current->next;
    }
    else {
        previous->next = current->next;
    }
    delete current;
}

// Operator+ to add two polynomials
const Poly Poly::operator+ (const Poly& second_Poly) {
    Poly result;

    // Insert the first polynomial
    PolyNode* temp = first;
    while (temp != nullptr) {
        result.addNode(temp->coefficient, temp->exponent);
        temp = temp->next;
    }

    // Insert the second polynomial
    temp = second_Poly.first;
    while (temp != nullptr) {
        result.addNode(temp->coefficient, temp->exponent);
        temp = temp->next;
    }

    return result;
}

// Operator* to multiply two polynomials
const Poly Poly::operator* (const Poly& second_Poly) {
    Poly result;

    PolyNode* left = first;
    while (left != nullptr) {
        PolyNode* right = second_Poly.first;
        while (right != nullptr) {
            int new_coefficient = left->coefficient * right->coefficient;
            int new_exponent = left->exponent + right->exponent;
            result.addNode(new_coefficient, new_exponent);
            right = right->next;
        }
        left = left->next;
    }

    return result;
}

// Function to clear the linked list
void Poly::clear() {
    PolyNode* current = first;
    while (current != nullptr) {
        PolyNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    first = nullptr;
}

// Assignment operator
Poly& Poly::operator= (const Poly& second) {
    // Self-assignment check
    if (this == &second) return *this;

    // Clear the existing list
    clear();

    // Deep copy the second polynomial
    PolyNode* current = second.first;
    while (current != nullptr) {
        addNode(current->coefficient, current->exponent);
        current = current->next;
    }

    return *this;
}

// Function to print the polynomial
void Poly::printPoly() {
    PolyNode* current = first;
    bool isFirst = true;
    while (current != nullptr) {
        if (!isFirst) {
            cout << " + ";
        }
        cout << current->coefficient << "x^" << current->exponent;
        isFirst = false;
        current = current->next;
    }
    if (isFirst) { // If the polynomial is empty
        cout << "0";
    }
    cout << endl;
}

int main() {
    int P, Q; // P and Q represent the number of terms in the two polynomials respectively
    int count = 1; // Record the nth test case

    while (true) {
        int input_coefficient, input_exponent; // The coefficient and exponent the user inputs

        cout << "How many terms in polynomial A? ";
        cin >> P;
        if (!cin) { // Handle invalid input
            cerr << "Invalid input for P." << endl;
            break;
        }

        // First polynomial
        Poly first_poly;
        for (int i = 0; i < P; i++) {
            cin >> input_coefficient >> input_exponent;
            if (!cin) { // Handle invalid input
                cerr << "Invalid input for polynomial A." << endl;
                break;
            }
            first_poly.addNode(input_coefficient, input_exponent);
        }

        cout << "How many terms in polynomial B? ";
        cin >> Q;
        if (!cin) { // Handle invalid input
            cerr << "Invalid input for Q." << endl;
            break;
        }

        // Second polynomial
        Poly second_poly;
        for (int i = 0; i < Q; i++) {
            cin >> input_coefficient >> input_exponent;
            if (!cin) { // Handle invalid input
                cerr << "Invalid input for polynomial B." << endl;
                break;
            }
            second_poly.addNode(input_coefficient, input_exponent);
        }

        // If both P and Q are 0, stop the program
        if (P == 0 && Q == 0) break;

        // Perform addition and multiplication
        Poly add_result = first_poly + second_poly;
        Poly multiply_result = first_poly * second_poly;

        // Output the results
        cout << "Case " << count << ":" << endl;
        cout << "ADD" << endl;
        add_result.printPoly();
        cout << "MULTIPLY" << endl;
        multiply_result.printPoly();

        count++;
    }

    return 0;
}


//function to add new node
void Poly :: addNode(int input_coefficient , int input_exponent ) {
    if (input_coefficient == 0) return; //if the coefficient is 0, than we don't need to insert
    else if (first == nullptr) first = new PolyNode(input_coefficient , input_exponent); //if there is no node, then assign it to first
    else {
        //if not empty, then go through the link list
        PolyNode *current = first; // current pointer means the node that we are at
        PolyNode *previous = nullptr; // previous means last node
        while(current != nullptr && current -> exponent > input_exponent) { // if the current exponent is greater than input, pass to next
            previous = current;
            current = current -> next;
        }
        
        // if exponent is equal, than plus the coefficient
        if (current != nullptr && current -> exponent == input_exponent) {
            current -> coefficient += input_coefficient;
            if (current -> coefficient == 0) deleteNode(previous , current); // coefficient is 0, than delete the node
        }
        //if meet with the last one and no match any node, than add a new on in the last
        else if (current == nullptr) {
            PolyNode *temp = new PolyNode(input_coefficient, input_exponent);
            if (previous == nullptr) first = temp;
            else previous -> next = temp;
        }
        // if less than current one, than insert before it.
        else {
            PolyNode *temp = new PolyNode(input_coefficient, input_exponent);
            if (previous == nullptr) first = temp;
            else {
                previous -> next = temp;
                temp -> next = current;
            }
        }
    }
}

// Function to add a new node
void Poly::addNode(int input_coefficient, int input_exponent) {
    if (input_coefficient == 0) return; // if the coefficient is 0, don't insert

    if (first == nullptr) {
        first = new PolyNode(input_coefficient, input_exponent);
        return;
    }

    // Traverse the list to find the correct position
    PolyNode* current = first;
    PolyNode* previous = nullptr;

    while (current != nullptr && current->exponent > input_exponent) {
        previous = current;
        current = current-> next;
    }

    // If exponent is equal, add the coefficients
    if (current != nullptr && current->exponent == input_exponent) {
        current -> coefficient += input_coefficient;
        if (current -> coefficient == 0) {
            deleteNode(previous, current);
        }
    }
    // If not found, insert a new node
    else {
        PolyNode* temp = new PolyNode(input_coefficient, input_exponent);
        if (previous == nullptr) {
            // Insert at the beginning
            temp->next = first;
            first = temp;
        }
        else {
            previous->next = temp;
            temp->next = current;
        }
    }
}