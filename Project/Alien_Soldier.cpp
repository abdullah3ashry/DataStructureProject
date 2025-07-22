#include "Alien_Soldier.h"
#include"Earth_Soldier.h"

Alien_Soldier::Alien_Soldier(int h, int p, int id, int atk, int j, Game* r_pGame) : unit(h, p, id, atk, j, r_pGame)
{
}
bool Alien_Soldier::operator==(Alien_Soldier& other)
{
	return (this->gethealth() == other.gethealth() && this->getpower() == other.getpower() && this->getID() == other.getID() && this->getatk_cap() == other.getatk_cap() && this->getjoin_time() == other.getjoin_time());
}

void Alien_Soldier::attack()
{
	if (!(pGame->getEarthSoldierUnitQueue()->isEmpty())) {
		cout << "AS  " << this->getID() << "   [ ";
		int atk_cap = this->getatk_cap();
		unit* u = pGame->getEarthSoldierUnitQueue()->dequeue();
		u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
		cout << u->getID() << ",";
		if (u->gethealth() <= 0) {
			pGame->addtokilledlist(u->getID());
		}
		else {
			pGame->getEA()->getESQ()->enqueue(dynamic_cast<Earth_Soldier*>(u));
		}
		for (int i = 0; i < atk_cap - 1; i++) {
			if (pGame->getEA()->getESQ()->getCount() > 0) {
				unit* u = pGame->getEA()->getESQ()->dequeue();
				u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
				cout << u->getID() << ", ";
				if (u->gethealth() <= 0) {
					pGame->addtokilledlist(u->getID());
				}
				else {
					pGame->getEA()->getESQ()->enqueue(dynamic_cast<Earth_Soldier*>(u));
				}
			}
		}
		cout << "]" << endl ;
		pGame->getAA()->getASQ()->enqueue(this);
	}
	else {
		cout << "AS  " << this->getID() << "   [ ";
		int atk_cap = this->getatk_cap();
		for (int i = 0; i < atk_cap; i++) {
			if (pGame->getEA()->getESQ()->getCount() > 0) {
				unit* u = pGame->getEA()->getESQ()->dequeue();
				u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
				cout << u->getID() << ", ";
				if (u->gethealth() <= 0) {
					pGame->addtokilledlist(u->getID());
				}
				else {
					pGame->getEA()->getESQ()->enqueue(dynamic_cast<Earth_Soldier*>(u));
				}
			}
		}
		cout << "]" << endl;
		pGame->getAA()->getASQ()->enqueue(this);
	}
}

//type Alien_Soldier::getType()
//{
//	return Alien_s;
//}


