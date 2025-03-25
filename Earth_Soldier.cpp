#include "Earth_Soldier.h"
#include "Alien_Soldier.h"
#include<iostream>


Earth_Soldier::Earth_Soldier(int h, int p, int id, int atk, int j, Game* r_pGame) : unit(h, p, id, atk, j, r_pGame)
{
}

bool Earth_Soldier::operator==( Earth_Soldier& other) 
{
	return (this->gethealth() == other.gethealth() && this->getpower() == other.getpower() && this->getID() == other.getID() && this->getatk_cap() == other.getatk_cap() && this->getjoin_time() == other.getjoin_time());
}

void Earth_Soldier::attack()
{
	cout << "ES   " << this->getID() << "    [ ";
	int atk_cap = this->getatk_cap();
	for (int i = 0; i < atk_cap; i++) {
		if (pGame->getAA()->getASQ()->getcount() > 0) {
			unit* u = pGame->getAA()->getASQ()->dequeue();
			u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
			cout <<u->getID()<<", ";
			if (u->gethealth() <= 0) {
				pGame->addtokilledlist(u->getID());
			}
			else if (pGame->getAlienSoldierUnitQueue()->isEmpty()){
				pGame->getAlienSoldierUnitQueue()->enqueue(dynamic_cast<unit*>(u));
			}
			else {
				pGame->getAA()->getASQ()->enqueue(dynamic_cast<Alien_Soldier*>(u));
			}
		}
	}
	cout << "]" << endl;
	pGame->getEarthSoldierUnitQueue()->enqueue(dynamic_cast<unit*>(this));
}

//type Earth_Soldier::getType()
//{
//	return Earth_s;
//}


