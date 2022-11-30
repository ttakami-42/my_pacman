#include "../include/ft_powerfood.h"

// パワーエサを初期化する関数
void	Powerfood::init(int arg_y, int arg_x, int arg_state)
{
	y = arg_y;
	x = arg_x;
	state = arg_state;
}

// パワーエサを指定の座標に表示する関数
void	Powerfood::draw(void)
{
	if (state == INACTIVE)
		return ;
	wattrset(gamew, COLOR_PAIR(POWERFOOD));
	mvwaddstr(gamew, y, x * 2, ILLUST_POWERFOOD);
}

// パワーエサがヒーローに衝突したかどうかを判定をする関数
bool	Powerfood::GetPowerFood(Hero h)
{
	if ((y == h.y) && (x == h.x))
	{
		state = INACTIVE;
		return (true);
	}
	else
		return (false);
}
