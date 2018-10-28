#include <iostream>
#include "complex.h"
#define M_PI 3.14159265358979323846

using std::cout; using std::cin; using std::endl;

int main(int argc, char* argv[])
{
	double angle;
	complex a;
	cin >> a;
	complex d = 1 / a;
	double arg_rad = a.arg();
	double arg_deg = arg_rad * (180/M_PI);
	cout << "The complex number : " << a << endl;
	cout << "The inverse of the complex number : " << d << endl;
	cout << "The angle that the complex number makes with the real axis is : " << arg_deg << endl;
	cout << "Enter the angle(in degrees) by which you want to rotate the vector: " << endl;
	cin >> angle;
	double angle_rad = angle*(M_PI/180);
	a.rotate(angle_rad);
	cout << "The rotated vector looks loke : " << a << endl;
}
