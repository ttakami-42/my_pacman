#include <cstring>
#include "../include/ft_map.h"

// ステージ（面）ごとの初期化用関数
void	Map::init(int stage)
{
	switch (stage)
	{
		case 1: // ステージ1のマップのデータをdata[][]にコピー
			memcpy(data, stage1, sizeof stage1);
			break ;
		case 2: // ステージ2のマップのデータをdata[][]にコピー
			memcpy(data, stage2, sizeof stage2);
			break ;
		case 3: // ステージ3のマップのデータをdata[][]にコピー
			memcpy(data, stage3, sizeof stage3);
			break ;
	}
}

// マップを描画する関数
void	Map::drawmap(char game_state)
{
	int		c;
	char	s;

	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			c = data[y][x];
			s = game_state;
			switch (c)
			{
				case WALL:
					if (s == 'p')
					{wattrset(gamew, COLOR_PAIR(WALL)); mvwaddstr(gamew, y, x * 2, "  ");}
					if (s == 'c')
					{wattrset(gamew, COLOR_PAIR(9)); mvwaddstr(gamew, y, x * 2, "  ");}
					if (s == 'g')
					{wattrset(gamew, COLOR_PAIR(4)); mvwaddstr(gamew, y, x * 2, "  ");}
					if (s == 'a')
					{wattrset(gamew, COLOR_PAIR(10)); mvwaddstr(gamew, y, x * 2, "  ");}
					break;
				case ROAD:
					wattrset(gamew, COLOR_PAIR(ROAD)); mvwaddstr(gamew, y, x * 2, "  ");
					break;
				case FOOD:
					wattrset(gamew, COLOR_PAIR(FOOD)); mvwaddstr(gamew, y, x * 2, "🍒"); //"🪙, 🍒"
					break;
			}
		}
	}
}

// マップ上にエサが何個残っているかを数える関数
int		Map::countUneatenFoods(void)
{
	int q = 0;

	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			if (data[y][x] == FOOD)
				q++;
		}
	}
	return (q);
}

// 文字列（定数）を指定の座標に表示する関数
void	Map::printString(int y, int x, const char msg[])
{
	wattrset(gamew, COLOR_PAIR(MESG));
	mvwaddstr(gamew, y, x * 2, msg);
}

// 整数を指定の座標に表示する関数
void	Map::printInt(int y, int x, int n)
{
	wattrset(gamew, COLOR_PAIR(MESG));
	mvwprintw(gamew, y, x * 2, "%d", n);
}
