#include "../include/ft_hero.h"

// ヒーローを初期化する関数
void	Hero::init(int arg_y, int arg_x) { y = arg_y; x = arg_x; wait = 0; }

// ヒーローのwaitを減らす関数
void	Hero::waitupdate() { if (wait > 0) { wait --;} }

// ヒーローの座標を更新する関数
void	Hero::move(Map* m, int direction)
{
	if (wait > 0) { wait--; return; }
	switch (direction)
	{
		case Const::UP:
			if (!(*m).isWall(y - 1, x)) { y--; }
			if ((*m).isFood(y, x)) { (*m).eaten(y, x); }
			break;
		case Const::RIGHT:
			if (!(*m).isWall(y, x + 1)) { x++; }
			if ((*m).isFood(y, x)) { (*m).eaten(y, x); }
			break;
		case Const::DOWN:
			if (!(*m).isWall(y + 1, x)) { y++; }
			if ((*m).isFood(y, x)) { (*m).eaten(y, x); }
			break;
		case Const::LEFT:
			if (!(*m).isWall(y, x - 1)) { x--; }
			if ((*m).isFood(y, x)) { (*m).eaten(y, x); }
			break;
	}
	wait = wait_max;
}

// ヒーローを指定の座標に表示する関数
void	Hero::draw(char game_state)
{
	wattrset(gamew, COLOR_PAIR(Const::HERO));
	switch(game_state)
	{
		case Const::PLAYING:
			if ((y + x) % 2) { mvwaddstr(gamew, y, x * 2, "😃"); }
			else { mvwaddstr(gamew, y, x * 2, "😊"); }
			break;
		case Const::ALMIGHTY:
			mvwaddstr(gamew, y, x * 2, "😁");
			break;
		case Const::GAMEOVER:
			mvwaddstr(gamew, y, x * 2, "😂");
			break;
		case Const::CLEARED:
			mvwaddstr(gamew, y, x * 2, "😆");
			break;
	}
}