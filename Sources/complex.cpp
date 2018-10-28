#include "pch.h"
#include "complex.h"

using std::cout; using std::ostream;using std::istream;

complex conjugate(const complex& a)
{
	return complex(a.re, -a.im);
}

complex operator*(const complex& a, const complex& b)
{
	return complex(a.re*b.re - a.im*b.im , a.re*b.im + a.im*b.re);
}

complex operator+(const complex& a, const complex& b)
{
	return complex(a.re + b.re, a.im + b.im);
}

complex operator-(const complex& a, const complex& b)
{
	return complex(a.re - b.re, a.im - b.im);
}

complex operator/(const complex& a, const complex& b)
{
	complex num = a * b.conjugate();
	double den = b.mod()*b.mod();
	return complex(num.re / den, num.im / den);
}

bool operator<(const complex& a, const complex& b)
{
	return (a.mod() < b.mod());
}

bool operator>(const complex& a, const complex& b)
{
	return (a.mod() > b.mod());
}

ostream& operator<<(ostream& out, const complex& a)
{
	if (a.im >= 0)
		out << a.re << " + " << a.im << "i";
	else
		out << a.re << " - " << abs(a.im) << "i";
	return out;
}

istream& operator>>(istream& in, complex& a)
{
	in >> a.re >> a.im;
	return in;
}

bool operator==(const complex& a, const complex& b)
{
	return (a.re == b.re && a.im == b.im);
}

bool operator!=(const complex& a, const complex& b)
{
	return !(a == b);
}

void complex::rotate(double ang)
{
	double new_re = mod()*(cos(arg() + ang));
	double new_im = mod()*(sin(arg() + ang));
	re = new_re; 
	im = new_im;
}