#pragma once
#include "unit.h"

class Alien_Monster:
    public unit
{
public:

    Alien_Monster(int h, int p, int id, int atk, int j, Game* r_pGame);
    void attack();
    //type getType();

};

