#ifndef FT_WANI_H
# define FT_WANI_H

# include "ft_global.h"
# include "ft_map.h"
# include "ft_hero.h"

// ワニを表現するためのクラス
class Wani
{
private:
	int y;
	int x;
	const int wait_max_slow = 25;
	const int wait_max_fast = 20;
	int wait_max = wait_max_slow;
	int wait = 0;
	int direction;
	int state;

public:
	// ワニを初期化する関数
	void init(int arg_y, int arg_x, int arg_direction, int arg_state);

	// ワニの座標を更新する関数
	void move(Map* m, Hero h);

	// ワニを指定の座標に表示する関数
	void draw(void);

	// ワニがヒーローに衝突したかどうかを判定をする関数
	bool killedHero(Hero h);
};

#endif