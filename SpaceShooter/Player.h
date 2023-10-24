#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include "AUnit.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Meteor.h"

class Fireball;

class Player : public AUnit {

private:
	Fireball* _bullets[MAX_BULLETS];
	static int				_qBullets;
	std::vector<SDL_Rect>	_colliders;
	static int				_lives;
	static int				_hitPoints;
	static long				_score;
	Uint32					_lastShot;
public:
	Player(void);
	~Player(void);

	int				getPoints(void);
	int				getLives(void);
	int				getHitPoints(void);

	void			setPoints(int points);

	virtual void	moveDown(void);
	void			moveBullets(t_settings& settings);

	void			shoot(t_settings& settings);
	void			shiftColliders(void);

	bool			containes(Enemy* enemy);
	bool			containes(Enemy2* enemy2);
	bool			containes(Meteor* meteor);

	bool			kill(int index, Enemy* enemy);
	bool			kill(int index, Enemy2* enemy2);
	bool			kill(int index, Meteor* meteor);

	bool			getKilled(int hit_points);

};

#endif
