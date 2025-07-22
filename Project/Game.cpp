#include "Game.h"
#include "Alien_Drone.h"
#include "Alien_Monster.h"
#include "Alien_Soldier.h"
#include "Earth_Gunnery.h"
#include "Earth_Soldier.h"
#include "ET.h"
#include "unit.h"





void Game::inputFunc(string filename)
{
	int armyUnitsNo;
	int ES_percent, ET_percent, EG_percent, AS_percent, AM_percent, AD_percent;
	int E_minPower, E_maxPower, E_minHealth, E_maxHealth, E_minAttCap, E_maxAttCap;
	int A_minPower, A_maxPower, A_minHealth, A_maxHealth, A_minAttCap, A_maxAttCap;
	int prob;
	int HU_Percent;

	ifstream infile;
	infile.open(filename);
	
	if (!infile.is_open()) {
		cout << "Input File not founded" << endl;
		return;
	}

	infile >> armyUnitsNo
		>> HU_Percent
		>> ES_percent >> ET_percent >> EG_percent
		>> AS_percent >> AM_percent >> AD_percent
		>> prob
		>> E_minPower >> E_maxPower >> E_minHealth >> E_maxHealth >> E_minAttCap >> E_maxAttCap
		>> A_minPower >> A_maxPower >> A_minHealth >> A_maxHealth >> A_minAttCap >> A_maxAttCap;
	infile.close();
	RG->setProb(prob);

	RG->setArmyUnitsNo(armyUnitsNo);

	RG->setES_percent(ES_percent);
	RG->setET_percent(ET_percent);
	RG->setEG_percent(EG_percent);
	RG->setE_minPower(E_minPower);
	RG->setE_maxPower(E_maxPower);
	RG->setE_minHealth(E_minHealth);
	RG->setE_maxHealth(E_maxHealth);
	RG->setE_minAttCap(E_minAttCap);
	RG->setE_maxAttCap(E_maxAttCap);

	RG->setAS_percent(AS_percent);
	RG->setAM_percent(AM_percent);
	RG->setAD_percent(AD_percent);
	RG->setA_minPower(A_minPower);
	RG->setA_maxPower(A_maxPower);
	RG->setA_minHealth(A_minHealth);
	RG->setA_maxHealth(A_maxHealth);
	RG->setA_minAttCap(A_minAttCap);
	RG->setA_maxAttCap(A_maxAttCap);
}




Game::Game(string filename)
{
	EarthSoldier_uq = new UnitQueue();
	EarthGunnery_uq = new UnitQueue();
	EarthTank_uq = new UnitQueue();
	AlienSoldier_uq = new UnitQueue();
	AlienDrone_uq = new UnitQueue();
	AlienMonster_uq = new UnitQueue();
	EA = new EarthArmy();
	AA = new AlienArmy();
	RG = new RandGen(AA,EA,this); 
	inputFunc(filename);
	//RG->setProb(30);

	//RG->setArmyUnitsNo(7);

	//RG->setES_percent(70);
	//RG->setET_percent(20);
	//RG->setEG_percent(10);
	//RG->setE_minPower(3);
	//RG->setE_maxPower(50);
	//RG->setE_minHealth(30);
	//RG->setE_maxHealth(90);
	//RG->setE_minAttCap(2);
	//RG->setE_maxAttCap(5);

	//RG->setAS_percent(80);
	//RG->setAM_percent(12);
	//RG->setAD_percent(8);
	//RG->setA_minPower(1);
	//RG->setA_maxPower(20);
	//RG->setA_minHealth(40);
	//RG->setA_maxHealth(80);
	//RG->setA_minAttCap(1);
	//RG->setA_maxAttCap(4);
	//RG->setHU_percent(5);
}

EarthArmy* Game::getEA()
{
	return EA;
}

AlienArmy* Game::getAA()
{
	return AA;
}

//RandGen* Game::getRG()
//{
//	return RG;
//}

void Game::addtokilledlist(int id)
{
	int* newKilled = new int[Killed_List_count + 1];
	for (int i = 0; i < Killed_List_count; ++i)
	{
		newKilled[i] = Killed_List[i];
	}
	newKilled[Killed_List_count++] = id;
	delete[] Killed_List;
	Killed_List = newKilled;
}

void Game::attack()
{
		EA->attack();
		//if () {
			//if (!AlienSoldier_uq->isEmpty()) {
			//	Alien_Soldier* as = dynamic_cast<Alien_Soldier*>(AlienSoldier_uq->dequeue());
			//	as->attack();
			//}
			////if (AlienDrone_uq->getCount() >= 2) {
			////	Alien_Drone* ad1 = dynamic_cast<Alien_Drone*>(AlienSoldier_uq->dequeue());
			////	ad1->attack();
			////	Alien_Drone* ad2 = dynamic_cast<Alien_Drone*>(AlienSoldier_uq->dequeue());
			////	ad2->attack();
			////}
			//if (!AlienMonster_uq->isEmpty()) {
			//	Alien_Monster* am = dynamic_cast<Alien_Monster*>(AlienSoldier_uq->dequeue());
			//	am->attack();
			//}
		//}
		//else {
			AA->attack();
		//}
}




