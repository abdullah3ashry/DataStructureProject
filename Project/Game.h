#pragma once
#include"EarthArmy.h"
#include"AlienArmy.h"
#include "UnitQueue.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include"RandGen.h"



class Game
{
private:
	EarthArmy* EA;
	AlienArmy* AA;
	RandGen* RG;
	int* Killed_List;
	int Killed_List_count;
	UnitQueue* EarthSoldier_uq;
	UnitQueue* EarthGunnery_uq;
	UnitQueue* EarthTank_uq;
	UnitQueue* AlienSoldier_uq;
	UnitQueue* AlienDrone_uq;
	UnitQueue* AlienMonster_uq;
	//Earth_Soldier* es;
	//Earth_Gunnery* eg;
	//ETank* et;
	//Alien_Soldier* as;
	//Alien_Drone* ad;
	//Alien_Monster* am;
public:
	Game(string filename);
	EarthArmy* getEA();
	AlienArmy* getAA();
	//RandGen* getRG();
	Game* getGame();
	UnitQueue* getEarthSoldierUnitQueue();
	UnitQueue* getEarthGunneryUnitQueue();
	UnitQueue* getEarthTankUnitQueue();
	UnitQueue* getAlienSoldierUnitQueue();
	UnitQueue* getAlienDroneUnitQueue();
	UnitQueue* getAlienMonsterUnitQueue();
	void inputFunc(string filename);
	void go();
	void addtokilledlist(int id);
	void attack();
};

