#include "../include/ft_wani.h"

// ワニを初期化する関数
void	Wani::init(int arg_y, int arg_x, int arg_direction, int arg_state)
{
	y = arg_y;
	x = arg_x;
	direction = arg_direction;
	state = arg_state;
}

// ワニの座標を更新する関数
void	Wani::move(Map* m, Hero h)
{
	if (state == Const::INACTIVE)
		return ;
	if (y == h.y)                                             // ヒーローとy座標が同じ場合
	{
		wait_max = wait_max_fast;
		if (wait > wait_max)
			wait = 0;
	}
	else
		wait_max = wait_max_slow;
	if (wait > 0)
	{
		wait--;
		return ;
	}
	wait = wait_max;
	if (y == h.y)                                            // ヒーローとy座標が同じ場合
	{
		if (x < h.x)                                         // ワニがヒーローの左側にいる場合
		{
			if ((*m).isWall(y, x + 1))
				direction = Const::STOP;
			else
				direction = Const::RIGHT;
		}
		else if (h.x < x)                                    // ワニがヒーローの右側にいる場合
		{
			if ((*m).isWall(y, x - 1))
				direction = Const::STOP;
			else
				direction = Const::LEFT;
		}
		else                                                 // ヒーローと衝突した場合
			direction = Const::STOP;
	}
	else if ((*m).isWall(y, x + 1) && (*m).isWall(y, x - 1)) // 左右両側が壁の場合
		direction = Const::STOP;
	else if ((*m).isWall(y, x + 1))
		direction = Const::LEFT;
	else if ((*m).isWall(y, x - 1)) 
		direction = Const::RIGHT;

	if (direction == Const::RIGHT)
		x++;
	if (direction == Const::LEFT)
		x--;
}

// ワニを指定の座標に表示する関数
void	Wani::draw(void)
{
	if (state == Const::INACTIVE)
		return ;
	wattrset(gamew,COLOR_PAIR(Const::WANI));
	mvwaddstr(gamew, y, x * 2, "🐊");
}

// ワニがヒーローに衝突したかどうかを判定をする関数
bool	Wani::killedHero(Hero h)
{
	return ((y == h.y) && (x == h.x));
}
