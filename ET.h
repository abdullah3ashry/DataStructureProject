#pragma once
#include "unit.h"
class ETank :
    public unit
{
public:
    ETank(int h, int p, int id, int atk, int j, Game* r_pGame) ;
    bool operator==(ETank& other);
    void attack();
    //type getType();
};

