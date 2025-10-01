// Name : B123040004 莊志文
// Date : 2024/11/11
// Purpose : Input a list of numeral integers, and find out which one appears odd times

#include<bits/stdc++.h>
using namespace std;

// structure of a node
class TreeNode{
    public:
        TreeNode( ); // constructor to initialize
        TreeNode(int); // constructor to assign an initial value

        int data; // data to save the number
        TreeNode *leftChild, *rightChild; // the link of left and right child
        TreeNode *parent; // the link to record the address of parent
};

// constructor to initialize
TreeNode :: TreeNode( ) : data(0), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {

}

// constructor to assign an initial value
TreeNode :: TreeNode(int input) : data(input), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {

}

// structure of a binary tree
class BinarySearchTree{
    public:
        BinarySearchTree( ); // constructor to initialize

        TreeNode* binarySearch(int, TreeNode*); // function to do binary search
        void insertNode(int, TreeNode*); // funcion to insert a node
        void deleteNode(TreeNode*); // function to delete a node
        TreeNode* InorderSuccessor(TreeNode*); // function to find the inorder successor
        TreeNode* leftMost(TreeNode*); // function to fin the left most node
        void printNode(TreeNode*); // funciton to print out the data of the tree 
        void printLeftChild(TreeNode*); // function to print left child
        void printRightChild(TreeNode*); // function to print right child
        bool isEmpty( ); // function to check weather the tree is empty
        TreeNode *root; // root of the tree
};

// constructor of BunarySearchTree
BinarySearchTree :: BinarySearchTree( ) : root(nullptr) {

}

// function to do binary search
TreeNode* BinarySearchTree :: binarySearch(int goal, TreeNode* root_to_binary_search) {
    if (root_to_binary_search != nullptr) { // There is a data to do comparison
        if (goal > root_to_binary_search -> data) return binarySearch(goal, root_to_binary_search -> rightChild); // Goal is greater than the root, move to rightChild to search
        else if (goal < root_to_binary_search -> data) return binarySearch(goal, root_to_binary_search -> leftChild); // Goal is less than the root, move to leftChild to searc0h
        else return root_to_binary_search; // if find, return the current pointer
    }
    return nullptr; // not find, return a nullptr
}

// function to insert a node
void BinarySearchTree :: insertNode(int input, TreeNode* root_to_insert) {
    if (isEmpty( )) {
        root = new TreeNode(input);
        root -> parent = nullptr;
        return;
    }

    if (input > root_to_insert -> data) { // greater than the root, check right child
        if (root_to_insert -> rightChild != nullptr) insertNode(input, root_to_insert -> rightChild); // RightChild is not empty, then move to rightChild
        else { // If rightChild is empty, insert the new node on the right
            TreeNode *newNode = new TreeNode(input);
            root_to_insert -> rightChild = newNode;
            newNode -> parent = root_to_insert;
            return;
        }
    }
    else { // less than the root, check left child
        if (root_to_insert -> leftChild != nullptr) insertNode(input, root_to_insert -> leftChild); // Left child is not empty, then move to leftChild
        else { // If leftChild is empty, insert the new node on the left
            TreeNode *newNode = new TreeNode(input);
            root_to_insert -> leftChild = newNode;
            newNode -> parent = root_to_insert;
            return;
        }
    }    
}

// function to find the leftMost node 
TreeNode* BinarySearchTree :: leftMost(TreeNode* current) {
    while (current -> leftChild != nullptr) leftMost(current -> leftChild);
    return current;
}

// function to find the inorder succesor
TreeNode* BinarySearchTree :: InorderSuccessor(TreeNode* current) {
    if (current -> rightChild != nullptr) return leftMost(current -> rightChild); // If it has right child, then find the left most node of right child

    TreeNode *successor = current -> parent; // If it has no right child, find the first root on the right of the node 
    while (successor != nullptr && current == successor -> rightChild) {
        current = successor;
        successor = successor -> parent;
    }
    return successor;
}

