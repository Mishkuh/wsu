/*
	Programmer: Michael Wiens
	Class: CptS 121, Spring 2014; Section 6
	Date: February, 2014
	Description: A program that performs various equations
				 by using functions to perform calculations.
*/

#include "MyEquations.h"

int main(void){

	double y, x, z, a, x1, x2, y1, y2, vout, r1, r2, vin, force, 
		   force2, mass, mass1, mass2, acceleration,
		   volume_cylinder, radius, height, distance;
	int temp;
	char plaintext_character='\0', encoded_character='\0';

	/* Newton’s Second Law of Motion: force = mass * acceleration */

	printf("Enter a floating point value for mass: ");
	scanf("%lf", &mass);
	printf("Enter a floating point value for acceleration: ");
	scanf("%lf", &acceleration);

	force = calculate_newtons_2nd_law(mass, acceleration);

	printf("Newton’s Second Law of Motion: mass*acceleration = force\n");
	printf("%.1lfx%.1lf = %.2lf", mass, acceleration, force);

	/* Volume of a cylinder: volume_cylinder = PI * radius2 * height */

	printf("\n\nEnter a floating point value for radius: ");
	scanf("%lf", &radius);
	printf("Enter a floating point value for height: ");
	scanf("%lf", &height);

	volume_cylinder = calculate_volume_cylinder(radius, height);

	printf("Volume of a cylinder: PI * radius^2 * height = volume_cylinder\n");
	printf("PI*(%.1lf^2)*%.1lf = %.2lf", radius, height, volume_cylinder);

	/* Character encoding: encoded_character = (plaintext_character - 'a') + 'A' */

	printf("\n\nEnter a plain text character: ");
	scanf(" %c", &plaintext_character);

	encoded_character = perform_character_encoding(plaintext_character);

	printf("Encoded Character: %c", encoded_character);

	/* Gravity: force = G * mass1 * mass2 / distance2, where G is the gravitational constant with value 6.67 * 10-11 */

	printf("\n\nEnter a floating point value for mass1: ");
	scanf("%lf", &mass1);
	printf("Enter a floating point value for mass2: ");
	scanf("%lf", &mass2);
	printf("Enter a floating point value for distance: ");
	scanf("%lf", &distance);

	force2 = calculate_gravity_force(mass1, mass2, distance);

	printf("Gravity: G*mass1*mass2/distance^2 = force\n");
	printf("(6.67x10^-11)*%.1lf*%.1lf/%.1lf^2 = %.2lf*10^-11", mass1, mass2, distance, force2);

	/* Resistive divider: vout = r2 / (r1 + r2) * vin */

	printf("\n\nEnter a floating point value for r1: ");
	scanf("%lf", &r1);
	printf("Enter a floating point value for r2: ");
	scanf("%lf", &r2);
	printf("Enter a floating point value for vin: ");
	scanf("%lf", &vin);

	vout = calculate_resistive_divider(r1, r2, vin);

	printf("Resistive divider: r2/(r1+r2)*vin = vout\n");
	printf("%.1lf/(%.1lf+%.1lf)*%.1lf = %.2lf", r2, r1, r2, vin, vout);

	/* Distance between two points: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2)*/

	printf("\n\nEnter a floating point value for x1: ");
	scanf("%lf", &x1);
	printf("Enter a floating point value for x2: ");
	scanf("%lf", &x2);
	printf("Enter a floating point value for y1: ");
	scanf("%lf", &y1);
	printf("Enter a floating point value for y2: ");
	scanf("%lf", &y2);

	distance = calculate_distance_between_2pts(x1, x2, y1, y2);

	printf("Distance between two points: distance = square root of ((x1-x2)^2+(y1-y2)^2)\n");
	printf("sqrt(%.1lf-%.1lf)^2+(%.1lf-%.1lf)^2 = %.2lf", x1, x2, y1, y2, distance);

	/* General equation: y = (7 / 5) * x + z - a / (a % 2) + PI (recall: a is an integer; the 7 and 5 constants in the equation should be left as integers initially, but explicitly type-casted as floating-point values) */

	printf("\n\nEnter a floating point value for x: ");
	scanf("%lf", &x);
	printf("Enter a floating point value for z: ");
	scanf("%lf", &z);
	printf("Enter a floating point value for a: ");
	scanf("%lf", &a);

	y = calculate_general_equation(a,x,z);

	printf("General equation: (7/5) * x + z - a / (a%%2) + PI = y\n");
	printf("(7/5)*%.1lf+%.1lf-%.1lf / (%.1lf%%2) + Pi = %.2lf\n", x, z, a, a, y);

	return 0;
}