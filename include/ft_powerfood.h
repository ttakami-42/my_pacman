#ifndef FT_POWERFOOD_H
# define FT_POWERFOOD_H

# include "ft_global.h"
# include "ft_hero.h"

class Powerfood
{
private:
	int y;
	int x;
	int state;

public:
	// パワーエサを初期化する関数
	void init(int arg_y, int arg_x, int arg_state);

	// パワーエサを指定の座標に表示する関数
	void draw(void);

	// パワーエサがヒーローに衝突したかどうかを判定をする関数
	bool GetPowerFood(Hero h);
};

#endif