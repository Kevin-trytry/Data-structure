#include<bits/stdc++.h>
using namespace std;

void initialize_die(int die[ ]) {
    die[0] = 1, die[5] = 6;
    die[2] = 2, die[4] = 5;
    die[3] = 3, die[1] = 4;
}

void change_state(int die[ ], string direction) {
    if (direction == "north") {
        int temp1 = die[0], temp2 = die[2], temp3 = die[5], temp4 = die[4];
        die[0] = temp4;
        die[2] = temp1;
        die[5] = temp2;
        die[4] = temp3;
    }
    else if (direction == "south") {
        int temp1 = die[0], temp2 = die[2], temp3 = die[5], temp4 = die[4];
        die[0] = temp2;
        die[2] = temp3;
        die[5] = temp4;
        die[4] = temp1;
    }
    else if (direction == "east") {
        int temp1 = die[0], temp2 = die[1], temp3 = die[5], temp4 = die[3];
        die[0] = temp4;
        die[1] = temp1;
        die[5] = temp2;
        die[3] = temp3;
    }
    else if (direction == "west"){
        int temp1 = die[0], temp2 = die[1], temp3 = die[5], temp4 = die[3];
        die[0] = temp2;
        die[1] = temp3;
        die[5] = temp4;
        die[3] = temp1;
    }
}

int main( ) {
    ios :: sync_with_stdio(NULL);
    cin.tie(0);

    int die[6]; // 0:top, 1:right, 2:front, 3:left, 4:back, 5:bottom 
    int times;
    while(cin >> times) {
        if (times == 0) break;
        vector<pair<string, int>> current_state;
        string input;
        initialize_die(die);

        for (int i = 0 ; i < times ; i++) {
            getline(cin >> ws, input);
            change_state(die, input);
        }
        cout << die[0] << endl;
    } 
}