#include "../include/ft_banner.h"

// ゲーム中に表示するステータス
void	Banner::show_banner(int stage, int pause_flag)
{
	werase(bannerw);
	if (pause_flag)
	{
		wattrset(bannerw, COLOR_PAIR(15));
		box(bannerw, ACS_BULLET, ACS_BULLET);
		mvwprintw(bannerw, 2, 1, "..... Game Paused .....");
		mvwprintw(bannerw, 4, 5, "Press any key:");
		mvwprintw(bannerw, 5, 5, "to continue");
		wattroff(bannerw, COLOR_PAIR(15));
		wrefresh(bannerw);
		wgetch(bannerw);
		werase(bannerw);
	}
	wattrset(bannerw, COLOR_PAIR(18));
	box(bannerw, ' ', ' ');
	mvwprintw(bannerw, 2, 5, "AREA: %d ", stage);
	mvwprintw(bannerw, 4, 5, "Eat all dot:       ");
	wattroff(bannerw, COLOR_PAIR(18));
	wrefresh(bannerw);
}

// ステータスをアップデート
void	Banner::update_banner(int esa)
{
	wclrtoeol(bannerw);
	wattrset(bannerw, COLOR_PAIR(7));
	mvwprintw(bannerw, 4, 17,"%d", esa);
	wattroff(bannerw, COLOR_PAIR(7));
	wrefresh(bannerw);
}

// ゲームオーバーまたはクリアのときの表示
void	Banner::update_banner(char game_state)
{
	werase(bannerw);
	if (game_state == CLEARED)
	{
		wattrset(bannerw, COLOR_PAIR(17));
		box(bannerw, ' ', ' ');
		mvwprintw(bannerw, 2, 5, "GAME CLEAR!!!!! ");
		mvwprintw(bannerw, 4, 5, "HIT THE 'space'");
		mvwprintw(bannerw, 5, 5, "TO GO BACK MENU");
		wattroff(bannerw, COLOR_PAIR(17));
		wrefresh(bannerw);
	}
	if (game_state == GAMEOVER)
	{
		wattrset(bannerw, COLOR_PAIR(12));
		box(bannerw, ' ', ' ');
		mvwprintw(bannerw, 2, 5, "GAME OVER!!!!!! ");
		mvwprintw(bannerw, 4, 5, "HIT THE 'space'");
		mvwprintw(bannerw, 5, 5, "TO GO BACK MENU");
		wattroff(bannerw, COLOR_PAIR(12));
		wrefresh(bannerw);
	}
}
