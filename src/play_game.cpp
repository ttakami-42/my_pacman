#include "../include/play_game.h"

void	play_game(int stage)
{
	char	ch;
	char	state;
	Asset	asset;

	//system("xset r off");
	Banner::show_banner(stage);
	asset.initAsset(stage);
	while (1)
	{
		ch = getch();
		state = asset.getGameState();
		if (ch == 'p' && (state == Const::PLAYING || state == Const::ALMIGHTY))
		{
			Banner::show_pausebanner();
			Banner::show_banner(stage);
		}
		if (ch == 'q' && (state == Const::PLAYING || state == Const::ALMIGHTY))
			return ;
		if ((state == Const::CLEARED || (state == Const::GAMEOVER)) && (ch == ' '))
			return ;
		if (state == Const::PLAYING)
		{
			asset.replaceHero(ch);
			asset.moveEnemies();
			state = asset.getGameState();
		}
		if (state == Const::ALMIGHTY)
		{
			asset.replaceHero(ch);
			asset.addPowerTime();
			if (asset.getPowerTime() > Const::POWERTIME)
				asset.setGameState(Const::PLAYING);
		}
		werase(gamew);
		asset.drawAll();
		asset.printState();
		wrefresh(gamew);
		if (asset.getUneatenFoods() == 0)
			asset.setGameState(Const::CLEARED);
	}
	return ;
}
