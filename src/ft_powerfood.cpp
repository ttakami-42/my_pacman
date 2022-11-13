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
	if (state == Const::INACTIVE)
		return ;
	wattrset(gamew, COLOR_PAIR(Const::POWERFOOD));
	mvwaddstr(gamew, y, x * 2, "⏳");
}

// パワーエサがヒーローに衝突したかどうかを判定をする関数
bool	Powerfood::GetPowerFood(Hero h)
{
	if ((y == h.y) && (x == h.x))
	{
		state = Const::INACTIVE;
		return (true);
	}
	else
		return (false);
}