Game* Game::getGame()
{
	return this;
}

UnitQueue* Game::getEarthSoldierUnitQueue()
{
	return EarthSoldier_uq;
}

UnitQueue* Game::getEarthGunneryUnitQueue()
{
	return EarthGunnery_uq;
}

UnitQueue* Game::getEarthTankUnitQueue()
{
	return EarthTank_uq;
}

UnitQueue* Game::getAlienSoldierUnitQueue()
{
	return AlienSoldier_uq;
}

UnitQueue* Game::getAlienDroneUnitQueue()
{
	return AlienDrone_uq;
}

UnitQueue* Game::getAlienMonsterUnitQueue()
{
	return AlienMonster_uq;
}


void Game::go()
{
	/*UnitQueue EAQ;
	UnitQueue AAQ;*/
	for (int i = 0; i < 50; i++)
	{
		RG->Randgenerate();
	}
	//for (int i = 0; i < 5; i++)
	//{
	//	AA->getADQ()->print();
	//	EA->getETS()->print();
	//	AA->getASQ()->print();
	//	EA->getESQ()->print();
	//	AA->getMA()->print();
	//	EA->getEGQ()->print();
	//	cout << "********************" << endl;
	//	
	//}
	//Alien_Drone* PPP = new Alien_Drone(1, 2, 2, 4, 5);
	//AA->getADQ()->enqueueFront(PPP);
	//AA->getADQ()->print();
	AA->print();
	EA->print();
	
	attack();
	
	//for (int i = 0; i < 5; i++){
	//	int X = 1 + rand() % 60;
	//	if (0 < X && X < 10) {
	//		Earth_Soldier* es = EA->getESQ()->dequeue();
	//		EA->getESQ()->enqueue(es);
	//	}
	//	else if (10 < X && X < 20) {
	//		ETank* et = EA->getETS()->pop();
	//		addtokilledlist(et->getID());
	//	}
	//	else if (20 < X && X < 30) {
	//		// Pick Earth Gunnery (EG) from its list, decrement its health to half, then insert it again.
	//		// RECHECK====================================================================
	//		Earth_Gunnery* eg = EA->getEGQ()->dequeue();
	//		int pri = eg->getHP_comb();
	//		eg->sethealth(eg->gethealth() / 2);
	//		EA->getEGQ()->enqueue(eg, pri);
	//	}
	//	else if (30 < X && X < 40) {
	//		// Pick 5 Alien Soldiers (AS) from their list, decrement their health, and put them back into their original list.  
	//		// pick 5 AS from their list, decrement their health and put them in a temp list then put back into their original lis
	//		Alien_SoldierQueue* temp = new Alien_SoldierQueue();
	//		for (int i = 0; i < 5; i++) {
	//			Alien_Soldier* as = AA->getASQ()->dequeue();
	//			as->sethealth(as->gethealth() - 1);
	//			temp->enqueue(as);
	//		}
	//		for (int i = 0; i < 5; i++) {
	//			Alien_Soldier* as = temp->dequeue();
	//			AA->getASQ()->enqueue(as);
	//		}
	//	}
	//	// RECHECK====================================================================
	//	else if (40 < X && X < 50) {
	//		// Pick 5 Alien Monsters from their list and insert them again.
	//		//srand(time(0));
	//		for (int i = 0; i < 5; i++) {
	//			//int x = rand() % AA->getMA()->getCount();
	//			Alien_Monster* am = AA->getMA()->removeMonster();
	//			AA->getMA()->addMonster(am);
	//		}
	//	}
	//	// RECHECK====================================================================
	//	else if (50 < X && X < 60) {
	//		// Pick 6 Alien Drones from front and rear of their list and move them to the Killed List.
	//		for (int i = 0; i < 3; i++) {
	//			Alien_Drone* frontDrone = AA->getADQ()->dequeue(); // Assuming you have a dequeueFront function.
	//			//Alien_Drone* rearDrone = AA->getADQ()->dequeuerear(); // Assuming you have a dequeueRear function.
	//			addtokilledlist(frontDrone->getID());
	//			//Killed_List[2]=rearDrone->getID();
	//		}
	//	}
	//	cout << "**************************************************************************************************" << endl;
	//	cout << X << endl;
	//	AA->print();
	//	EA->print();
	//}
	cout << "=========================================== After attack ========================================================"  << endl << endl;
	AA->print();
	EA->print();

	cout << "Killed List "<< Killed_List_count<<" [ ";
	for (int i = 0; i < Killed_List_count; i++) {
		cout << Killed_List[i] << ", ";
	}
	cout << "]";

	/*for (int i = 0; i < Killed_List_count; ++i) {
		cout << "Item " << i + 1 << ": " << Killed_List[i] << std::endl;

	}*/
}
//}








