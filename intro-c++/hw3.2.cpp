// Date Created: March 13, 2026 - 10:56pm
// Date Updated: 
// hw3: intro_c++.polygon calculator

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int apothem(int s, int n) {
    int aptm; float pi = 3.14159265358979323846;
    aptm = s / (2*tan(pi/n));

    return aptm;
}
int interior_angle(int n) {
    int i_angle;
    i_angle = (180*(n-2))/n;

    return i_angle;
}

int main(){

}