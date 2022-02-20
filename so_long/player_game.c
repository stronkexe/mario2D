/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:33:39 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/20 20:54:56 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_game *my_game)
{
	if (my_game->map[my_game->y_player][my_game->x_player] == '0')
	{
		mlx_destroy_image(my_game->mlx, my_game->player);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/mario.xpm", &my_game->img_w, &my_game->img_h);
	//	mlx_clear_window(my_game->mlx, my_game->win);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player+1][my_game->x_player] = '0';
		
	}
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'C')
	{
		mlx_destroy_image(my_game->mlx, my_game->player);
		mlx_destroy_image(my_game->mlx, my_game->collect);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/mario.xpm", &my_game->img_w, &my_game->img_h);
	//	mlx_clear_window(my_game->mlx, my_game->win);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player+1][my_game->x_player] = '0';
		my_game->gg = 1;
		
	}
	map_game(my_game);
	printf("hi i'm w\n");
}

void	move_player_down(t_game *my_game)
{
	if (my_game->map[my_game->y_player][my_game->x_player] == '0')
	{
		mlx_destroy_image(my_game->mlx, my_game->player);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/realmario2.xpm", &my_game->img_w, &my_game->img_h);
	//	mlx_clear_window(my_game->mlx, my_game->win);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player-1][my_game->x_player] = '0';
	}
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'C')
	{
		mlx_destroy_image(my_game->mlx, my_game->player);
		mlx_destroy_image(my_game->mlx, my_game->collect);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/realmario2.xpm", &my_game->img_w, &my_game->img_h);
	//	mlx_clear_window(my_game->mlx, my_game->win);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player-1][my_game->x_player] = '0';
		my_game->gg = 1;
	}
	
	map_game(my_game);
	printf("hi i'm s\n");
}

void	move_player_right(t_game *my_game)
{
	if (my_game->map[my_game->y_player][my_game->x_player] == '0')
	{
		mlx_destroy_image(my_game->mlx, my_game->player);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/mario.xpm", &my_game->img_w, &my_game->img_h);
	//	mlx_clear_window(my_game->mlx, my_game->win);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player][my_game->x_player-1] = '0';
	}
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'C')
	{
		mlx_destroy_image(my_game->mlx, my_game->player);
		mlx_destroy_image(my_game->mlx, my_game->collect);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/mario.xpm", &my_game->img_w, &my_game->img_h);
	//	mlx_clear_window(my_game->mlx, my_game->win);
		printf("im collect\n");
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player][my_game->x_player-1] = '0';
		my_game->gg = 1;
	}
	map_game(my_game);
	printf("hi i'm d\n");
}

void	move_player_left(t_game *my_game)
{
	if (my_game->map[my_game->y_player][my_game->x_player] == '0')
	{
		mlx_destroy_image(my_game->mlx, my_game->player);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/realmario2.xpm", &my_game->img_w, &my_game->img_h);
	//	mlx_clear_window(my_game->mlx, my_game->win);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player][my_game->x_player+1] = '0';
	}
	else if (my_game->map[my_game->y_player][my_game->x_player] == 'C')
	{
		mlx_destroy_image(my_game->mlx, my_game->player);
		mlx_destroy_image(my_game->mlx, my_game->collect);
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/realmario2.xpm", &my_game->img_w, &my_game->img_h);
	//	mlx_clear_window(my_game->mlx, my_game->win);
		my_game->map[my_game->y_player][my_game->x_player] = 'P';
		my_game->map[my_game->y_player][my_game->x_player+1] = '0';
		my_game->gg = 1;
	}
	
	map_game(my_game);
	printf("hi i'm a\n");
}

void	player_game(int key, t_game *my_game)
{
	if (key == 13)
	{
		my_game->y_player -=1;
		move_player_up(my_game);
	}
	else if (key == 1)
	{
		my_game->y_player +=1;
		move_player_down(my_game);
	}
	else if (key == 2)
	{
		my_game->x_player +=1;
		move_player_right(my_game);
	}
	else if (key == 0)
	{
		my_game->x_player -=1;
		move_player_left(my_game);
	}
}