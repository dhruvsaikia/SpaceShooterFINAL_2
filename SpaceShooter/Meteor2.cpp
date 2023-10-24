#include "Meteor2.h"

Meteor2::Meteor2(int x) {
	setWidth(METEOR2_WIDTH);
	setHeight(METEOR2_HEIGHT);
	setX(x);
	setY(-METEOR2_HEIGHT - 1);
}

Meteor2::~Meteor2(void) {
}

void	Meteor2::moveDown(void) {
	setY(getY() + 1);
}
