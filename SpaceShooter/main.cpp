#include "SpaceShooter.h"
#include "Player.h"
#include "Background.h"

bool	init(t_settings& settings) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
	settings.window = SDL_CreateWindow("Space Shooter",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT + INFOBOX_HEIGHT,
		SDL_WINDOW_SHOWN);


	if (settings.window == NULL) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	settings.renderer = SDL_CreateRenderer(settings.window, -1, SDL_RENDERER_ACCELERATED);
	if (settings.renderer == NULL) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	SDL_SetRenderDrawColor(settings.renderer, 0x61, 0x23, 0x7A, 0xFF);
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cout << IMG_GetError() << std::endl;
		return false;
	}
	if (TTF_Init() == -1) {
		std::cout << TTF_GetError() << std::endl;
		return false;
	}
	return true;
}

void	close(t_settings& settings, Player& player) {
	player.free();

	SDL_DestroyRenderer(settings.renderer);
	SDL_DestroyWindow(settings.window);
	settings.renderer = NULL;
	settings.window = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int		main(int ac, char* av[]) {
	Background background;
	t_settings settings;
	srand(time(0));

	settings.window = NULL;
	settings.renderer = NULL;

	if (!init(settings))
		std::cout << "Failed to initialize!" << std::endl;

	Player	player;
	if (!player.load(PLAYER_IMG, settings))
		std::cout << "Failed to load Player image" << std::endl;
	else {
		bool quit = false;
		SDL_Event event;
		unsigned long ticks = 0;
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		Uint32 currentFrameTime, lastFrameTime = 0;
		float deltaTime = 0.0f;

		while (!quit) {
			currentFrameTime = SDL_GetTicks();
			deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f; 
			lastFrameTime = currentFrameTime;
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT)
					quit = true;
				else if (event.type == SDL_KEYDOWN) {
					if (event.key.keysym.sym == SDLK_ESCAPE)
						quit = true;
				}
			}
			if (currentKeyStates[SDL_SCANCODE_W] || currentKeyStates[SDL_SCANCODE_UP]) {
				player.moveUp();
			}
			if (currentKeyStates[SDL_SCANCODE_S] || currentKeyStates[SDL_SCANCODE_DOWN]) {
				player.moveDown();
			}
			if (currentKeyStates[SDL_SCANCODE_A] || currentKeyStates[SDL_SCANCODE_LEFT]) {
				player.moveLeft();
			}
			if (currentKeyStates[SDL_SCANCODE_D] || currentKeyStates[SDL_SCANCODE_RIGHT]) {
				player.moveRight();
			}
			if (currentKeyStates[SDL_SCANCODE_SPACE]) {
				player.shoot(settings);
			}

			if (ticks % (STAR_HEIGHT * 5) == 0)
				background.makeStar(settings);

			if (ticks % (METEOR_HEIGHT * 20) == 0)
				background.makeMeteor(settings);

			if (ticks % (ENEMY_HEIGHT * 24) == 0)
				background.makeEnemy(settings);

			if (ticks % (ENEMY2_HEIGHT * 24) == 0)
				background.makeEnemy2(settings);

			background.killEnemy(player);
			background.killEnemy2(player);
			background.killMeteor(player);

			if (background.hitEnemy(player) || background.hitEnemy2(player) || background.hitMeteor(player)) {
				SDL_SetRenderDrawColor(settings.renderer, 0x61, 0x23, 0x7A, 0xFF);
				SDL_RenderClear(settings.renderer);
				background.loadGameOver(GAME_OVER, settings);
				SDL_RenderPresent(settings.renderer);
				SDL_Delay(2000);
				break;
			}

			SDL_SetRenderDrawColor(settings.renderer, 0x61, 0x23, 0x7A, 0xFF);
			SDL_RenderClear(settings.renderer);

			background.displayStar(settings);
			background.displayMeteor(settings, (ticks % 2 == 0));
			background.displayEnemy(settings, (ticks % (ENEMY_HEIGHT), deltaTime);
			background.displayEnemy2(settings, (ticks % (ENEMY2_HEIGHT / 2) == 0));

			player.render(settings);
			player.moveBullets(settings);

			background.drawInfoBox(player, settings, ticks / 100);
			SDL_RenderPresent(settings.renderer);
			ticks++;
		}
	}
	close(settings, player);
	return 0;
}
