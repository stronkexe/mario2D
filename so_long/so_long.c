/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:44:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/25 20:11:26 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_game(t_game *my_game)
{
	int	i;

	i = 0;
	my_game->map_w = ft_strlen(my_game->map[0]) * 32;
	while (my_game->map[i] != NULL)
		i++;
	my_game->map_h = i * 32;
}

int	main(int ac, char **av)
{
	t_game	my_game;

	if (ac == 2)
	{
		my_game.moves = 0;
		my_game.mlx = mlx_init();
		get_game(av[1], &my_game);
		window_game(&my_game);
		my_game.win = mlx_new_window(my_game.mlx,
				my_game.map_w, my_game.map_h, "solong");
		game_img(&my_game);
		map_game(&my_game);
		play_game(&my_game);
		mlx_loop(my_game.mlx);
	}
	else
		ft_putstr_error_exit("Invalid number of aeguments\n");
}
