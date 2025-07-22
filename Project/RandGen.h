#pragma once
#include <cstdlib>
#include <ctime>
#include "AlienArmy.h"
#include "EarthArmy.h"
#include <fstream>

class Game;

class RandGen
{
    int armyUnitsNo;
    int ES_percent, ET_percent, EG_percent, AS_percent, AM_percent, AD_percent;
    int E_minPower, E_maxPower, E_minHealth, E_maxHealth, E_minAttCap, E_maxAttCap;
    int A_minPower, A_maxPower, A_minHealth, A_maxHealth, A_minAttCap, A_maxAttCap;
    int prob;
    int A, B;
    int timeStep;
    int HU_Percent;
    AlienArmy*& alienArmy;
    EarthArmy*& earthArmy;

protected:
    Game* pGame;

  
public:
    RandGen(AlienArmy*& alien, EarthArmy*& earth,Game* r_pGame);


    // Setters
    void setTimeStep(int time);

    void setArmyUnitsNo(int units);

    void setES_percent(int percent);
    void setET_percent(int percent);
    void setEG_percent(int percent);

    void setAS_percent(int percent);
    void setAM_percent(int percent);
    void setAD_percent(int percent);

    void setProb(int probability);

    void setE_minPower(int minRange);
    void setE_maxPower(int maxRange);

    void setE_minHealth(int minHealth);
    void setE_maxHealth(int maxHealth);

    void setE_minAttCap(int minAttCap);
    void setE_maxAttCap(int maxAttCap);

    void setA_minPower(int minRange);
    void setA_maxPower(int maxRange);

    void setA_minHealth(int minHealth);
    void setA_maxHealth(int maxHealth);

    void setA_minAttCap(int minAttCap);
    void setA_maxAttCap(int maxAttCap);
    void setHU_percent(int HU_Percent);



    // Getters
    int getTimeStep() const;

    int getArmyUnitsNo() const;

    int getES_percent() const;
    int getET_percent() const;
    int getEG_percent() const;

    int getAS_percent() const;
    int getAM_percent() const;
    int getAD_percent() const;

    int getProb() const;

    int getE_minPower() const;
    int getE_maxPower() const;

    int getE_minHealth() const;
    int getE_maxHelth() const;

    int getE_minAttCap() const;
    int getE_maxAttCap() const;

    int getA_minPower() const;
    int getA_maxPower() const;

    int getA_minHealth() const;
    int getA_maxHealth() const;

    int getA_minAttCap() const;
    int getA_maxAttCap() const;
    int getHU_Percent() const;


    

    void Randgenerate();
};

