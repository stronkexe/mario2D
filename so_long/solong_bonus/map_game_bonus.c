/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:33:25 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/25 18:36:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putmap(t_game *my_game, void *img, int j, int i)
{
	mlx_put_image_to_window(my_game->mlx, my_game->win, img, j * 32, i * 32);
}

void	ft_putmap_player(t_game *my_game, void *img, int j, int i)
{
	my_game->x_player = j;
	my_game->y_player = i;
	ft_putmap(my_game, img, j, i);
}

void	print_moves(t_game *my_game)
{
	char	*n;

	mlx_string_put(my_game->mlx, my_game->win, 32, 35, 0x000, "Moves: \n");
	n = ft_itoa(my_game->moves);
	mlx_string_put(my_game->mlx, my_game->win, 100, 35, 0x000, n);
}

void	get_character(t_game *my_game)
{
	int	i;
	int	j;

	i = 0;
	while (my_game->map[i] != NULL)
	{
		j = 0;
		while (my_game->map[i][j] != '\0')
		{
			if (my_game->map[i][j] == '0')
				ft_putmap(my_game->mlx, my_game->background, j, i);
			else if (my_game->map[i][j] == '1')
				ft_putmap(my_game, my_game->wall, j, i);
			else if (my_game->map[i][j] == 'P')
				ft_putmap_player(my_game, my_game->player, j, i);
			else if (my_game->map[i][j] == 'C')
				ft_putmap(my_game, my_game->collect, j, i);
			else if (my_game->map[i][j] == 'N')
				ft_putmap(my_game, my_game->enemy, j, i);
			else if (my_game->map[i][j] == 'E')
				ft_putmap(my_game, my_game->exit, j, i);
			else
				ft_putstr_error_exit("invalid character\n");
			j++;
		}
		i++;
	}
}

int	map_game(t_game *my_game)
{
	if (!check_map(my_game))
		ft_putstr_error_exit("invalid map\n");
	get_character(my_game);
	print_moves(my_game);
	return (1);
}
