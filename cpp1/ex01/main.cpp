#include "Zombie.hpp"

int	main(void)
{
	Zombie *z = NULL;
	z = z->zombieHorde(5, "paco");
	z[0].announce();
	z[1].announce();
	z[2].announce();
	z[3].announce();
	z[4].announce();
	delete[] z;
}