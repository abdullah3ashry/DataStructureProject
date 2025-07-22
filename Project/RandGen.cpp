#include "RandGen.h"
#include "Alien_Drone.h"
#include "Alien_Soldier.h"
#include "Alien_Monster.h"
#include "Earth_Gunnery.h"
#include "Earth_Soldier.h"
#include "ET.h"
#include "HU.h"

// Constructor

RandGen::RandGen(AlienArmy*& alien, EarthArmy*& earth, Game* r_pGame) : alienArmy(alien), earthArmy(earth)
{
 
    armyUnitsNo = 0;
    ES_percent = 0;
    ET_percent = 0;
    EG_percent = 0;
    AS_percent = 0;
    AM_percent = 0;
    AD_percent = 0;
    prob = 0.0;
    pGame = r_pGame;
    HU_Percent = 0;
}

void RandGen::setTimeStep(int time)
{
    timeStep = time;
}



// Setters
void RandGen::setArmyUnitsNo(int units) {
    armyUnitsNo = units;
}

void RandGen::setES_percent(int percent) {
    ES_percent = percent;
}

void RandGen::setET_percent(int percent) {
    ET_percent = percent;
}

void RandGen::setEG_percent(int percent) {
    EG_percent = percent;
}

void RandGen::setAS_percent(int percent) {
    AS_percent = percent;
}

void RandGen::setAM_percent(int percent) {
    AM_percent = percent;
}

void RandGen::setAD_percent(int percent) {
    AD_percent = percent;
}

void RandGen::setProb(int probability) {
    prob = probability;
}

void RandGen::setE_minPower(int minRange)
{
    E_minPower = minRange;
}

void RandGen::setE_maxPower(int maxRange)
{
    E_maxPower = maxRange;
}

void RandGen::setE_minHealth(int minHealth)
{
    E_minHealth = minHealth;
}

void RandGen::setE_maxHealth(int maxHealth)
{
    E_maxHealth = maxHealth;
}

void RandGen::setE_minAttCap(int minAttCap)
{
    E_minAttCap = minAttCap;
}

void RandGen::setE_maxAttCap(int maxAttCap)
{
    E_maxAttCap = maxAttCap;
}

void RandGen::setA_minPower(int minRange)
{
    A_minPower = minRange;
}

void RandGen::setA_maxPower(int maxRange)
{
    A_maxPower = maxRange;
}

void RandGen::setA_minHealth(int minHealth)
{
    A_minHealth = minHealth;
}

void RandGen::setA_maxHealth(int maxHealth)
{
    A_maxHealth = maxHealth;
}

void RandGen::setA_minAttCap(int minAttCap)
{
    A_minAttCap = minAttCap;
}

void RandGen::setA_maxAttCap(int maxAttCap)
{
    A_maxAttCap = maxAttCap;
}

void RandGen::setHU_percent(int HU_Percent)
{
    this->HU_Percent = HU_Percent;
}



int RandGen::getTimeStep() const
{
    return timeStep;
}

// Getters
int RandGen::getArmyUnitsNo() const {
    return armyUnitsNo;
}

int RandGen::getES_percent() const {
    return ES_percent;
}

int RandGen::getET_percent() const {
    return ET_percent;
}

int RandGen::getEG_percent() const {
    return EG_percent;
}

int RandGen::getAS_percent() const {
    return AS_percent;
}

int RandGen::getAM_percent() const {
    return AM_percent;
}

int RandGen::getAD_percent() const {
    return AD_percent;
}

int RandGen::getProb() const {
    return prob;
}

int RandGen::getE_minPower() const
{
    return E_minPower;
}

int RandGen::getE_maxPower() const
{
    return E_maxPower;
}

int RandGen::getE_minHealth() const
{
    return E_minHealth;
}

int RandGen::getE_maxHelth() const
{
    return E_maxHealth;
}

int RandGen::getE_minAttCap() const
{
    return E_minAttCap;
}

int RandGen::getE_maxAttCap() const
{
    return E_maxAttCap;
}

int RandGen::getA_minPower() const
{
    return A_minPower;
}

int RandGen::getA_maxPower() const
{
    return A_maxPower;
}

int RandGen::getA_minHealth() const
{
    return A_minHealth;
}

int RandGen::getA_maxHealth() const
{
    return A_maxHealth;
}

int RandGen::getA_minAttCap() const
{
    return A_minAttCap;
}

int RandGen::getA_maxAttCap() const
{
    return A_maxAttCap;
}

int RandGen::getHU_Percent() const
{
    return HU_Percent;
}



void RandGen::Randgenerate()
{
    static int earthID = 0;
    static int alienID = 5000;
   // srand(time(0));
    A = (1 + rand() % 100);
    if (A < prob || timeStep == 0) {
        for (int i = 0; i < 5; i++) //loop to generate units of earth army
        {
            B = (1 + rand() % 100);

            int power, health, attCapacity; // random generation of pow, health, and attCap of each unit
            power = E_minPower + rand() % (E_maxPower - E_minPower);
            health = E_minHealth + rand() % (E_maxHealth - E_minHealth);
            attCapacity = E_minAttCap + rand() % (E_maxAttCap - E_minAttCap);

            if (B <= ES_percent)
            {
                Earth_Soldier* newUnit = new Earth_Soldier(health, power, earthID++, attCapacity, timeStep++,pGame);
                earthArmy->addsolider(newUnit);
            }
            else if (B <= ES_percent + ET_percent)
            {
                ETank* newUnit = new ETank(health, power,earthID++, attCapacity, timeStep++, pGame);
                earthArmy->addTank(newUnit);
            }
            else
            {
                int Pri = 0;    
                Earth_Gunnery* newUnit = new Earth_Gunnery(health, power,earthID++,attCapacity, timeStep++, pGame);
                earthArmy->addGunnery(newUnit,Pri);
            }

        }

        for (int i = 0; i < armyUnitsNo; i++) //loop to generate units of alien army
        {
            B = (1 + rand() % 100);

            int power, health, attCapacity;
            power = A_minPower + rand() % (A_maxPower - A_minPower);
            health = A_minHealth + rand() % (A_maxHealth - A_minHealth);
            attCapacity = A_minAttCap + rand() % (A_maxAttCap - A_minAttCap);

            if (B <= AS_percent)
            {
                Alien_Soldier* newUnit = new Alien_Soldier(health, power,alienID++, attCapacity, timeStep++, pGame);
                alienArmy->addsolider(newUnit);
            }
            else if (B <= AS_percent + AM_percent)
            {
                Alien_Monster* newUnit = new Alien_Monster(health, power,alienID++, attCapacity, timeStep++, pGame);
                alienArmy->addMonster(newUnit);
            }
            else
            {
                Alien_Drone* newUnit = new Alien_Drone(health, power,alienID++ ,attCapacity, timeStep++, pGame);
                alienArmy->addDrone(newUnit);
            }
            

        }
        for (int i = 0; i < armyUnitsNo; i++) //loop to generate HU
        {
            B = (1 + rand() % 100);

            int power, health, attCapacity;
            power = E_minPower + rand() % (E_maxPower - E_minPower);
            health = E_minHealth + rand() % (E_maxHealth - E_minHealth);
            attCapacity = E_minAttCap + rand() % (E_maxAttCap - E_minAttCap);

            if (B <= HU_Percent)
            {
                HU* newUnit = new HU(health, power, earthID++, attCapacity, timeStep++, pGame);
                earthArmy->addHU(newUnit);
            }


        }

    }
    else
        return;
}