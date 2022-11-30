#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include <iostream>
# include <ncurses.h>

namespace	Global_Vars
{
	// キャラクターの移動方向や状態を表す定数
	static const int	INACTIVE = -1;
	static const int	ACTIVE   = 1;
	static const int	UP       = 2;
	static const int	RIGHT    = 3;
	static const int	DOWN     = 4;
	static const int	LEFT     = 5;
	static const int	STOP     = 6;

	// data[][]の要素や色名を参照するときのあだ名
	static const int	WALL      = 1;
	static const int	ROAD      = 2;
	static const int	FOOD      = 3;
	static const int	HERO      = 20;
	static const int	WANI      = 21;
	static const int	GHOST     = 22;
	static const int	POWERFOOD = 23;
	static const int	MESG      = 24;

	// ゲーム中の状態
	static const char	PLAYING  = 'p';
	static const char	ALMIGHTY = 'a';
	static const char	CLEARED  = 'c';
	static const char	GAMEOVER = 'g';

	// getch()でのキー入力の待ち時間（単位:ms）
	static const int	GETCH_WAIT = 10;
	
	// ステージ数
	static const int	NUMBER_OF_STAGES = 3;

	// 用意するワニ, 幽霊, パワーエサの数
	static const int	NUMBER_OF_WANIS      = 5;
	static const int	NUMBER_OF_GHOSTS     = 5;
	static const int	NUMBER_OF_POWERFOODS = 5;

	// メニューの数
	static const int	NUMBER_OF_MITEMS = 4;

	// 無敵時間
	static const int	POWERTIME = 1000;
	
	// ゲーム画面の大きさ
	static const int	GAME_HEIGHT = 50;
	static const int	GAME_WIDTH  = 40;

	// 操作方法の変更
	static const char	CONTROL_UP    = 'w';
	static const char	CONTROL_DOWN  = 's';
	static const char	CONTROL_LEFT  = 'a';
	static const char	CONTROL_RIGHT = 'd';
	static const char	CONTROL_NEXT  = 'e';
	static const char	CONTROL_PAUSE = 'p';
	static const char	CONTROL_QUIT  = 'q';

	// キャラクター用の文字列
	static const char	ILLUST_HERO_ODD[]  = "😃";
	static const char	ILLUST_HERO_EVEN[] = "😊";
	static const char	ILLUST_HERO_ALT[]  = "😁";
	static const char	ILLUST_HERO_DEAD[] = "😂";
	static const char	ILLUST_HERO_CLR[]  = "😆";
	static const char	ILLUST_WANI[]      = "🐊";
	static const char	ILLUST_GHOST[]     = "👻";
	static const char	ILLUST_POWERFOOD[] = "⏳";
};

using namespace Global_Vars;

extern WINDOW *menuw, *miw, *titlew, *gamew, *instw, *bannerw;

#endif
