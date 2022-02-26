/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:47:46 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/26 13:49:59 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	check_player(t_game *my_game)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (my_game->map[i])
	{
		j = 0;
		while (my_game->map[i][j])
		{
			if (my_game->map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	return (p);
}

int	check_exit(t_game *my_game)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (my_game->map[i])
	{
		j = 0;
		while (my_game->map[i][j])
		{
			if (my_game->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	return (e);
}

void	check_collect(t_game *my_game)
{
	int	i;
	int	j;

	i = 0;
	while (my_game->map[i])
	{
		j = 0;
		while (my_game->map[i][j])
		{
			if (my_game->map[i][j] == 'C')
			{
				my_game->nb_collect++;
				my_game->gg = 1;
			}
			j++;
		}
		i++;
	}
}

int	check_map(t_game *my_game)
{
	int	p;
	int	e;

	my_game->nb_collect = 0;
	p = check_player(my_game);
	e = check_exit(my_game);
	check_collect(my_game);
	if (p != 1 || !my_game->gg || e < 1)
		return (0);
	if (!check_ifclosed(my_game))
		return (0);
	return (1);
}
