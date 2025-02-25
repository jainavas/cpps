#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " have no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanA " << name << " destroyed" << std::endl;
}