#include "../include/ft_wani.h"

// ワニを初期化する関数
void	Wani::init(int arg_y, int arg_x, int arg_direction, int arg_state)
{
	y = arg_y; x = arg_x; direction = arg_direction; state = arg_state;
}

// ワニの座標を更新する関数
void	Wani::move(Map* m, Hero h)
{
	if (state == Const::INACTIVE) { return; } // 不活性状態
	if (y == h.y) // ヒーローとy座標が同じ場合
	{
		wait_max = wait_max_fast; // スピードアップ
		if (wait > wait_max) { wait = 0; } // 少し反応が早くなる
	}
	else { wait_max = wait_max_slow; } // 遅めのウェイト

	if (wait > 0) { wait--; return; }

	// waitが0の瞬間だけ、以下の座標の更新処理をおこなう
	wait = wait_max;
	if (y == h.y) // ヒーローとy座標が同じ場合
	{
		if (x < h.x) // ワニがヒーローの左側にいる場合
		{
			if ((*m).isWall(y, x + 1)) { direction = Const::STOP; }
			else { direction = Const::RIGHT; }
		}
		else if (h.x < x) // ワニがヒーローの右側にいる場合
		{
			if ((*m).isWall(y, x - 1)) { direction = Const::STOP; }
			else { direction = Const::LEFT; }
		}
		else { direction = Const::STOP; } // ヒーローと衝突したら停止
	}
	else if ((*m).isWall(y, x + 1) && (*m).isWall(y, x - 1))
		direction = Const::STOP; // 左右両側が壁の場合は停止
	else if ((*m).isWall(y, x + 1))
		direction = Const::LEFT;
	else if ((*m).isWall(y, x - 1)) 
		direction = Const::RIGHT;

	switch (direction)
	{
		case Const::RIGHT: x++; break;
		case Const::LEFT:  x--; break;
	}
}
	
	// ワニを指定の座標に表示する関数
void	Wani::draw()
{
	if (state == Const::INACTIVE) { return; }
	wattrset(gamew,COLOR_PAIR(Const::WANI));
	mvwaddstr(gamew, y, x * 2, "🐊");
}

// ワニがヒーローに衝突したかどうかを判定をする関数
bool	Wani::killedHero(Hero h)
{
	if ((y == h.y) && (x == h.x)) { return true; }
	else { return false; }
}
