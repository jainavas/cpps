#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}
	~HumanA(void);
	void attack();
};
