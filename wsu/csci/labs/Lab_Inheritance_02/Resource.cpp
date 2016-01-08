// Task1.cpp
 
#include "Header.h"
 
void Base::testFunction ()
{
    cout << "Base class" << endl;
}
 
void Derived::testFunction ()
{
    cout << "Derived class" << endl;
}
 
Mammal::Mammal(void):itsAge(1)
{
      cout << "Mammal constructor..." << endl;
}
 
Mammal::~Mammal(void)
{
      cout << "Mammal destructor..." << endl;
}
 
void Mammal::Move() const
{
      cout << "Mammal moves a step!" << endl;
}
 
void Mammal::Speak() const
{
      cout << "What does a mammal speak? Mammilian!" << endl;
}
 
Dog::Dog()
{
}

Dog::~Dog()
{
}

void Dog::Move()
{
      cout << "Dog moves a step!" << endl;
}
 
void Dog::Speak()
{
      cout << "What does a Dog speak? Dogish!" << endl;
}
