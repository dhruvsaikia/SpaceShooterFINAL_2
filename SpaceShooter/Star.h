#ifndef STAR_CLASS_HPP
#define STAR_CLASS_HPP

#include "AUnit.h"
#include "SpaceShooter.h"

class Star : public AUnit {

public:
	Star(int x);
	~Star(void);

	virtual void	moveDown(void);

};

#endif
