#ifndef FIREBALL_CLASS_HPP
#define FIREBALL_CLASS_HPP

#include "AUnit.h"
#include "SpaceShooter.h"
#include "Player.h"

class Enemy;
class Meteor;
class Enemy2;

class Fireball : public AUnit {

public:
	Fireball(Player* player);
	~Fireball(void);

	virtual void	moveDown(void);
	bool			contains(Enemy* enemy);
	bool			contains(Enemy2* enemy2);
	bool			contains(Meteor* meteor);

};

#endif
