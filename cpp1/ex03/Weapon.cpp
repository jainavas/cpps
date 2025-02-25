#include "Weapon.hpp"

const std::string Weapon::getType()
{
	std::string& s = type;
	return (s);
}

void Weapon::setType( std::string s )
{
	type = s;
}
