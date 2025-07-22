#pragma once
#include "unit.h"

class Earth_Soldier :
    public unit
{

public:
    Earth_Soldier(int h, int p, int id, int atk, int j, Game* r_pGame);
    bool operator==( Earth_Soldier& other) ;
    void attack();
    //type getType();
};

