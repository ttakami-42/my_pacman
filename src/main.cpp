#include <locale.h>
#include "../include/show_menu.h"
#include "../include/play_game.h"
#include "../include/ft_window.h"
#include "../include/ft_colors.h"

WINDOW	*menuw, *miw, *titlew, *gamew, *instw, *bannerw;

int		main(void)
{
	int		stage_no;

	setlocale(LC_ALL,"");
	initscr();
	init_colors();
	curs_set(0);
	noecho();
	cbreak();
	timeout(Const::GETCH_WAIT);
	while (1)
	{
		init_bg_colors();
		init_menu_windows();
		stage_no = show_menu();
		del_menu_windows();
		if (stage_no == END_GAME)
		{
			endwin();
			return (0);
		}
		if (stage_no >= 1)
		{
			init_game_windows();
			Menu::show_how_to_play(instw);
			//keypad(gamew, TRUE);
			//system("xset r off");
			play_game(stage_no);
			del_game_windows();
			//system("/usr/bin/xset r rate 500 33");
		}
	}
}
