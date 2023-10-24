#include "Meteor.h"

Meteor::Meteor(int x) {
	setWidth(METEOR_WIDTH);
	setHeight(METEOR_HEIGHT);
	setX(x);
	setY(-METEOR_HEIGHT - 1);
}

Meteor::~Meteor(void) {
}

void	Meteor::moveDown(void) {
	setY(getY() + 1);
}
