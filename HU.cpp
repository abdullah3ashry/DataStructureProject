#include "HU.h"

HU::HU(int h, int p, int id, int atk, int j, Game* r_pGame) : unit(h, p, id, atk, j, r_pGame)
{
}

bool HU::operator==(HU& other)
{
	return (this->gethealth() == other.gethealth() && this->getpower() == other.getpower() && this->getID() == other.getID() && this->getatk_cap() == other.getatk_cap() && this->getjoin_time() == other.getjoin_time());
}

void HU::attack()
{

	//int atk_cap = this->getatk_cap();
	//for (int i = 0; i < atk_cap; i++) {
	//	unit* u = pGame->getAA()->getMA()->removeMonster();
	//	u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
	//	if (u->gethealth() <= 0) {
	//		pGame->addtokilledlist(u->getID());
	//	}
	//	else {
	//		pGame->getAA()->getMA()->addMonster(dynamic_cast<Alien_Monster*>(u));
	//	}

	//}
}

//type ETank::getType()
//{
//	return Earth_t;
//}



