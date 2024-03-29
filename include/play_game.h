#ifndef PLAY_GAME_H
# define PLAY_GAME_H

/*********************
/To Use Func 'system'/
/# include <stdlib.h>/
*********************/

# include "ft_global.h"
# include "ft_map.h"
# include "ft_hero.h"
# include "ft_wani.h"
# include "ft_ghost.h"
# include "ft_powerfood.h"
# include "ft_banner.h"

class	Asset
{
	private:

		char		game_state = PLAYING;
		int			powertime = 0;
		int			esa;
		Map			map;
		Map*		mp = &map;
		Hero		hero;
		Wani		wani[NUMBER_OF_WANIS];
		Ghost		ghost[NUMBER_OF_GHOSTS];
		Powerfood	powerfood[NUMBER_OF_POWERFOODS];

	public:

		template <typename OBJ>
		void	inactivateAsset(OBJ o, int n, int max)
		{
			for (; n < max; n++)
				o[n].init(INACTIVE, INACTIVE, INACTIVE);
		}
		
		void	initAsset(int stage);
		void	replaceHero(char c);
		void	moveEnemies(void);
		void	drawAll(void);
		void	printState(void);

		char	getGameState(void)
		{
			return (game_state);
		}

		void	setGameState(char c)
		{
			game_state = c;
		}
		int		getPowerTime(void)
		{
			return (powertime);
		}

		void	addPowerTime(void)
		{
			powertime++;
		}

		int		getUneatenFoods(void)
		{
			return ((*mp).countUneatenFoods());
		}
};

void	play_game(int stage);

#endif
