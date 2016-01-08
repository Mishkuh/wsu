 #include <iostream>
 
using std::cout;
using std::endl;
using std::string;
 
class Base
{
      public:
           virtual void testFunction ();
};
 
class Derived : public Base
{
      public:
            void testFunction ();
};

class Mammal
{
      public:
            Mammal(void);
            ~Mammal(void);
 
            virtual void Move() const;
            virtual void Speak() const;
 
      protected:
            int itsAge;
};

class Dog : public Mammal
{
public:
	Dog();
	~Dog();

	void Move();
	void Speak();

private:
	string name;
};