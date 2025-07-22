#include "unit.h"


unit::unit(int h, int p, int id, int atk, int j,Game* r_pGame)
{
	health = h;
	power = p;
	ID = id;
	Atk_cap = atk;
	join_time = j;
	pGame = r_pGame;
}

void unit::sethealth(int h)
{
	health = h;
}
void unit::setpower(int p)
{
	power = p;
}
void unit::setID(int id)
{
	ID = id;
}
void unit::setatk_cap(int atk)
{
	Atk_cap = atk;
}
void unit::setjoin_time(int j)
{
	join_time = j;
}

//Game* unit::getGame()
//{
//	return g;
//}


int unit::gethealth()
{
	return health;
}
int unit::getpower()
{
	return power;
}
int unit::getID()
{
	return ID;
}
int unit::getatk_cap()
{
	return Atk_cap;
}
int unit::getjoin_time()
{
	return join_time;
}
bool unit::operator==(unit& other)
{
	return (this->gethealth() == other.gethealth() && this->getpower() == other.getpower() && this->getID() == other.getID() && this->getatk_cap() == other.getatk_cap() && this->getjoin_time() == other.getjoin_time());
}




