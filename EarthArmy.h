#pragma once

//#include"unit.h"

#include "Earth_Soldier_Queue.h"
#include "Earth_Gunnery_PQueue.h"
#include "ET_stack.h"
#include "HU_Stack.h"

class Earth_Soldier;
class Earth_Gunnery;
class ETank;
class HU;
class EarthArmy
{
private:
	Earth_SoldierQueue* ESQ;
	Earth_Gunnery_PQueue* EGQ;
	ET_stack* ETS;
	HU_Stack* HUS;

public:
	EarthArmy();
//	~EarthArmy();
	Earth_SoldierQueue* getESQ();
	Earth_Gunnery_PQueue* getEGQ();
	ET_stack* getETS();
	HU_Stack* getHUS();
	void print();
	void addsolider(Earth_Soldier* Es);
	void addGunnery(Earth_Gunnery* Eg,int pri);
	void addTank(ETank* Et);
	void addHU(HU* hu);
	void attack();

};

