#include<iostream>
#include<string>
using namespace std;

int main( ) {
    while(!cin.eof( )) {
        string first, second;
        getline(cin, first);
        getline(cin, second);

        int alphabet_table_first[26] = {0}, alphabet_table_second[26] = {0};
        for (int i = 0; i < first.length(); i++) {
            alphabet_table_first[int(first[i]) - 97] += 1;
        }
        for (int i = 0; i < second.length(); i++) {
            alphabet_table_second[int(second[i]) - 97] += 1;
        }

        for (int i = 0; i < 26; i++) {
            if (alphabet_table_first[i] > 0 && alphabet_table_second[i] > 0) {
                if(alphabet_table_first[i] < alphabet_table_second[i]) {
                    for (int j = 0; j < alphabet_table_first[i]; j++) {
                        cout << char(i + 97);
                    }
                }
                else {
                    for (int j = 0; j < alphabet_table_second[i]; j++) {
                        cout << char(i + 97);
                    }
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}