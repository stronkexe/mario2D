/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:42:14 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/19 17:55:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

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
	//////////// imgs
	int		img_w;
	int		img_h;
	void	*background;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
	//////////// player
	int		x_player;
	int		y_player;
}	t_game;

//// -------------- keys
# define KEY_EXIT 27

//// -------------- map
void	get_game(char *av, t_game *my_game);
void	map_game(t_game *my_game);
void	game_img(t_game *my_game);

//// -------------- game_play
void	play_game(t_game *my_game);

//// -------------- utils
char	**ft_split(char *s, char c);
int		ft_strlen(char *s);
char	*ft_substr(char	*s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, int n);

#endif