#ifndef FT_BANNER_H
# define FT_BANNER_H

# include "ft_global.h"

class	Banner
{
	public:

		static void	show_banner(int stage, int pause_flag);
		static void	update_banner(int esa);
		static void	update_banner(char game_state);
};

#endif
