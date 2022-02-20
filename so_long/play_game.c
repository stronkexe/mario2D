/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:13:41 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/20 20:06:27 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_val(int key, t_game *my_game)
{
	if (key == 53)
	{
		mlx_destroy_window(my_game->mlx, my_game->win);
		exit(0);
	}
	else if (key == 13 || key == 1 || key == 2 || key == 0) // up --> 13
		player_game(key, my_game);
/*	else if (key == 1) // down --> 1
		play_game(my_game);
	else if (key == 2) // right --> 2
		play_game(my_game);
	else if (key == 0) // left --> 0
		play_game(my_game);*/
	else
		return (0);
	return (1);
}

int	print(int key)
{
	printf("key %d\n", key);
	return (0);
}

void	play_game(t_game *my_game)
{
	mlx_hook(my_game->win, 2, 1L<<12, key_val, my_game);
	mlx_hook(my_game->win, 9, 1L<<21, map_game, my_game);
	mlx_loop(my_game->mlx);
}