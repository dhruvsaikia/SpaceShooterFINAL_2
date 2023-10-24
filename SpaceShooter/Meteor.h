#ifndef METEOR_CLASS_HPP
#define METEOR_CLASS_HPP

#include "AUnit.h"
#include "SpaceShooter.h"

class Meteor : public AUnit {

public:
	Meteor(int x);
	~Meteor(void);

	virtual void	moveDown(void);
};

#endif
