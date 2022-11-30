#include "../include/play_game.h"

void	play_game(int stage)
{
	char	ch;
	char	state;
	Asset	asset;

	Banner::show_banner(stage, 0);
	asset.initAsset(stage);
	while (1)
	{
		ch = getch();
		state = asset.getGameState();
		if (ch == CONTROL_PAUSE && (state == PLAYING || state == ALMIGHTY))
			Banner::show_banner(stage, 1);
		if (ch == CONTROL_QUIT && (state == PLAYING || state == ALMIGHTY))
			return ;
		if ((state == CLEARED || (state == GAMEOVER)) && (ch == ' '))
			return ;
		if (state == PLAYING)
		{
			asset.replaceHero(ch);
			asset.moveEnemies();
			state = asset.getGameState();
		}
		if (state == ALMIGHTY)
		{
			asset.replaceHero(ch);
			asset.addPowerTime();
			if (asset.getPowerTime() > POWERTIME)
				asset.setGameState(PLAYING);
		}
		werase(gamew);
		asset.drawAll();
		asset.printState();
		wrefresh(gamew);
		if (asset.getUneatenFoods() == 0)
			asset.setGameState(CLEARED);
	}
	return ;
}
