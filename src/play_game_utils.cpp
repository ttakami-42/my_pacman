#include "../include/play_game.h"

void	Asset::initAsset(int stage)
{
	(*mp).init(stage);
	hero.init(13, 10);
	if (stage == 1)
	{
		wani[0].init( 9, 7, Const::RIGHT, Const::ACTIVE);
		wani[1].init(12, 12, Const::RIGHT, Const::ACTIVE);
		inactivateAsset(wani, 2, Const::NUMBER_OF_WANIS);
		inactivateAsset(ghost, 0, Const::NUMBER_OF_GHOSTS);
		inactivateAsset(powerfood, 0, Const::NUMBER_OF_POWERFOODS);
	}
	else if (stage == 2)
	{
		wani[0].init(8, 11, Const::STOP, Const::ACTIVE);
		wani[1].init(8, 8, Const::STOP, Const::ACTIVE);
		wani[2].init(18, 7, Const::STOP, Const::ACTIVE);
		wani[3].init(18, 12, Const::STOP, Const::ACTIVE);
		inactivateAsset(wani, 4, Const::NUMBER_OF_WANIS);
		ghost[0].init( 2, 1, Const::ACTIVE);
		ghost[1].init(24, 18, Const::ACTIVE);
		inactivateAsset(ghost, 2, Const::NUMBER_OF_GHOSTS);
		inactivateAsset(powerfood, 0, Const::NUMBER_OF_POWERFOODS);
	}
	else if (stage == 3)
	{
		wani[0].init(20, 14, Const::RIGHT, Const::ACTIVE);
		wani[1].init(15, 16, Const::RIGHT, Const::ACTIVE);
		wani[2].init(9, 10, Const::LEFT, Const::ACTIVE);
		wani[3].init(21, 19, Const::RIGHT, Const::ACTIVE);
		wani[4].init(6, 3, Const::LEFT, Const::ACTIVE);
		inactivateAsset(ghost, 0, Const::NUMBER_OF_GHOSTS);
		powerfood[0].init(19, 10, Const::ACTIVE);
		inactivateAsset(powerfood, 1, Const::NUMBER_OF_POWERFOODS);
	}
}

// カーソルキーを読み取ってヒーローの座標の更新
void	Asset::replaceHero(char c)
{
	hero.waitupdate();
	if (c == Const::CONTROL_UP)
		hero.move(mp, Const::UP);
	else if (c == Const::CONTROL_RIGHT)
		hero.move(mp, Const::RIGHT);
	else if (c == Const::CONTROL_DOWN)
		hero.move(mp, Const::DOWN);
	else if (c == Const::CONTROL_LEFT)
		hero.move(mp, Const::LEFT);
}

// 敵の座標の更新とヒーローとの衝突判定
void	Asset::moveEnemies(void)
{
	for (int i = 0; i < Const::NUMBER_OF_WANIS; i++)
	{
		wani[i].move(mp, hero);
		if (wani[i].killedHero(hero))
			game_state = Const::GAMEOVER;
	}
	for (int i = 0; i < Const::NUMBER_OF_GHOSTS; i++)
	{
		ghost[i].move(hero);
		if (ghost[i].killedHero(hero))
			game_state = Const::GAMEOVER;
	}
	for (int i = 0; i < Const::NUMBER_OF_POWERFOODS; i++)
	{
		if (powerfood[i].GetPowerFood(hero))
			game_state = Const::ALMIGHTY;
	}
}

void	Asset::drawAll(void)
{
	// マップを描画する
	(*mp).drawmap(game_state);

	// ヒーロー・ワニ・幽霊を描画する
	for (int i = 0; i < Const::NUMBER_OF_WANIS; i++)
		wani[i].draw();
	for (int i = 0; i < Const::NUMBER_OF_GHOSTS; i++)
		ghost[i].draw();
	for (int i = 0; i < Const::NUMBER_OF_POWERFOODS; i++)
		powerfood[i].draw();
	hero.draw(game_state);
}

// 画面に文字を表示する
void	Asset::printState(void)
{
	if (game_state == Const::PLAYING)
	{
		esa = (*mp).countUneatenFoods();
		Banner::update_banner(esa);
	}
	else if (game_state == Const::ALMIGHTY)
	{
		esa = (*mp).countUneatenFoods();
		Banner::update_banner(esa);
		(*mp).printString(0, 1, "GO!GO!GO! TIME 1000 / ");
		(*mp).printInt(0, 12, powertime);
	}
	else
		Banner::update_banner(game_state);
}
