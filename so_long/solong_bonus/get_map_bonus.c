/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:33:12 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/26 12:32:52 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*getmaplines(char *s, int fd)
{
	char	*t;
	char	*temp;

	temp = ft_strdup("");
	if (!temp)
		exit(1);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		t = temp;
		temp = ft_strjoin(t, s);
		if (!temp)
			exit(1);
		free(s);
		free(t);
	}
	if (temp[0] == 0)
		ft_putstr_error_exit("invalid map\n");
	return (temp);
}

void	get_game(char *av, t_game *my_game)
{
	int		fd;
	char	*s;
	char	*temp;

	s = NULL;
	if (!check_rev_file(av))
		ft_putstr_error_exit("invalid file\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(1);
	temp = getmaplines(s, fd);
	if (!temp)
		exit(1);
	if (temp[ft_strlen(temp) - 1] == '\n')
		ft_putstr_error_exit("invalid map\n");
	my_game->map = ft_split(temp, '\n');
	if (!my_game->map)
		exit(1);
	free(temp);
	close(fd);
}
