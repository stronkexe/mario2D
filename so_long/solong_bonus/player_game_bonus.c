/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:33:43 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/24 19:41:49 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player_up(t_game *my_game)
{
	if (my_game->map[my_game->y_player][my_game->x_player] == '0')
		mv_player_w(my_game);
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'C')
	{
		my_game->nb_collect--;
		if (my_game->nb_collect == 0)
		{
			mlx_destroy_image(my_game->mlx, my_game->exit);
			my_game->exit = mlx_xpm_file_to_image(my_game->mlx,
					"imgs/exit2.xpm", &my_game->img_w, &my_game->img_h);
		}
		mlx_destroy_image(my_game->mlx, my_game->player);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/m1.xpm", &my_game->img_w, &my_game->img_h);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player + 1][my_game->x_player] = '0';
		my_game->gg = 1;
	}
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'E'
		&& my_game->nb_collect == 0)
		destroy_window(my_game);
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'N')
		exit(0);
	map_game(my_game);
}

void	move_player_down(t_game *my_game)
{
	if (my_game->map[my_game->y_player][my_game->x_player] == '0')
		mv_player_s(my_game);
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'C')
	{
		my_game->nb_collect--;
		if (my_game->nb_collect == 0)
		{
			mlx_destroy_image(my_game->mlx, my_game->exit);
			my_game->exit = mlx_xpm_file_to_image(my_game->mlx,
					"imgs/exit2.xpm", &my_game->img_w, &my_game->img_h);
		}
		mlx_destroy_image(my_game->mlx, my_game->player);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/m2.xpm", &my_game->img_w, &my_game->img_h);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player - 1][my_game->x_player] = '0';
		my_game->gg = 1;
	}
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'E'
			&& my_game->nb_collect == 0)
		destroy_window(my_game);
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'N')
		exit(0);
	map_game(my_game);
}

void	move_player_right(t_game *my_game)
{
	if (my_game->map[my_game->y_player][my_game->x_player] == '0')
		mv_player_d(my_game);
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'C')
	{
		my_game->nb_collect--;
		if (my_game->nb_collect == 0)
		{
			mlx_destroy_image(my_game->mlx, my_game->exit);
			my_game->exit = mlx_xpm_file_to_image(my_game->mlx,
					"imgs/exit2.xpm", &my_game->img_w, &my_game->img_h);
		}
		mlx_destroy_image(my_game->mlx, my_game->player);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/m1.xpm", &my_game->img_w, &my_game->img_h);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player][my_game->x_player - 1] = '0';
		my_game->gg = 1;
	}
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'E'
			&& my_game->nb_collect == 0)
		destroy_window(my_game);
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'N')
		exit(0);
	map_game(my_game);
}

void	move_player_left(t_game *my_game)
{
	if (my_game->map[my_game->y_player][my_game->x_player] == '0')
		mv_player_a(my_game);
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'C')
	{
		my_game->nb_collect--;
		if (my_game->nb_collect == 0)
		{
			mlx_destroy_image(my_game->mlx, my_game->exit);
			my_game->exit = mlx_xpm_file_to_image(my_game->mlx,
					"imgs/exit2.xpm", &my_game->img_w, &my_game->img_h);
		}
		mlx_destroy_image(my_game->mlx, my_game->player);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx,
				"imgs/m2.xpm", &my_game->img_w, &my_game->img_h);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player][my_game->x_player + 1] = '0';
		my_game->gg = 1;
	}
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'E'
			&& my_game->nb_collect == 0)
		destroy_window(my_game);
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'N')
		exit(0);
	map_game(my_game);
}

void	player_game(int key, t_game *my_game)
{
	if (key == 13)
	{
		my_game->y_player -= 1;
		my_game->moves++;
		move_player_up(my_game);
	}
	else if (key == 1)
	{
		my_game->y_player += 1;
		my_game->moves++;
		move_player_down(my_game);
	}
	else if (key == 2)
	{
		my_game->x_player += 1;
		my_game->moves++;
		move_player_right(my_game);
	}
	else if (key == 0)
	{
		my_game->x_player -= 1;
		my_game->moves++;
		move_player_left(my_game);
	}
}
