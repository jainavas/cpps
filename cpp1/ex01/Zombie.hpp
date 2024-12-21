#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	void destroy( Zombie *z )
	{
		std::cout << z->name << " destroyed\n";
		delete z;
	}
	void	addname(std::string named)
	{
		name = named;
	}
	Zombie* zombieHorde( int N, std::string name );
	void announce( void );
};


#endif