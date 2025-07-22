#include "ET.h"
#include"Alien_Monster.h"
ETank::ETank(int h, int p, int id, int atk, int j, Game* r_pGame) : unit(h, p, id, atk, j, r_pGame)
{
}

bool ETank::operator==(ETank& other)
{
	return (this->gethealth() == other.gethealth() && this->getpower() == other.getpower() && this->getID() == other.getID() && this->getatk_cap() == other.getatk_cap() && this->getjoin_time() == other.getjoin_time());
}

void ETank::attack()
{
	cout << "ET  " << this->getID() << "  [ ";
	int atk_cap = this->getatk_cap();
	for (int i = 0; i < atk_cap; i++) 
	{
		if (pGame->getAA()->getMA()->getCount() > 0) {
			unit* u = pGame->getAA()->getMA()->removeMonster();
			
			u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
			cout << u->getID()<< ", ";
			if (u->gethealth() <= 0) {
				pGame->addtokilledlist(u->getID());
			}
			else {
				pGame->getAlienMonsterUnitQueue()->enqueue(dynamic_cast<unit*>(u));
			}
		}
	}
	cout << "]" << endl;
	pGame->getEarthTankUnitQueue()->enqueue(dynamic_cast<unit*>(this));
}

//type ETank::getType()
//{
//	return Earth_t;
//}


