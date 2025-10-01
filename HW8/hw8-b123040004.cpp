#include<bits/stdc++.h>
using namespace std;

// function to compress the file
void compress(const string &input_file, const string &output_file) {
    ifstream file(input_file, std :: ios :: binary); // readin the txt file as binary mode
    if (!file) {
        cout << "The file does not exist.";
        return;
    }

    // calculate the frequency
    map<char, int> frequency;
    char readin;
    while(!file.get(readin)) frequency[readin]++;

    
    
    
}

int main(int argc, char* argv[ ]) {
    string filename;
    int selection;
    cout << "Enter the action that you want to do: " << endl;
    cout << "EOF : End the program.\n";
    cout << "1 : Compress a file.\n";
    cout << "2 : Uncompress a file.\n";
    while(cin >> selection) {
        if (selection == 1) {
            cout << "Choose the file that you want to compress: ";
            cin >> filename;
        }


    }
    

}