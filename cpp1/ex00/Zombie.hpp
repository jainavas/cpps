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
	void announce( void );
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
};


#endif