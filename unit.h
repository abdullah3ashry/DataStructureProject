#pragma once
#include <cmath>

#include "Game.h"
enum type { Earth_s, Earth_t, Earth_g, Alien_s, Alien_m, Alien_d };

class unit
{

private:
	int health;
	int power;
	int ID;
	int Atk_cap;
	int join_time;
	type Type;
protected:
	Game* pGame;        //pointer to game object
	
public:
	unit(int h, int p, int id, int atk, int j,Game* r_pGame);
	
	void sethealth(int h);
	void setpower(int p);
	void setID(int id);
	void setatk_cap(int atk);
	void setjoin_time(int j);
	
	//Game* getGame();
	virtual int gethealth();
	virtual int getpower();
	virtual int getID();
	virtual int getatk_cap();
	virtual int getjoin_time();
	//virtual type getType() = 0;
	virtual void attack() = 0;
	bool operator==(unit& other);








};

