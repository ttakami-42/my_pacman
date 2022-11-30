#include "../include/ft_hero.h"

// ヒーローを初期化する関数
void	Hero::init(int arg_y, int arg_x)
{
	y = arg_y;
	x = arg_x;
	wait = 0;
}

// ヒーローのwaitを減らす関数
void	Hero::waitupdate(void)
{
	if (wait > 0)
		wait--;
}

// ヒーローの座標を更新する関数
void	Hero::move(Map* m, int direction)
{
	if (wait > 0)
	{
		wait--;
		return ;
	}
	switch (direction)
	{
		case UP:
			if (!(*m).isWall(y - 1, x))
				y--;
			if ((*m).isFood(y, x))
				(*m).eaten(y, x);
			break ;
		case RIGHT:
			if (!(*m).isWall(y, x + 1))
				x++;
			if ((*m).isFood(y, x))
				(*m).eaten(y, x);
			break ;
		case DOWN:
			if (!(*m).isWall(y + 1, x))
				y++;
			if ((*m).isFood(y, x))
				(*m).eaten(y, x);
			break ;
		case LEFT:
			if (!(*m).isWall(y, x - 1))
				x--;
			if ((*m).isFood(y, x))
				(*m).eaten(y, x);
			break ;
	}
	wait = wait_max;
}

// ヒーローを指定の座標に表示する関数
void	Hero::draw(char game_state)
{
	wattrset(gamew, COLOR_PAIR(HERO));
	switch (game_state)
	{
		case PLAYING:
			if ((y + x) % 2)
				mvwaddstr(gamew, y, x * 2, ILLUST_HERO_ODD);
			else
				mvwaddstr(gamew, y, x * 2, ILLUST_HERO_EVEN);
			break ;
		case ALMIGHTY:
			mvwaddstr(gamew, y, x * 2, ILLUST_HERO_ALT);
			break ;
		case GAMEOVER:
			mvwaddstr(gamew, y, x * 2, ILLUST_HERO_DEAD);
			break ;
		case CLEARED:
			mvwaddstr(gamew, y, x * 2, ILLUST_HERO_CLR);
			break ;
	}
}
