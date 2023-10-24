#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "SpaceShooter.h"
#include "Fireball.h"
#include "Enemy.h"
#include "Star.h"
#include "Meteor.h"
#include "Meteor2.h"
#include "Player.h"
#include "Enemy2.h"

class Background {

private:
	Enemy* _enemies[ENEMY_MAX_QUANTITY];
	Enemy2* _enemies2[ENEMY2_MAX_QUANTITY];
	Meteor* _meteors[METEOR_MAX_QUANTITY];
	Meteor2* _meteors2[METEOR2_MAX_QUANTITY];
	Star* _stars[STAR_MAX_QUANTITY];
	SDL_Texture* _texture;
	SDL_Texture* bgTexture;

public:
	Background(void);
	~Background(void);

	void	free(void);
	void	clean(void);
	void	loadGameOver(std::string, t_settings&);
	void	drawInfoBox(Player&, t_settings&, unsigned long);

	void	makeStar(t_settings&);
	void	makeMeteor(t_settings&);
	void	makeMeteor2(t_settings&);
	void	makeEnemy(t_settings&);
	void	makeEnemy2(t_settings&);

	void	render(t_settings& settings);
	bool	loadBackground(const char* path, t_settings& settings);
	void	displayStar(t_settings&);
	void	displayMeteor(t_settings&, bool);
	void	displayMeteor2(t_settings&, bool);
	void	displayEnemy(t_settings&, bool);
	void	displayEnemy2(t_settings&, bool);

	bool	hitEnemy(Player& player);
	bool	hitEnemy2(Player& player);
	bool	hitMeteor(Player& player);
	bool	hitMeteor2(Player& player);

	void	killEnemy(Player& player);
	void	killEnemy2(Player& player);
	void	killMeteor(Player& player);
	void	killMeteor2(Player& player);


};

#endif
