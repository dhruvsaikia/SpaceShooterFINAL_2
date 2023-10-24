#include "Star.h"

Star::Star(int x) {
	setWidth(STAR_WIDTH);
	setHeight(STAR_HEIGHT);
	setX(x);
	setY(-STAR_HEIGHT - 1);
}

Star::~Star(void) {
}

void	Star::moveDown(void) {
	setY(getY() + 1);
}
