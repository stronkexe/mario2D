/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:13:41 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/26 14:11:38 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_val(int key, t_game *my_game)
{
	if (key == 53)
	{
		mlx_destroy_window(my_game->mlx, my_game->win);
		free_map(my_game);
		free(my_game->mlx);
		exit(1);
	}
	else if (key == 13 || key == 1
		|| key == 2 || key == 0)
		player_game(key, my_game);
	else
		return (0);
	return (1);
}

int	leave_game(void)
{
	exit(1);
}

void	play_game(t_game *my_game)
{
	mlx_hook(my_game->win, 2, 1L << 0, key_val, my_game);
	mlx_hook(my_game->win, 17, 1L << 0, leave_game, my_game);
}
