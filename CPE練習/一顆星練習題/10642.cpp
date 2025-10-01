#include<iostream>
using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, count = 1;
    cin >> n;
    while(n--) {
        int x1, y1, x2, y2;
        cin.ignore( );
        cin >> x1 >> y1 >> x2 >> y2; 

        int origin_line = x1 + y1, final_line = x2 + y2;
        int origin_x = 0, origin_y = origin_line;
        int final_x = final_line, final_y = 0;
        long long steps = 0;
        for (int i = origin_line; i <= final_line; i++) {
            steps += i + 1;
        }
        while(origin_x != x1 ) {
            origin_x += 1;
            origin_y -= 1;
            steps --;
        }
        while(final_x != x2) {
            final_x -= 1;
            final_y += 1;
            steps --;
        }
        
        cout << "Case " << count << ": " << steps - 1 << endl;
        count++;
    }

    return 0;
}