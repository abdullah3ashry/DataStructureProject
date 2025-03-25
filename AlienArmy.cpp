#include "AlienArmy.h"
#include"Alien_Soldier.h"
#include"Alien_Monster.h"
#include"Alien_Drone.h"


AlienArmy::AlienArmy()
{
	ADQ = new Alien_DroneQueue();
	ASQ = new Alien_SoldierQueue();
	MA = new Monster_Array();
}

Alien_DroneQueue* AlienArmy::getADQ()
{
	return ADQ;
}

Alien_SoldierQueue* AlienArmy::getASQ()
{
	return ASQ;
}

Monster_Array* AlienArmy::getMA()
{
	return MA;
}

void AlienArmy::print()
{
	cout << "=========================================" << "Alive Alien Army units" << "=========================================" << endl << endl;
	ASQ->print();
	ADQ->print();
	MA->print();
	
}

void AlienArmy::addsolider(Alien_Soldier* As)
{
	ASQ->enqueue(As);
}

void AlienArmy::addMonster(Alien_Monster* Am)
{
	MA->addMonster(Am);
}

void AlienArmy::addDrone(Alien_Drone* Ad)
{
	ADQ->enqueue(Ad);
}

void AlienArmy::operator=( AlienArmy& rhs) {
	// Assign the contents of Alien_DroneQueue, Alien_SoldierQueue, and Monster_Array
	*(this->ADQ) = *(rhs.getADQ());
	*(this->ASQ) = *(rhs.getASQ());
	*(this->MA) = *(rhs.getMA());
}

void AlienArmy::attack()
{
	ASQ->dequeue()->attack();
	if (ADQ->getcount() >= 2) {
		ADQ->dequeue()->attack();
		ADQ->dequeueRear()->attack();
	}
	MA->removeMonster()->attack();


}
