/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:42:14 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/25 12:50:39 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "stdio.h"
# include "fcntl.h"

# include "mlx/mlx.h"
# include "utils/gnl/get_next_line.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	void	*background;
	void	*wall;
	void	*player;
	void	*collect;
	void	*enemy;
	void	*exit;
	int		x_player;
	int		y_player;
	int		nb_collect;
	int		moves;
	int		frame;
	int		loop;
	int		gg;
}	t_game;

//// -------------- map
void	get_game(char *av, t_game *my_game);
int		map_game(t_game *my_game);
void	game_img(t_game *my_game);
int		check_map(t_game *my_game);
int		check_rev_file(char *s);
int		check_ifclosed(t_game *my_game);

//// -------------- game_play
void	play_game(t_game *my_game);

//// -------------- player
void	player_game(int key, t_game *my_game);
void	destroy_window(t_game *my_game);
void	mv_player_w(t_game *my_game);
void	mv_player_s(t_game *my_game);
void	mv_player_d(t_game *my_game);
void	mv_player_a(t_game *my_game);
//// -------------- utils
char	**ft_split(char *s, char c);
int		ft_strlen(char *s);
char	*ft_substr(char	*s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr(char *s);
void	ft_putstr_error_exit(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
char	*ft_itoa(int n);

#endif