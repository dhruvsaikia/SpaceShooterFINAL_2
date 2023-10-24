#include "Fireball.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Meteor.h"

Fireball::Fireball(Player* player) {
	setWidth(FIREBALL_WIDTH);
	setHeight(FIREBALL_HEIGHT);
	setX(PLAYER_WIDTH / 3 + player->getX() + 1);
	setY(player->getY());
}

Fireball::~Fireball(void) {
}

void	Fireball::moveDown(void) {
	setY(getY() - 1);
}

bool	Fireball::contains(Enemy* enemy) {
	int topBullet = getY();
	int bottomBullet = getY() + FIREBALL_HEIGHT;
	int leftBullet = getX();
	int rightBullet = getX() + FIREBALL_WIDTH;

	int topEnemy = enemy->getY();
	int bottomEnemy = enemy->getY() + ENEMY_HEIGHT;
	int leftEnemy = enemy->getX();
	int rightEnemy = enemy->getX() + ENEMY_WIDTH;

	if (((bottomBullet <= topEnemy) ||
		(topBullet >= bottomEnemy) ||
		(rightBullet <= leftEnemy) ||
		(leftBullet >= rightEnemy)) == false)
		return true;

	return false;
}

bool	Fireball::contains(Enemy2* enemy2) {
	int topBullet = getY();
	int bottomBullet = getY() + FIREBALL_HEIGHT;
	int leftBullet = getX();
	int rightBullet = getX() + FIREBALL_WIDTH;

	int topEnemy = enemy2->getY();
	int bottomEnemy = enemy2->getY() + ENEMY2_HEIGHT;
	int leftEnemy = enemy2->getX();
	int rightEnemy = enemy2->getX() + ENEMY2_WIDTH;

	if (((bottomBullet <= topEnemy) ||
		(topBullet >= bottomEnemy) ||
		(rightBullet <= leftEnemy) ||
		(leftBullet >= rightEnemy)) == false)
		return true;

	return false;
}

bool	Fireball::contains(Meteor* meteor) {
	int topBullet = getY();
	int bottomBullet = getY() + FIREBALL_HEIGHT;
	int leftBullet = getX();
	int rightBullet = getX() + FIREBALL_WIDTH;

	int topMeteor = meteor->getY();
	int bottomMeteor = meteor->getY() + METEOR_HEIGHT;
	int leftMeteor = meteor->getX();
	int rightMeteor = meteor->getX() + METEOR_WIDTH;

	if (((bottomBullet <= topMeteor) ||
		(topBullet >= bottomMeteor) ||
		(rightBullet <= leftMeteor) ||
		(leftBullet >= rightMeteor)) == false)
		return true;

	return false;
}
