#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie *z = newZombie(name);
	z->announce();
	destroy(z);
}
