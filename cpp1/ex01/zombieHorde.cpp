#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie *z;
	z = new Zombie[N];
	for (int i = 0; i < N ;i++)
	{
		z[i].addname(name);
	}
	return (z);
}