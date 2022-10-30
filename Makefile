NAME	= pacman
CC		= g++
CFLAGS	= -std=c++17 -Wall -Wextra -Werror
MLIB	= -lncurses
ULIB	= -lncursesw
SRCS	= main.cpp play_game_utils.cpp \
			play_game.cpp show_menu.cpp \
			show_menu_utils.cpp ft_window.cpp \
			ft_colors.cpp ft_banner.cpp ft_map.cpp \
			ft_hero.cpp ft_ghost.cpp \
			ft_wani.cpp ft_powerfood.cpp
OBJDIR	= obj
OBJS	= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: directories $(NAME)

directories:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJDIR)/%.o:	%.cpp
	@[ -d $(OBJDIR) ]
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(ULIB)

.PHONY: all clean fclean re

vpath %.cpp src
