#pragma once
#include "unit.h"

class Alien_Soldier :
    public unit
{
public:
    Alien_Soldier(int h, int p, int id, int atk, int j, Game* r_pGame);
    bool operator==(Alien_Soldier& other);
    void attack();
    //type getType();


};

