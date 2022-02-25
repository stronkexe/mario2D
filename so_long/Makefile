# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 18:47:14 by ael-asri          #+#    #+#              #
#    Updated: 2022/02/25 12:51:04 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BNAME = bonus

SRC = so_long.c\
	map_game.c\
	get_map.c\
	check_map.c\
	check_map2.c\
	img_game.c\
	play_game.c\
	player_game.c\
	player_game_mv.c\
	utils/gnl/get_next_line.c\
	utils/gnl/get_next_line_utils.c\
	utils/ft_split.c\
	utils/utils.c\
	utils/utils2.c\

BSRC = solong_bonus/so_long_bonus.c\
	solong_bonus/map_game_bonus.c\
	solong_bonus/get_map_bonus.c\
	solong_bonus/check_map_bonus.c\
	solong_bonus/check_map2_bonus.c\
	solong_bonus/img_game_bonus.c\
	solong_bonus/play_game_bonus.c\
	solong_bonus/player_game_bonus.c\
	solong_bonus/player_game_mv_bonus.c\
	utils/gnl/get_next_line.c\
	utils/gnl/get_next_line_utils.c\
	utils/ft_split.c\
	utils/ft_itoa.c\
	utils/utils.c\
	utils/utils2.c\

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

#$(NAME) : $(OBJ)
#		cc $(CFLAGS) -Imlx $^ -o $@

$(NAME): $(OBJ)
	cc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BNAME): $(BOBJ)
	cc $(BOBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

%.o: %.c
	cc -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BNAME)

re : fclean all

.PHONY : all clean fclean re