#include<bits/stdc++.h>
using namespace std;

int main( ) {
    int right_most_x, up_most_y;
    int initial_x, initial_y;
    char initial_direction;
    
    while(cin >> right_most_x >> up_most_y){
        while (cin >> initial_x >> initial_y >> initial_direction) {
            string ways_of_steps;
            getline(cin >> ws, ways_of_steps);

            char map[up_most_y + 1][right_most_x + 1];
            for (int i = 0 ; i < up_most_y ; i++) {
                for (int j = 0 ; j < right_most_x ; j++) {
                    if (initial_x == j && initial_y == 3 - i) map[i][j] = initial_direction;
                    else map[i][j] = ' ';
                } 
            }

            for (int i = 0 ; i < ways_of_steps.length( ) ; i++) {
                
            }
        }
    }
}