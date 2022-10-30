#include "../include/ft_ghost.h"

// 幽霊を初期化する関数
void	Ghost::init(int arg_y, int arg_x, int arg_state)
{
	y = arg_y; x = arg_x; state = arg_state;
}

// 幽霊の座標を更新する関数
void	Ghost::move(Hero h)
{
	if (state == Const::INACTIVE) {return;} // 不活性状態
	if (wait > 0) { wait--; return; }

	// waitが0の瞬間だけ、以下の座標の更新処理をおこなう
	wait = wait_max;

	if (direction == vertical) {
		if (y < h.y) { y++;} else if (h.y < y) {y--;}
		direction = horizontal;
	}
	else
	{
		if (x < h.x) { x++;} else if (h.x < x) {x--;}
		direction = vertical;
	}
}

// 幽霊を指定の座標に表示する関数
void	Ghost::draw()
{
	if (state == Const::INACTIVE) { return; }
	wattrset(gamew, COLOR_PAIR(Const::GOST));
	mvwaddstr(gamew, y, x * 2, "👻");
}

// 幽霊がヒーローに衝突したかどうかを判定をする関数
bool	Ghost::killedHero(Hero h)
{
	if ((y == h.y) && (x == h.x)) { return true; }
	else { return false; }
}