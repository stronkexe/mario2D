/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:33:39 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/19 17:58:35 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int key, t_game *my_game)
{
	if (key ==119)
	{
		my_game->y_player += 1;
		my_game->player = mlx_xpm_file_to_image(my_game->mlx, "imgs/mario.xpm", &my_game->img_w, &my_game->img_h);
	}
}

void	player_game(t_game my_game)
{
	
}