#ifndef AUNIT_CLASS_HPP
#define AUNIT_CLASS_HPP

#include "SpaceShooter.h"

class AUnit {

private:
	int				_width;
	int				_height;
	int				_x;
	int				_y;
	SDL_Texture* _texture;

public:
	AUnit(void);
	~AUnit(void);

	int				getWidth(void);
	int				getHeight(void);
	int				getX(void);
	int				getY(void);
	SDL_Texture*	getTexture(void);

	void			setWidth(int width);
	void			setHeight(int height);
	void			setX(int x);
	void			setY(int y);

	bool			load(std::string path, t_settings& settings);
	void			free(void);
	void			render(t_settings& settings);

	virtual void	moveDown(void) = 0;
	virtual void	moveRight(void);
	virtual void	moveLeft(void);
	virtual void	moveUp(void);

};

#endif
