/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:33:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/25 20:20:13 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_val(int key, t_game *my_game)
{
	if (key == 53)
	{
		mlx_destroy_window(my_game->mlx, my_game->win);
		exit(0);
	}
	else if (key == 13 || key == 1
		|| key == 2 || key == 0)
		player_game(key, my_game);
	else
		return (0);
	return (1);
}

void	frames_animation(t_game *my_game)
{
	if (my_game->frame == 1)
	{
		my_game->collect = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/c1.xpm", &my_game->img_w, &my_game->img_h);
	}
	else if (my_game->frame == 2)
	{
		my_game->collect = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/c2.xpm", &my_game->img_w, &my_game->img_h);
	}
	else if (my_game->frame == 3)
	{
		my_game->collect = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/c3.xpm", &my_game->img_w, &my_game->img_h);
	}
}

void	frames_animation2(t_game *my_game)
{
	if (my_game->frame == 4)
	{
		my_game->collect = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/c4.xpm", &my_game->img_w, &my_game->img_h);
	}
	else if (my_game->frame == 5)
	{
		my_game->collect = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/c5.xpm", &my_game->img_w, &my_game->img_h);
	}
	else if (my_game->frame == 6)
	{
		my_game->collect = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/c6.xpm", &my_game->img_w, &my_game->img_h);
		my_game->frame = 0;
	}
}

int	some_animation(t_game *my_game)
{
	if (my_game->loop < 1000)
	{
		my_game->loop++;
		return (0);
	}
	my_game->loop = 0;
	frames_animation(my_game);
	frames_animation2(my_game);
	if (!my_game->collect)
		ft_putstr_error_exit("invalid image\n");
	map_game(my_game);
	my_game->frame++;
	return (0);
}

void	play_game(t_game *my_game)
{
	mlx_hook(my_game->win, 2, 1L << 12, key_val, my_game);
	mlx_loop_hook(my_game->mlx, some_animation, my_game);
}
