#include "Header.h"

Complex::Complex()
{
	real = 0.0;
	imaginary = 0.0;
}

Complex::Complex (double newReal, double newImaginary)
{
	real = newReal;
	imaginary = newImaginary;
}

Complex::~Complex()
{}

void Complex::setReal (double newReal)
{
	real = newReal;
}

void Complex::setImaginary (double newImaginary)
{
	imaginary = newImaginary;
}

double Complex::getReal ()
{
	return real;
}

double Complex::getImaginary ()
{
	return imaginary;
}

void Complex::add (Complex n1, Complex n2)
{
	real = n1.real + n2.real;
	imaginary = n1.imaginary + n2.imaginary;
}

void Complex::subtract (Complex n1, Complex n2)
{
	real = n1.real - n2.real;
	imaginary = n1.imaginary - n2.imaginary;
}

void Complex::printComplex()
{
	cout << real << " | " << imaginary << endl;
}

Complex & Complex::operator= (Complex &rhs)
{
	real = rhs.real;
	imaginary = rhs.imaginary;
	
	return (*this);
}

Complex & Complex::operator+ (Complex &rhs)
{
	Complex result(0.0,0.0);

	result.real = real + rhs.real;
	result.imaginary = real + rhs.imaginary;

	return result;
}

Complex & Complex::operator- (Complex &rhs)
{
	Complex result(0.0,0.0);

	result.real = real -  rhs.real;
	result.imaginary = real - rhs.imaginary;

	return result;
}