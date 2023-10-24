#include "Enemy2.h"

Enemy2::Enemy2(int x) {
	setWidth(ENEMY_WIDTH);
	setHeight(ENEMY_HEIGHT);
	setX(x);
	setY(-ENEMY_HEIGHT - 1);
}

Enemy2::~Enemy2(void) {
}

void	Enemy2::moveDown(void) {
	setY(getY() + 3);
}
