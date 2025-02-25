#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon(const std::string& name) : type(name) {}
	const std::string getType();
	void setType( std::string s);
};
