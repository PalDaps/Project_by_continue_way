#include <iostream>
#include <string>

//
// Link the following classes into the inheritance hierarchy: 
// Character (Character), Long Range, 
// Wizard, SwordsMan, Archer
//
struct Character
{
	std::string const & name() const;
	int health() const;
};

struct LongRange : Character
{
	int range() const;
};

struct SwordsMan : Character
{
	int strength() const;
};

struct Wizard : LongRange
{
	int mana() const;
};

struct Archer : LongRange
{
	int accuracy() const;
};


int main()
{
	return 0;
}