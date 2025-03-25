#include "EarthArmy.h"
#include"Earth_Soldier.h"
#include"Earth_Gunnery.h"
#include"ET.h"
#include "HU.h"

EarthArmy::EarthArmy()
{
	ESQ = new Earth_SoldierQueue();
	EGQ = new Earth_Gunnery_PQueue();
	ETS = new ET_stack();
	HUS = new HU_Stack();
}

//EarthArmy::~EarthArmy()
//{
//	this->getESQ();
//}

Earth_SoldierQueue* EarthArmy::getESQ()
{
	return ESQ;
}

Earth_Gunnery_PQueue* EarthArmy::getEGQ()
{
	return EGQ;
}

ET_stack* EarthArmy::getETS()
{
	return ETS;
}

HU_Stack* EarthArmy::getHUS()
{
	return HUS;
}

void EarthArmy::print()
{
	cout << "=========================================" << "Alive Earth Army units" << "=========================================" << endl << endl;
	ESQ->print();
	ETS->print();
	EGQ->print();
	
}

void EarthArmy::addsolider(Earth_Soldier* Es)
{
	ESQ->enqueue(Es);
}

void EarthArmy::addGunnery(Earth_Gunnery* Eg,int pri)
{
	EGQ->enqueue(Eg,pri);
}

void EarthArmy::addTank(ETank* Et)
{
	ETS->push(Et);
}

void EarthArmy::addHU(HU* hu)
{
	HUS->push(hu);
}

void EarthArmy::attack()
{
	cout << "=====================================Units fighting at current step===================================" << endl << endl;
	ESQ->dequeue()->attack();
	ETS->pop()->attack();
	EGQ->dequeue()->attack();

	

}



