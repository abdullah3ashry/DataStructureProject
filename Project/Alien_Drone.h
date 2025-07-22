#pragma once
#include "unit.h"

class Alien_Drone :
    public unit
{
public:
    Alien_Drone(int h, int p, int id, int atk, int j, Game* r_pGame);
    bool operator==(Alien_Drone& other);
    void attack();
    //type getType();
};

