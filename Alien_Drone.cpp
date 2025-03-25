#include "Alien_Drone.h"
#include "ET.h"
#include"Earth_Gunnery.h"

Alien_Drone::Alien_Drone(int h, int p, int id, int atk, int j, Game* r_pGame) : unit(h,p,id,atk,j,r_pGame)
{
}

bool Alien_Drone::operator==(Alien_Drone& other)
{
	return (this->gethealth() == other.gethealth() && this->getpower() == other.getpower() && this->getID() == other.getID() && this->getatk_cap() == other.getatk_cap() && this->getjoin_time() == other.getjoin_time());
}

void Alien_Drone::attack()
{
	if (!(pGame->getEarthGunneryUnitQueue()->isEmpty())) {
		cout << "AD   " << this->getID() << "  [ ";
		int atk_cap = this->getatk_cap();
		if (pGame->getEarthTankUnitQueue()->getCount() > 0 && pGame->getEarthGunneryUnitQueue()->getCount() > 0) {
			unit* u = pGame->getEarthTankUnitQueue()->dequeue();
			unit* u2 = pGame->getEarthGunneryUnitQueue()->dequeue();
			u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
			u2->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u2->gethealth()));
			cout << u->getID() << ", ";
			cout << u2->getID() << ", ";
			if (u->gethealth() <= 0) {
				pGame->addtokilledlist(u->getID());
			}
			else {
				pGame->getEA()->getETS()->push(dynamic_cast<ETank*>(u));
			}
			if (u2->gethealth() <= 0) {
				pGame->addtokilledlist(u2->getID());
			}
			else {
				pGame->getEA()->getEGQ()->enqueue(dynamic_cast<Earth_Gunnery*>(u2), u2->gethealth() + u2->getpower());
			}
		}
		for (int i = 0; i < atk_cap - 1; i++) {
			if (pGame->getEA()->getETS()->getCount() > 0 && pGame->getEA()->getEGQ()->getCount() > 0) {
				unit* u = pGame->getEA()->getETS()->pop();
				unit* u2 = pGame->getEA()->getEGQ()->dequeue();
				u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
				u2->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u2->gethealth()));
				cout << u->getID() << ", ";
				cout << u2->getID() << ", ";
				if (u->gethealth() <= 0) {
					pGame->addtokilledlist(u->getID());
				}
				else {
					pGame->getEA()->getETS()->push(dynamic_cast<ETank*>(u));
				}
				if (u2->gethealth() <= 0) {
					pGame->addtokilledlist(u2->getID());
				}
				else {
					pGame->getEA()->getEGQ()->enqueue(dynamic_cast<Earth_Gunnery*>(u2), u2->gethealth() + u2->getpower());
				}
			}
		}
		cout << "]" << endl;
	}
	else {
		cout << "AD   " << this->getID() << "  [ ";
		int atk_cap = this->getatk_cap();
		for (int i = 0; i < atk_cap; i++) {
			if (pGame->getEA()->getETS()->getCount() > 0 && pGame->getEA()->getEGQ()->getCount() > 0) {
				unit* u = pGame->getEA()->getETS()->pop();
				unit* u2 = pGame->getEA()->getEGQ()->dequeue();
				u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
				u2->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u2->gethealth()));
				cout << u->getID() << ", ";
				cout << u2->getID() << ", ";
				if (u->gethealth() <= 0) {
					pGame->addtokilledlist(u->getID());
				}
				else {
					pGame->getEA()->getETS()->push(dynamic_cast<ETank*>(u));
				}
				if (u2->gethealth() <= 0) {
					pGame->addtokilledlist(u2->getID());
				}
				else {
					pGame->getEA()->getEGQ()->enqueue(dynamic_cast<Earth_Gunnery*>(u2), u2->gethealth() + u2->getpower());
				}
			}
		}
		cout << "]" << endl;
	}
	
}

//type Alien_Drone::getType()
//{
//	return Alien_d;
//}