// function to delete a node
void BinarySearchTree :: deleteNode(TreeNode* root_to_delete) {
    TreeNode *parent = root_to_delete -> parent; 

    if (root_to_delete -> leftChild == nullptr && root_to_delete -> rightChild == nullptr){ // if it has no child, then directly delete the node
        if (parent) { // readdress the link of the parent
              if (parent -> leftChild == root_to_delete) parent -> leftChild = nullptr;
              else parent -> rightChild = nullptr;
        }
        else root = nullptr; // delete the root, then clean up the root
        delete root_to_delete;
    } 
    else if (!root_to_delete -> leftChild || !root_to_delete -> rightChild) { // Node has one child
        TreeNode* child = root_to_delete -> leftChild ? root_to_delete -> leftChild : root_to_delete -> rightChild; // check weather the child is on the left or right

        if (parent) {  // readdress the link of parent
            if (parent -> leftChild == root_to_delete) parent -> leftChild = child; 
            else parent -> rightChild = child;
        } 
        else { // delete the root, then readdress the root to child
            root = child; 
        }
        child -> parent = parent; // readdress the link of child's parent
        delete root_to_delete;
    }
    else { // Meet nonleaf node having two children, find inorder successor to replace the root
        TreeNode* successor = InorderSuccessor(root_to_delete);
        root_to_delete -> data = successor -> data;
        deleteNode(successor);
    }
}

// function to print tree
void BinarySearchTree :: printNode(TreeNode* root_to_print_node) {
    if (isEmpty( )) return; // the tree is empty, there is no need to print

    if (root_to_print_node -> leftChild != nullptr) printNode(root_to_print_node -> leftChild); // First to print the left subtree
    cout << root_to_print_node -> data << " "; // Print out the root
    if (root_to_print_node -> rightChild != nullptr) printNode(root_to_print_node -> rightChild); // Print out the right subtree  
    return; 
}

// function to print left child of the tree
void BinarySearchTree :: printLeftChild(TreeNode* root_to_print_leftChild) {
    if (root_to_print_leftChild == nullptr) return; // if having travel the subtree, return

    printLeftChild(root_to_print_leftChild -> leftChild); // First to print the left child of every node in left subtree
    
    // print the left child of the node
    if (root_to_print_leftChild -> leftChild == nullptr) cout << 0 << " "; 
    else cout << root_to_print_leftChild -> leftChild -> data << " ";
    
    printLeftChild(root_to_print_leftChild -> rightChild); // Print out the left child of every node in the right subtree
    return;
}

// function to print right child of the tree 
void BinarySearchTree :: printRightChild(TreeNode* root_to_print_rightChild) {
    if (root_to_print_rightChild == nullptr) return;

    printRightChild(root_to_print_rightChild -> leftChild); // First to print the right child of every node in left subtree
    
    // print the right child of the node
    if (root_to_print_rightChild -> rightChild == nullptr) cout << 0 << " "; 
    else cout << root_to_print_rightChild -> rightChild -> data << " ";
    
    printRightChild(root_to_print_rightChild -> rightChild); // Print out the right child of every node in the right subtree
    return;
}

// function to check weather the tree is empty
bool BinarySearchTree :: isEmpty( ) {
    if (root == nullptr) return true;
    else return false;
}

int main( ) {
    int input; // Number to input
    while (!cin.eof( )) {
        BinarySearchTree tree; // Build the tree
        while (cin >> input && input != -1) { // Meet -1, break

            // Check if the number appears odd time
            TreeNode* check = tree.binarySearch(input, tree.root); 
            if (check != nullptr) tree.deleteNode(check); // The number is in the tree, then delete the node
            else tree.insertNode(input, tree.root); // Not in the tree, then insert
        }
        if (!cin.eof( )) { // if not meet eof, then print out the BST
            //print out the tree
            cout << "node: ";
            tree.printNode(tree.root);
            cout << endl;

            // print out the left child
            cout << "left: ";
            tree.printLeftChild(tree.root);
            cout << endl;

            // print out the right child
            cout << "right: ";
            tree.printRightChild(tree.root);
            cout << endl;
        }
    }
    
    return 0;
}