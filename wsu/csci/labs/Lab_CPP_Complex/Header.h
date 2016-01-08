#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Complex
{
	public:
		Complex();
		Complex(double real, double imaginary);
		~Complex();
		void setReal(double real);
		void setImaginary(double imaginary);
		double getReal();
		double getImaginary();
		void add(Complex n1, Complex n2);
		void subtract(Complex n1, Complex n2);
		void printComplex();
		Complex & operator= (Complex &rhs);
		Complex & operator+ (Complex &rhs);
		Complex & operator- (Complex &rhs);

	private:
		double real;
		double imaginary;
};