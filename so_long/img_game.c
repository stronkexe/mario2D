/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:42:12 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/19 14:49:30 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_img(t_game *my_game)
{
	my_game->background = mlx_xpm_file_to_image(my_game->mlx, "imgs/background.xpm", &my_game->img_w, &my_game->img_h);
	my_game->wall = mlx_xpm_file_to_image(my_game->mlx, "imgs/wall.xpm", &my_game->img_w, &my_game->img_h);
	my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/mario.xpm", &my_game->img_w, &my_game->img_h);
	my_game->collect = mlx_xpm_file_to_image(my_game->mlx, "imgs/mashrom.xpm", &my_game->img_w, &my_game->img_h);
	my_game->exit = mlx_xpm_file_to_image(my_game->mlx, "imgs/exit1.xpm", &my_game->img_w, &my_game->img_h);
}