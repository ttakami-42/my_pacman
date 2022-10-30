#include "../include/ft_window.h"

void	init_menu_windows(void)
{
	menuw = newwin(15, 25, 8, 14);
	miw = newwin(10, 45, 10, 40);
	titlew = newwin(7, 44, 1, 14);
}

// ウィンドウの初期化
void	init_game_windows(void)
{
	gamew = newwin(Const::GAME_HEIGHT, Const::GAME_WIDTH, 0, 0);
	instw = newwin(Const::GAME_HEIGHT - 40, Const::GAME_WIDTH - 15, 6, Const::GAME_WIDTH);
	bannerw = newwin(8, Const::GAME_WIDTH - 15, 16, Const::GAME_WIDTH);
}

// ウィンドウの消去
void	del_game_windows(void)
{
	werase(gamew);
	werase(instw);
	werase(bannerw);
	wrefresh(gamew);
	wrefresh(instw);
	wrefresh(bannerw);
	delwin(gamew);
	delwin(instw);
	delwin(bannerw);
}

void	del_menu_windows(void)
{
	werase(menuw);
	werase(miw);
	werase(titlew);
	wrefresh(menuw);
	wrefresh(miw);
	wrefresh(titlew);
	delwin(menuw);
	delwin(miw);
	delwin(titlew);
}