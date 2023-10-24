#ifndef SPACESHOOTER_HPP
#define SPACESHOOTER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define INFOBOX_HEIGHT (WINDOW_HEIGHT / 5)

#define ENEMY_MAX_QUANTITY 100
#define METEOR_MAX_QUANTITY 20
#define STAR_MAX_QUANTITY 50
#define MAX_BULLETS 100

#define ENEMY_WIDTH 33
#define ENEMY_HEIGHT 17
#define PLAYER_WIDTH 33
#define PLAYER_HEIGHT 25
#define METEOR_WIDTH 64
#define METEOR_HEIGHT 64
#define STAR_WIDTH 10
#define STAR_HEIGHT 10
#define FIREBALL_WIDTH 5
#define FIREBALL_HEIGHT 17

#define METEOR_HIT 20
#define ENEMY_HIT 50

#define METEOR_POINTS 35
#define ENEMY_POINTS 75

#define PLAYER_START_X ((WINDOW_WIDTH / 2) - (PLAYER_WIDTH / 2))
#define PLAYER_START_Y (WINDOW_HEIGHT - PLAYER_HEIGHT - 4)

#define ENEMY_IMG ("Assets/enemyShip.png")
#define PLAYER_IMG ("Assets/player.png")
#define METEOR_IMG ("Assets/meteorBig.png")
#define STAR_IMG ("Assets/starBig.png")
#define FIREBALL_IMG ("Assets/laserGreen.png")
#define GAME_OVER ("Assets/game_over.png")

#define FONT_TTF ("ttf/banksb20.ttf")

#define MUSIC ("audio/moons_001.wav")
class AUnit;
class Player;

typedef struct	s_settings {

	SDL_Window* window;
	SDL_Renderer* renderer;

}				t_settings;

#endif
