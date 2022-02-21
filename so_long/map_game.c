/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:05:31 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/21 13:12:17 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_game(char *av, t_game *my_game)
{
	int		fd;
	char	*s;
	char	*temp;
	char	*t;
	
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(1);
	printf("hhhh\n");
	temp = ft_strdup("");
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break;
		t = temp;
		temp = ft_strjoin(t, s);
		if (!temp)
			exit(1);
		free(s);
		free(t);
	}
	my_game->map = ft_split(temp, '/');
	if (!my_game->map)
		exit(1);
	free(temp);
	close(fd);
}

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

int	check_ifclosed(t_game *my_game)
{
	int	i;

	i = 0;
	while (my_game->map[0][i])
	{
		if (my_game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	int	h = (my_game->map_h / 32) - 1;
	while (my_game->map[h][i])
	{
		if (my_game->map[h][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	check_map(t_game *my_game)
{
	my_game->nb_collect = 0;
	int	i;
	int	j;
	int	p;
//	int	c;
	int	e;

	i = 0;
	p = 0;
//	c = 0;
	e = 0;
	while (my_game->map[i])
	{
		j = 0;
		while (my_game->map[i][j])
		{
			if (my_game->map[i][j] == 'P')
			{
				p = 1;
				break;
			}
			j++;
		}
		i++;
	}
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
			//	break;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (my_game->map[i])
	{
		j = 0;
		while (my_game->map[i][j])
		{
			if (my_game->map[i][j] == 'E')
			{
				e++;
			//	break;
			}
			j++;
		}
		i++;
	}
	printf("nb collect %d\n", my_game->nb_collect);
	if (!p || !my_game->gg || !e || e > 1)
		return (0);
	if (my_game->map_h == my_game->map_w)
		return (0);
	if (!check_ifclosed(my_game))
		return (0);
	return (1);
}

int	map_game(t_game *my_game)
{
	int	i;
	int	j;
	
	i = 0;
	if (!check_map(my_game))
	{
		write(2, "invalid map\n", 12);
		exit(1);
	}
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
			else if (my_game->map[i][j] == 'E')
				ft_putmap(my_game, my_game->exit, j, i);
			else
			{
				write(2, "invalid character\n", 18);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}