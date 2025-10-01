#include<iostream>
#include<iomanip>
using namespace std;

int main( ) {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        double fourth_x = 0, fourth_y = 0;
        if (x1 == x3 && y1 == y3) {
            fourth_x = x1, fourth_y = y1;
            fourth_x += (x2 - x1) + (x4 - x1);
            fourth_y += (y2 - y1) + (y4 - y1);
        }
        else if (x1 == x4 && y1 == y4) {
            fourth_x = x1, fourth_y = y1;
            fourth_x += (x2 - x1) + (x3 - x1);
            fourth_y += (y2 - y1) + (y3 - y1);
        }
        else if (x2 == x3 && y2 == y3) {
            fourth_x = x2, fourth_y = y2;
            fourth_x += (x1 - x2) + (x4 - x2);
            fourth_y += (y1 - y2) + (y4 - y2);
        }
        if (x2 == x4 && y2 == y4) {
            fourth_x = x2, fourth_y = y2;
            fourth_x += (x1 - x2) + (x3 - x2);
            fourth_y += (y1 - y2) + (y3 - y2);
        }
        
        cout << fixed << setprecision(3) << fourth_x << " " << fixed << setprecision(3) << fourth_y << endl;
    }

    return 0;
}