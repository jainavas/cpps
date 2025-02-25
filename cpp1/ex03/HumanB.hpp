#include <string>
#include <iostream>
#include "HumanA.hpp"

class HumanB
{
private:
	std::string name;
	Weapon* weapon;
public:
	HumanB(const std::string& name, Weapon* weapon) : name(name), weapon(weapon) {}
	~HumanB(void);
	void setWeapon(Weapon& newWeapon);
	void attack();
};
