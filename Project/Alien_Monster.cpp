#include "Alien_Monster.h"
#include "Earth_Soldier.h"
#include"ET.h"


Alien_Monster::Alien_Monster(int h, int p, int id, int atk, int j, Game* r_pGame) : unit(h, p, id, atk, j, r_pGame)
{
}

void Alien_Monster::attack()
{
	if (!(pGame->getEarthTankUnitQueue()->isEmpty())) {
		cout << "AM   " << this->getID() << "    [ ";
		int atk_cap = this->getatk_cap();
		if (pGame->getEarthSoldierUnitQueue()->getCount() > 0 && pGame->getEarthTankUnitQueue()->getCount() > 0) {
			unit* u = pGame->getEarthSoldierUnitQueue()->dequeue();
			u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
			cout << u->getID() << ", ";
			if (u->gethealth() <= 0)
			{
				pGame->addtokilledlist(u->getID());
			}
			else
			{
				pGame->getEA()->getESQ()->enqueue(dynamic_cast<Earth_Soldier*>(u));
			}
			unit* u1 = pGame->getEarthTankUnitQueue()->dequeue();
			cout << u1->getID() << ", ";
			u1->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u1->gethealth()));
			if (u1->gethealth() <= 0)
			{
				pGame->addtokilledlist(u1->getID());
			}
			else
			{
				pGame->getEA()->getETS()->push(dynamic_cast<ETank*>(u1));
			}
		}
		for (int i = 0; i < atk_cap - 1; i++)
		{
			if (pGame->getEA()->getESQ()->getCount() > 0 && pGame->getEA()->getETS()->getCount() > 0) {
				unit* u = pGame->getEA()->getESQ()->dequeue();
				u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
				cout << u->getID() << ", ";
				if (u->gethealth() <= 0)
				{
					pGame->addtokilledlist(u->getID());
				}
				else
				{
					pGame->getEA()->getESQ()->enqueue(dynamic_cast<Earth_Soldier*>(u));
				}
			}
			unit* u1 = pGame->getEA()->getETS()->pop();
			cout << u1->getID() << ", ";
			u1->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u1->gethealth()));
			if (u1->gethealth() <= 0)
			{
				pGame->addtokilledlist(u1->getID());
			}
			else
			{
				pGame->getEA()->getETS()->push(dynamic_cast<ETank*>(u1));
			}
		}
		cout << "]" << endl << endl;
		pGame->getAA()->getMA()->addMonster(this);
	}
	else {
		cout << "AM   " << this->getID() << "    [ ";
		int atk_cap = this->getatk_cap();
		for (int i = 0; i < atk_cap; i++)
		{
			if (pGame->getEA()->getESQ()->getCount() > 0 && pGame->getEA()->getETS()->getCount() > 0) {
				unit* u = pGame->getEA()->getESQ()->dequeue();
				u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
				cout << u->getID() << ", ";
				if (u->gethealth() <= 0)
				{
					pGame->addtokilledlist(u->getID());
				}
				else
				{
					pGame->getEA()->getESQ()->enqueue(dynamic_cast<Earth_Soldier*>(u));
				}
			}
			unit* u1 = pGame->getEA()->getETS()->pop();
			cout << u1->getID() << ", ";
			u1->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u1->gethealth()));
			if (u1->gethealth() <= 0)
			{
				pGame->addtokilledlist(u1->getID());
			}
			else
			{
				pGame->getEA()->getETS()->push(dynamic_cast<ETank*>(u1));
			}
		}
		cout << "]" << endl << endl;
		pGame->getAA()->getMA()->addMonster(this);
	}
}

//type Alien_Monster::getType()
//{
//    return Alien_m;
//}

