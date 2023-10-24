#ifndef ENEMY_CLASS_HPP
#define ENEMY_CLASS_HPP

#include "AUnit.h"
#include "SpaceShooter.h"

class Enemy : public AUnit {

public:
	Enemy(int x);
	~Enemy(void);

	virtual void moveDown(float);
};

#endif
