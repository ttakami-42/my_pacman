#include "../include/ft_banner.h"

// ゲーム中に表示するステータス
void	Banner::show_banner(int stage)
{
	wclear(bannerw);
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
	if(game_state == 'c')
	{
		wattrset(bannerw, COLOR_PAIR(17));
		box(bannerw, ' ', ' ');
		mvwprintw(bannerw, 2, 5, "GAME CLEAR!!!!! ");
		mvwprintw(bannerw, 4, 5, "HIT THE 'space'");
		mvwprintw(bannerw, 5, 5, "TO GO BACK MENU");
		wattroff(bannerw, COLOR_PAIR(17));
		wrefresh(bannerw);
	}
	if(game_state == 'g')
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

// ポーズメニューの作成
void	Banner::show_pausebanner(void)
{
	pausew = newwin(8, Const::GAME_WIDTH - 15, 16, Const::GAME_WIDTH);
	wattrset(pausew, COLOR_PAIR(15));
	box(pausew, ACS_BULLET, ACS_BULLET);
	mvwprintw(pausew, 2, 1, "..... Game Paused .....");
	mvwprintw(pausew, 4, 5, "Press any key:");
	mvwprintw(pausew, 5, 5, "to continue");
	wattroff(pausew, COLOR_PAIR(15));
	wrefresh(pausew);
	wgetch(pausew);
}
