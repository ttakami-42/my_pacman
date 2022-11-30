#include "../include/play_game.h"

void	Asset::initAsset(int stage)
{
	(*mp).init(stage);
	hero.init(13, 10);
	if (stage == 1)
	{
		wani[0].init( 9, 7, RIGHT, ACTIVE);
		wani[1].init(12, 12, RIGHT, ACTIVE);
		inactivateAsset(wani, 2, NUMBER_OF_WANIS);
		inactivateAsset(ghost, 0, NUMBER_OF_GHOSTS);
		inactivateAsset(powerfood, 0, NUMBER_OF_POWERFOODS);
	}
	else if (stage == 2)
	{
		wani[0].init(8, 11, STOP, ACTIVE);
		wani[1].init(8, 8, STOP, ACTIVE);
		wani[2].init(18, 7, STOP, ACTIVE);
		wani[3].init(18, 12, STOP, ACTIVE);
		inactivateAsset(wani, 4, NUMBER_OF_WANIS);
		ghost[0].init( 2, 1, ACTIVE);
		ghost[1].init(24, 18, ACTIVE);
		inactivateAsset(ghost, 2, NUMBER_OF_GHOSTS);
		inactivateAsset(powerfood, 0, NUMBER_OF_POWERFOODS);
	}
	else if (stage == 3)
	{
		wani[0].init(20, 14, RIGHT, ACTIVE);
		wani[1].init(15, 16, RIGHT, ACTIVE);
		wani[2].init(9, 10, LEFT, ACTIVE);
		wani[3].init(21, 19, RIGHT, ACTIVE);
		wani[4].init(6, 3, LEFT, ACTIVE);
		inactivateAsset(ghost, 0, NUMBER_OF_GHOSTS);
		powerfood[0].init(19, 10, ACTIVE);
		inactivateAsset(powerfood, 1, NUMBER_OF_POWERFOODS);
	}
}

// カーソルキーを読み取ってヒーローの座標の更新
void	Asset::replaceHero(char c)
{
	hero.waitupdate();
	if (c == CONTROL_UP)
		hero.move(mp, UP);
	else if (c == CONTROL_RIGHT)
		hero.move(mp, RIGHT);
	else if (c == CONTROL_DOWN)
		hero.move(mp, DOWN);
	else if (c == CONTROL_LEFT)
		hero.move(mp, LEFT);
}

// 敵の座標の更新とヒーローとの衝突判定
void	Asset::moveEnemies(void)
{
	for (int i = 0; i < NUMBER_OF_WANIS; i++)
	{
		wani[i].move(mp, hero);
		if (wani[i].killedHero(hero))
			game_state = GAMEOVER;
	}
	for (int i = 0; i < NUMBER_OF_GHOSTS; i++)
	{
		ghost[i].move(hero);
		if (ghost[i].killedHero(hero))
			game_state = GAMEOVER;
	}
	for (int i = 0; i < NUMBER_OF_POWERFOODS; i++)
	{
		if (powerfood[i].GetPowerFood(hero))
			game_state = ALMIGHTY;
	}
}

void	Asset::drawAll(void)
{
	// マップを描画する
	(*mp).drawmap(game_state);

	// ヒーロー・ワニ・幽霊を描画する
	for (int i = 0; i < NUMBER_OF_WANIS; i++)
		wani[i].draw();
	for (int i = 0; i < NUMBER_OF_GHOSTS; i++)
		ghost[i].draw();
	for (int i = 0; i < NUMBER_OF_POWERFOODS; i++)
		powerfood[i].draw();
	hero.draw(game_state);
}

// 画面に文字を表示する
void	Asset::printState(void)
{
	if (game_state == PLAYING)
	{
		esa = (*mp).countUneatenFoods();
		Banner::update_banner(esa);
	}
	else if (game_state == ALMIGHTY)
	{
		esa = (*mp).countUneatenFoods();
		Banner::update_banner(esa);
		(*mp).printString(0, 1, "GO!GO!GO! TIME 1000 / ");
		(*mp).printInt(0, 12, powertime);
	}
	else
		Banner::update_banner(game_state);
}
