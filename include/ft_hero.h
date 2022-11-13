#ifndef FT_HERO_H
# define FT_HERO_H

# include "ft_global.h"
# include "ft_map.h"

// ヒーローを表現するためのクラス
class Hero
{
private:
	const int wait_max = 7;
	int wait = 0;

public:
	int y;
	int x;

	// ヒーローを初期化する関数
	void init(int arg_y, int arg_x);

	// ヒーローのwaitを減らす関数
	void waitupdate(void);

	// ヒーローの座標を更新する関数
	void move(Map* m, int direction);

	// ヒーローを指定の座標に表示する関数
	void draw(char game_state);
};

#endif