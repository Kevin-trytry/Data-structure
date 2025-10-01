#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main( ) {
    long long int r, angle;
    string unit;
    while(cin >> r >> angle >> unit) {
        double the_angle;
        r += 6440;
        if (unit == "deg") the_angle = angle * 1.0;
        else the_angle = angle * 1.0 / 60;
        while (the_angle > 360) {
            the_angle -= 360;
        }
        if (the_angle > 180) the_angle = 360 - the_angle;

        cout << fixed << setprecision(6) << M_PI * 2 * r * the_angle / 360 << " " << fixed << setprecision(6) << r * sqrt(2 - 2 * cos(the_angle * M_PI / 180)) << endl;
    }
    
    return 0;
}