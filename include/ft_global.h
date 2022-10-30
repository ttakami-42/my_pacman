#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include <iostream>
# include <ncurses.h>

class Const
{
public:

	// キャラクターの移動方向や状態を表す定数
	static const int	INACTIVE = 0;
	static const int	ACTIVE   = 1;
	static const int	UP       = 2;
	static const int	RIGHT    = 3;
	static const int	DOWN     = 4;
	static const int	LEFT     = 5;
	static const int	STOP     = 6;

	// data[][]の要素や色名を参照するときのあだ名
	static const int	WALL =  1;
	static const int	ROAD =  2;
	static const int	FOOD =  3;
	static const int	HERO =  20;		// 色でのみ使用（マップでは不使用）
	static const int	WANI =  21;		// 色でのみ使用（マップでは不使用）
	static const int	GOST =  22;		// 色でのみ使用（マップでは不使用）
	static const int	POWERFOOD = 23;	// 色でのみ使用（マップでは不使用）
	static const int	MESG =  24;		// 色でのみ使用（マップでは不使用）

	// ゲーム中の状態
	static const char	PLAYING  = 'p'; // プレイしている状態
	static const char	ALMIGHTY = 'a'; // パワーエサを取った状態
	static const char	CLEARED  = 'c'; // 現在のステージをクリアした状態
	static const char	GAMEOVER = 'g'; // ゲームオーバー

	// getch()でのキー入力の待ち時間（単位:ms）
	static const int	GETCH_WAIT = 10;
	
	// ステージ数
	static const int	NUMBER_OF_STAGES = 3;

	// 用意するワニと幽霊の頭数
	static const int	NUMBER_OF_WANIS = 5;
	static const int	NUMBER_OF_GHOSTS = 5;
	
	// パワーエサの数
	static const int	NUMBER_OF_POWERFOODS = 5;
	
	// メニューの数
	static const int	NITEMS = 4;

	// 無敵時間
	static const int	POWERTIME = 1000;
	
	// ゲーム画面の大きさ
	static const int	GAME_HEIGHT = 50;
	static const int	GAME_WIDTH = 40;

	// 操作方法の変更
	static const char	CONTROL_UP = 'w';
	static const char	CONTROL_DOWN = 's';
	static const char	CONTROL_LEFT = 'a';
	static const char	CONTROL_RIGHT = 'd';
	static const char	CONTROL_NEXT = 'e';
	static const char	CONTROL_BACK = 'q';
};

extern WINDOW *menuw, *miw, *titlew, *gamew, *instw, *bannerw, *pausew;

#endif