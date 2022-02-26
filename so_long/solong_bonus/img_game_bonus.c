/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:33:20 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/26 17:01:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	leave_game(void)
{
	exit(1);
}

void	print_moves(t_game *my_game)
{
	char	*n;

	mlx_string_put(my_game->mlx, my_game->win, 32, 35, 0x000, "Moves: \n");
	n = ft_itoa(my_game->moves);
	mlx_string_put(my_game->mlx, my_game->win, 100, 35, 0x000, n);
	free(n);
}

void	game_img(t_game *my_game)
{
	my_game->background = mlx_xpm_file_to_image(my_game->mlx,
			"imgs/background.xpm", &my_game->img_w, &my_game->img_h);
	my_game->wall = mlx_xpm_file_to_image(my_game->mlx,
			"imgs/wall.xpm", &my_game->img_w, &my_game->img_h);
	my_game->player = mlx_xpm_file_to_image(my_game->mlx,
			"imgs/m1.xpm", &my_game->img_w, &my_game->img_h);
	my_game->collect = mlx_xpm_file_to_image(my_game->mlx,
			"imgs/c1.xpm", &my_game->img_w, &my_game->img_h);
	my_game->enemy = mlx_xpm_file_to_image(my_game->mlx,
			"imgs/enemy1.xpm", &my_game->img_w, &my_game->img_h);
	my_game->exit = mlx_xpm_file_to_image(my_game->mlx,
			"imgs/exit1.xpm", &my_game->img_w, &my_game->img_h);
	if (!my_game->background || !my_game->wall || !my_game->player
		|| !my_game->collect || !my_game->enemy || !my_game->exit)
	{
		ft_putstr_error_exit("invalid image\n");
	}
}
