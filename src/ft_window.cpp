#include "../include/ft_window.h"

// メニューウィンドウの初期化
void	init_menu_window(void)
{
	menuw = newwin(15, 25, 8, 14);
	miw = newwin(10, 35, 10, 40);
	titlew = newwin(7, 44, 1, 20);
}

// ゲームウィンドウの初期化
void	init_game_window(void)
{
	gamew = newwin(GAME_HEIGHT, GAME_WIDTH, 0, 0);
	instw = newwin(GAME_HEIGHT / 5, GAME_HEIGHT / 2, GAME_HEIGHT / 8, GAME_WIDTH);
	bannerw = newwin(GAME_HEIGHT / 6, GAME_HEIGHT / 2, GAME_HEIGHT / 3, GAME_WIDTH);
}

// メニューウィンドウの消去
void	del_menu_window(void)
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

// ゲームウィンドウの消去
void	del_game_window(void)
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
