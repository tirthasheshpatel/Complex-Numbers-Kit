#include "complex.h"
#include <iomanip>
constexpr auto M_PI = 3.14159265358979323846264338327950288419716939937510;


using std::cout; using std::ostream; using std::istream; using std::pair; using std::setprecision;

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

complex operator*=(const complex& a, const complex& b)
{
	return a * b;
}

complex operator+=(const complex& a, const complex& b)
{
	return a + b;
}

bool operator<(const complex& a, const complex& b)
{
	return (a.mod() < b.mod());
}

bool operator>(const complex& a, const complex& b)
{
	return (a.mod() > b.mod());
}

ostream& operator<<(ostream& out,const complex& a)
{
	if (a.im >= 0)
		out << setprecision(3) << a.re << " + " << a.im  << "i";
	else
		out << setprecision(3) << a.re << " - " << abs(a.im) << "i";
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

double complex::arg()
{
	if (re >= 0 && im >= 0)
		return atan(im / re);
	else if (re <= 0 && im >= 0)
		return (M_PI - atan(abs(im / re)));
	else if (re <= 0 && im <= 0)
		return (M_PI + atan(abs(im / re)));
	else if (re >= 0 && im <= 0)
		return (2 * M_PI - atan(abs(im / re)));
	return 0.0;
}

void complex::rotate(double ang)
{
	double new_re = mod()*(cos(arg() + ang));
	double new_im = mod()*(sin(arg() + ang));
	re = new_re; 
	im = new_im;
}

pair<complex, complex> complex::complex_sqrt()
{
	pair<complex, complex> sr;
	sr.first.re = sqrt((mod() + re) / 2);
	sr.first.im = sqrt((mod() - re) / 2);
	if (sr.first.im < 0) { sr.first.im = -sr.first.im; }
	sr.second.re = -sr.first.re;
	sr.second.im = -sr.first.im;
	return sr;
}


complex complex::complex_log() 
{
	complex complex_ln;
	complex_ln.re = log(mod());
	complex_ln.im = arg();
	return complex_ln;
}
