/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:33:07 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/26 12:28:17 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_rev_file(char *s)
{
	int	i;

	i = 0;
	while (i < (ft_strlen(s) - 4))
		i++;
	if (!ft_strncmp(&s[i], ".ber", 4))
		return (1);
	return (0);
}

int	check_top_map(t_game *my_game)
{
	int	i;

	i = 0;
	while (my_game->map[0][i])
	{
		if (my_game->map[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_bottom_map(t_game *my_game)
{
	int	i;
	int	h;

	h = (my_game->map_h / 32) - 1;
	i = 0;
	while (my_game->map[h][i] != '\0')
	{
		if (my_game->map[h][i] != '1')
			return (0);
		i++;
	}
	if (my_game->map[h][i] == '\n')
		return (0);
	return (1);
}

int	check_ifclosed(t_game *my_game)
{
	int	i;
	int	w;

	if (!check_top_map(my_game))
		return (0);
	i = 0;
	w = (my_game->map_w / 32) - 1;
	while (my_game->map[i])
	{
		if (my_game->map[i][0] != '1' || my_game->map[i][w] != '1'
			|| ft_strlen(my_game->map[i]) != (w + 1))
			return (0);
		i++;
	}
	if (!check_bottom_map(my_game))
		return (0);
	return (1);
}
