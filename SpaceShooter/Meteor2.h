#pragma once
#include "AUnit.h"
#include "SpaceShooter.h"

class Meteor2 : public AUnit {

public:
	Meteor2(int x);
	~Meteor2(void);

	virtual void	moveDown(void);
};