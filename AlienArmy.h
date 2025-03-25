#pragma once
#include"Alien_soldier_Queue.h"
#include"Monster_Array.h"
#include"Alien_Drones_Queues.h"


class Alien_Soldier;
class Alien_Monster;
class Alien_Drone;


class AlienArmy

{private:
	Alien_DroneQueue* ADQ;
	Alien_SoldierQueue* ASQ;
	Monster_Array* MA;
public:
	AlienArmy();
	//~AlienArmy();
	Alien_DroneQueue* getADQ();
	Alien_SoldierQueue* getASQ();
	Monster_Array* getMA();
	void print();
	void addsolider(Alien_Soldier* As);
	void addMonster(Alien_Monster* Am);
	void addDrone(Alien_Drone* Ad);
	void operator=( AlienArmy &rhs);
	void attack();
	
};

