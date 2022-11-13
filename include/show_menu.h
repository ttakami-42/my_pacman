#ifndef SHOW_MENU_H
# define SHOW_MENU_H

# define END_GAME -1

# include "ft_global.h"
# include <cstdio>

class Menu
{
public:

	static inline const char	LIST[Const::NITEMS][20] = {
		"New Game",
		"Instructions",
		"About Developers",
		"Exit"
	};
	static inline const char	title_ascii[5][45] = {
		"  _ __   __ _  ___ _ __ ___   __ _ _ __   ",
		" | '_ \\ / _` |/ __| '_ ` _ \\ / _` | '_ \\  ",
		" | |_) | (_| | (__| | | | | | (_| | | | | ",
		" | .__/ \\__,_|\\___|_| |_| |_|\\__,_|_| |_| ",
		" |_|                                      "
	};

	int		stage = 0;
	int		ch;
	int		dh;
	char	item[20];

	int			control_menu(void);
	int			select_stage(void);
	void		show_title(void);
	void		show_how_to_select(void);
	static void	show_how_to_play(WINDOW *w);
	void		show_dev_info(void);
	void		highlight_menu(int i);
};

int	show_menu(void);

#endif