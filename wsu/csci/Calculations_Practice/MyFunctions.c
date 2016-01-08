#include "MyEquations.h"

/*
Function: calculate_newtons_2nd_law()
Date Created: January 31, 2014
Date Last Modified: February 3, 2014
Description: Calculate Force using Newton's second law
Input Parameters: mass and acceleration of an object
Returns: Force of the object
Preconditions: mass and acceleration
Postconditions: calculated force
*/
double calculate_newtons_2nd_law (double mass, double acceleration)
{
	double force = 0.0;
	force = mass*acceleration;
	return force;
}

/*
Function: calculate_volume_cylinder()
Date Created: January 31, 2014
Date Last Modified: February 3, 2014
Description: Calculate the volume of a cylinder
Input Parameters: radius and height of cylinder
Returns: The volume of the cylinder
Preconditions: Radius, height, and pi
Postconditions: calculated volume of cylinder
*/
double calculate_volume_cylinder (double radius, double height)
{
	double volume_cylinder = 0.0;
	volume_cylinder = PI * (pow(radius,2)) * height;
	return volume_cylinder;
}

/*
Function: perform_character_encoding()
Date Created: January 31, 2014
Date Last Modified: February 3, 2014
Description: Encodes a character value
Input Parameters: Plaintext character to be encoded
Returns: Encoded character
Preconditions: plaintext character
Postconditions: encoded character
*/
char perform_character_encoding (char plaintext_character)
{
	char encoded_character = '\0';
	encoded_character = plaintext_character -'a' + 'A';
	return encoded_character;
}

/*
Function: calculate_gravity_force()
Date Created: January 31, 2014
Date Last Modified: February 3, 2014
Description: Calculates the gravity force between two masses
Input Parameters: mass1, mass2, and distance between masses
Returns: Force of gravity between objects
Preconditions: mass1, mass2, distance, constant value of gravity
Postconditions: Force of gravity between two masses
*/
double calculate_gravity_force (double mass1, double mass2, double distance)
{
	double force = 0.0;
	force = ((G*pow(10.0,-11)) * mass1 * mass2) / (pow(distance,2));
	force = force * pow(10.0,11);
	return force;
}

/*
Function: calculate_resistive_divider()
Date Created: January 31, 2014
Date Last Modified: February 3, 2014
Description: Calculates resistive divider
Input Parameters: resistance1, resistance2, and vin
Returns: vout voltage out
Preconditions: resistance1, resistance2, vin
Postconditions: vout voltage out
*/
double calculate_resistive_divider (double resistance1, double resistance2, double vin)
{
	double vout = 0.0;
	vout = resistance2 / (resistance1+resistance2) * vin;
	return vout;
}

/*
Function: calculate_distance_between_2pts()
Date Created: January 31, 2014
Date Last Modified: February 3, 2014
Description: Calculates the distance between two points
Input Parameters: x1, x2, y1, and y2
Returns: distance between two points
Preconditions: x and y values of 2 different points
Postconditions: distance between two points
*/
double calculate_distance_between_2pts (double x1, double x2, double y1, double y2)
{
	double distance = 0.0;
	distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
	return distance;
}

/*
Function: calculate_general_equation()
Date Created: January 31, 2014
Date Last Modified: February 3, 2014
Description: Calculates the general equation
Input Parameters: a, x, and z
Returns: value y
Preconditions: three values a, x, z, and pi
Postconditions: the value y calculated by the equation
*/
double calculate_general_equation (int a, double x, double z)
{
	double temp = 0.0, y = 0.0;
	temp = (int)a % 2;
	y = (double)7 / 5 * x + z - a /(double)temp + PI;
	return y;
}