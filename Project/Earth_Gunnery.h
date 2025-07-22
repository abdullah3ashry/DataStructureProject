#pragma once
#include "unit.h"

class Earth_Gunnery :
    public unit
{
private:
    int HP_comb;
public:
    Earth_Gunnery(int h, int p, int id, int atk, int j, Game* r_pGame);
    int getHP_comb();
    void attack();
    //type getType();
};

