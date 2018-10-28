#ifndef GUARD_COMPLEX_H
#define GUARD_COMPLEX_H

#include <iostream>
#include <math.h>

class complex
{
public:
	complex(double r, double i) { re = r ; im = i ; }
	complex(double r) { re = r; im = 0; }
	complex() { re = 0; im = 0; }
	friend complex operator+(const complex&,const complex&);
	friend complex operator-(const complex&, const complex&);
	friend complex operator*(const complex&, const complex&);
	friend complex operator/(const complex&, const complex&);
	friend complex operator*=(const complex&, const complex&);
	friend complex operator+=(const complex&, const complex&);
	friend bool operator<(const complex&, const complex&);
	friend bool operator>(const complex&, const complex&);
	friend bool operator==(const complex&, const complex&);
	friend bool operator!=(const complex&, const complex&);
	friend std::ostream& operator<<(std::ostream&, const complex&);
	friend std::istream& operator>>(std::istream&, complex&);
public:
	double mod() const { return sqrt(re*re + im*im); }
	complex conjugate() const { return complex(re, -im); }
	double arg();
	void rotate(double);
	std::pair<complex, complex> complex_sqrt();
	complex complex_log();
public:
	double re, im;
};

#endif