#include "../include/ft_colors.h"

// 色の設定（使っていない色も含む）
void	init_colors(void)
{
	start_color();
	init_pair(4,  COLOR_BLACK,   COLOR_RED);
	init_pair(5,  COLOR_BLACK,   COLOR_CYAN);
	init_pair(6,  COLOR_BLACK,   COLOR_BLUE);
	init_pair(7,  COLOR_BLACK,   COLOR_YELLOW);
	init_pair(8,  COLOR_BLACK,   COLOR_WHITE);
	init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
	init_pair(10, COLOR_BLACK,   COLOR_MAGENTA);
	init_pair(11, COLOR_BLACK,   COLOR_BLACK);
	init_pair(12, COLOR_RED,     COLOR_BLACK);
	init_pair(13, COLOR_CYAN,    COLOR_BLACK);
	init_pair(14, COLOR_BLUE,    COLOR_BLACK);
	init_pair(15, COLOR_YELLOW,  COLOR_BLACK);
	init_pair(16, COLOR_WHITE,   COLOR_BLACK);
	init_pair(17, COLOR_GREEN,   COLOR_BLACK);
	init_pair(18, COLOR_MAGENTA, COLOR_BLACK);

	init_pair(WALL, COLOR_BLACK,    COLOR_CYAN);
	init_pair(ROAD, COLOR_BLACK,    COLOR_BLACK);
	init_pair(FOOD, COLOR_YELLOW,   COLOR_BLACK);
	init_pair(HERO, COLOR_YELLOW,   COLOR_BLACK);
	init_pair(WANI, COLOR_GREEN,    COLOR_BLACK);
	init_pair(GHOST, COLOR_WHITE,   COLOR_BLACK);
	init_pair(MESG, COLOR_WHITE,    COLOR_BLACK);
	init_pair(POWERFOOD, COLOR_RED, COLOR_BLACK);
}

void	init_bg_colors(void)
{
	bkgd(COLOR_PAIR(11));
	erase();
	refresh();
}
