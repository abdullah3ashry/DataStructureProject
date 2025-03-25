#pragma once
#include"unit.h"

class HU:public unit
{
public:
    HU(int h, int p, int id, int atk, int j, Game* r_pGame);
    bool operator==(HU& other);
    void attack();
};

