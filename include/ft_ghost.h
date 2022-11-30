#ifndef FT_GHOST_H
# define FT_GHOST_H

# include "ft_global.h"
# include "ft_map.h"
# include "ft_hero.h"

class Ghost
{

	private:

		int			y;
		int			x;
		int			wait_max = 140; // GETCH_WAITの140倍という意味
		int			wait = 0;
		const int	vertical = 0;
		const int	horizontal = 1;
		int			direction = vertical;
		int			state;

	public:

		// 幽霊を初期化する関数
		void	init(int arg_y, int arg_x, int arg_state);

		// 幽霊の座標を更新する関数
		void	move(Hero h);
		
		// 幽霊を指定の座標に表示する関数
		void	draw(void);

		// 幽霊がヒーローに衝突したかどうかを判定をする関数
		bool	killedHero(Hero h);
};

#endif
