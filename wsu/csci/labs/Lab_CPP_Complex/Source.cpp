#include "Header.h"

int main(void)
{
	Complex number1(10.0, 3.3);
	Complex number2(1.1, 2.2);
	Complex number3;

	number3.setReal(6.9);
	number3.setImaginary(1.2);

	number2.printComplex();

	number2 = number2 + number1;

	number2.printComplex();

	number2 = number2 - number1;

	number2.printComplex();

	return 0;
}