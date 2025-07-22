#include "Earth_Gunnery.h"
#include"Alien_Drone.h"
#include "Alien_Monster.h"
Earth_Gunnery::Earth_Gunnery(int h, int p, int id, int atk, int j, Game* r_pGame) : unit(h, p, id, atk, j, r_pGame)
{
    HP_comb = h + p;
}

int Earth_Gunnery::getHP_comb()
{
    return HP_comb;
}

void Earth_Gunnery::attack()
{
	cout << "EG  " << this->getID() << "  [ ";
	int atk_cap = this->getatk_cap();
	for (int i = 0; i < atk_cap; i++) {
		if (pGame->getAA()->getMA()->getCount() > 0) {
			unit* u = pGame->getAA()->getMA()->removeMonster();
			u->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u->gethealth()));
			cout << u->getID() << ", ";
			if (u->gethealth() <= 0) {
				pGame->addtokilledlist(u->getID());
			}
			else {
				pGame->getAlienMonsterUnitQueue()->enqueue(dynamic_cast<unit*>(u));
			}
		}
		if (pGame->getAA()->getADQ()->getcount() >= 2) {
			unit* u2 = pGame->getAA()->getADQ()->dequeueRear();
			unit* u3 = pGame->getAA()->getADQ()->dequeue();
			cout << u2->getID() << ", ";
			cout << u3->getID() << ", ";
			u2->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u2->gethealth()));
			u3->sethealth((this->getpower() * (this->gethealth() / 100)) / sqrt(u3->gethealth()));
			if (u2->gethealth() <= 0) {
				pGame->addtokilledlist(u2->getID());
			}
			else {
				pGame->getAlienDroneUnitQueue()->enqueue(dynamic_cast<unit*>(u2));
			}
			if (u3->gethealth() <= 0) {
				pGame->addtokilledlist(u3->getID());
			}
			else {
				pGame->getAlienDroneUnitQueue()->enqueue(dynamic_cast<unit*>(u3));
			}
		}
	}
		cout << "]" << endl << endl;
		pGame->getEarthGunneryUnitQueue()->enqueue(dynamic_cast<unit*>(this));

}

//type Earth_Gunnery::getType()
//{
//    return Earth_g;
//}


