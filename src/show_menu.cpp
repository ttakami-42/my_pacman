#include "../include/show_menu.h"

int		show_menu(void)
{
	int		stage;
	Menu	menu;

	box(menuw, ACS_VLINE, ACS_HLINE);
	menu.show_title();
	for(size_t i = 0; i < NUMBER_OF_MITEMS; i++)
	{
		if(i == 0)
			wattron(menuw, A_STANDOUT);
		else
			wattroff(menuw, A_STANDOUT);
		mvwprintw(menuw, i + 1, 2, "%s", menu.menu_list[i]);
	}
	mvwprintw(menuw, 11, 2, "'%c' -> Up", CONTROL_UP);
	mvwprintw(menuw, 12, 2, "'%c' -> Down", CONTROL_DOWN);
	mvwprintw(menuw, 13, 2, "Press '%c' to select ", CONTROL_NEXT);
	wrefresh(menuw);
	keypad(menuw, TRUE);
	stage = menu.control_menu();
	return (stage);
}
