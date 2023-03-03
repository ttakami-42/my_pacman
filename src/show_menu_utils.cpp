#include "../include/show_menu.h"

int		Menu::control_menu(void)
{
	int	i;

	i = 0;
	while (1)
	{
		ch = wgetch(menuw);
		mvwprintw(menuw, i + 1, 2, "%s", menu_list[i]);
		switch (ch)
		{
			case CONTROL_UP:
				i--;
				i = (i < 0) ? (NUMBER_OF_MITEMS - 1) : i;
				break ;
			case CONTROL_DOWN:
				i++;
				i = (i > (NUMBER_OF_MITEMS - 1)) ? 0 : i;
				break ;
			case CONTROL_NEXT:
				werase(miw);
				wrefresh(miw);
				if (i == 0)
				{
					show_how_to_select();
					return (select_stage());
				}
				else if (i == 1)
					show_how_to_play(miw);
				else if (i == 2)
					show_dev_info();
				else if (i == 3)
					return (END_GAME);
				break ;
		}
		highlight_menu(i);
	}
	return (0);
}

int		Menu::select_stage(void)
{
	stage = 1;
	while (1)
	{
		dh = wgetch(miw);
		switch (dh)
		{
			case CONTROL_DOWN :
				stage--;
				stage = (stage < 1) ? (NUMBER_OF_STAGES) : stage;
				break ;
			case CONTROL_UP :
				stage++;
				stage = (stage > NUMBER_OF_STAGES) ? 1 : stage;
				break ;
			case CONTROL_QUIT :
				return (0);
			case CONTROL_NEXT :
				return (stage);
		}
		mvwprintw(miw, 2, 5, " %d ", stage);
		wattrset(miw, COLOR_PAIR(13));
		mvwprintw(miw, 3, 18, "\"Boys will Be");
		mvwprintw(miw, 4, 18, " Boys, but...\"");
		wattroff(miw, COLOR_PAIR(13));
		wrefresh(miw);
	}
	return (0);
}

void	Menu::show_title(void)
{
	wattrset(titlew, COLOR_PAIR(15));
	box(titlew, ACS_VLINE, ACS_HLINE);
	for (int i = 0; i < int(sizeof(title_ascii) / (int)sizeof(*title_ascii)); i++)
		mvwprintw(titlew, i + 1, 1, title_ascii[i]);
	wattroff(titlew, COLOR_PAIR(15));
	wrefresh(titlew);
}

void	Menu::show_how_to_select(void)
{
	mvwprintw(miw, 1, 2, "Select Map :");
	mvwprintw(miw, 2, 5, " %d ", 1);
	mvwprintw(miw, 5, 2, "'%c' -> Up", CONTROL_UP);
	mvwprintw(miw, 6, 2, "'%c' -> Down", CONTROL_DOWN);
	mvwprintw(miw, 7, 2, "'%c' -> Select", CONTROL_NEXT);
	mvwprintw(miw, 8, 2, "'%c' -> Go Back", CONTROL_QUIT);
	box(miw, ACS_VLINE, ACS_HLINE);
	wrefresh(miw);
}

void	Menu::show_how_to_play(WINDOW *w)
{
	mvwprintw(w, 1, 2, "Controls :");
	mvwprintw(w, 3, 2, "Move Left  -> %c", CONTROL_LEFT);
	mvwprintw(w, 4, 2, "Move Right -> %c", CONTROL_RIGHT);
	mvwprintw(w, 5, 2, "Move Down  -> %c", CONTROL_DOWN);
	mvwprintw(w, 6, 2, "Move Up    -> %c", CONTROL_UP);
	mvwprintw(w, 7, 2, "Pause Game -> p");
	mvwprintw(w, 8, 2, "Quit Game  -> q");
	box(w, ACS_VLINE, ACS_HLINE);
	wrefresh(w);
}

void	Menu::show_dev_info(void)
{
	mvwprintw(miw, 2, 2, "Game Developer :");
	mvwprintw(miw, 5, 2, "Contact info :");
	wattrset(miw, COLOR_PAIR(13));
	mvwprintw(miw, 3, 2, "  \"Tomoki Takami\"");
	mvwprintw(miw, 6, 2, "  https://github.com/ttakami-42");
	wattroff(miw, COLOR_PAIR(13));
	box(miw, ACS_VLINE, ACS_HLINE);
	wrefresh(miw);
}

void	Menu::highlight_menu(int i)
{
	wattron(menuw, A_STANDOUT);
	mvwprintw(menuw, i + 1, 2, "%s", menu_list[i]);
	wattroff(menuw, A_STANDOUT);
}
