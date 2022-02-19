/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:13:41 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/19 17:53:31 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_val(int key, t_game *my_game)
{
	if (key == 27)
	{
		printf("hi\n");
		mlx_destroy_window(my_game->mlx, my_game->win);
		exit(0);
	}
	else if (key == 119)
		move_player(key , my_game);
	else if (keycode == 115)
		move_player(key, my_game);
	else if (key == 100)
		move_player(key, my_game);
	else if (key == 97)
		move_player(key, my_game);
	else
		return (0);
}

void	play_game(t_game *my_game)
{
	mlx_hook(my_game->win, 2, 1L << 0, key_val, my_game);
//	mlx_key_hook(my_game.mlx, 97, my_game);
}