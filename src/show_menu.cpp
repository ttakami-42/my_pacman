#include "../include/show_menu.h"

int		show_menu(void)
{
	int		stage;
	Menu	menu;

	box(menuw, ACS_VLINE, ACS_HLINE);
	menu.show_title();
	for(size_t i = 0; i < Const::NITEMS; i++)
	{
		if(i == 0)
			wattron(menuw, A_STANDOUT);
		else
			wattroff(menuw, A_STANDOUT);
		std::snprintf(menu.item, sizeof(menu.item), "%s", menu.LIST[i]);
		mvwprintw(menuw, i + 1, 2, "%s", menu.item);
	}
	mvwprintw(menuw, 11, 2, "'%c' -> Up", Const::CONTROL_UP);
	mvwprintw(menuw, 12, 2, "'%c' -> Down", Const::CONTROL_DOWN);
	mvwprintw(menuw, 13, 2, "Press '%c' to select ", Const::CONTROL_NEXT);
	wrefresh(menuw);
	keypad(menuw, TRUE);
	stage = menu.control_menu();
	return (stage);
}
