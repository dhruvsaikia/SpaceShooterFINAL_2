#include "Enemy.h"

Enemy::Enemy(int x) {
	setWidth(ENEMY_WIDTH);
	setHeight(ENEMY_HEIGHT);
	setX(x);
	setY(-ENEMY_HEIGHT - 1);
}

Enemy::~Enemy(void) {
}

void	Enemy::moveDown(void) {
	setY(getY() + 5);
}
