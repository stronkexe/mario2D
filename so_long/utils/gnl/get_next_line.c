/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:11:47 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/22 14:31:24 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_chyata(char *line)
{
	char	*chyata;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	chyata = ft_substr2(line, i + 1, ft_strle(line));
	free(line);
	line = NULL;
	return (chyata);
}

char	*get_line(char	**line)
{
	int		i;
	char	*temp;

	i = 0;
	if (line[0][i] == '\0')
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	temp = ft_substr2(*line, 0, i+1);
	return (temp);
}

char	*read_line(int fd, char *line)
{
	char		*buffer;
	ssize_t		n;

	n = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (!line)
		line = ft_strdup2("");
	while (ft_strchr(line) == 0 && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buffer);
			free(line);
			line = NULL;
			return (NULL);
		}
		buffer[n] = '\0';
	//	printf("buffer %s$\n", buffer);
	//	if (buffer[0] == '\n')
	//		exit(1);
		line = ft_strjoin2(line, buffer);
	}
	free(buffer);
	
	return (line);
}

void	check_bn(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && s[i+1] == '\0')
			printf("yoyo\n");
		//	exit(1);
		i++;
	}
}
char	*get_next_line(int fd)
{
	static char		*line;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, line);
	if (line == NULL)
		return (NULL);
	buffer = get_line(&line);
//	printf("buffer [0] %c$\n", buffer[0]);
//	check_bn(buffer);
	
	if (buffer == NULL)
		return (NULL);
	line = get_chyata(line);
	
	printf("buffer %s$\n", buffer);
	if (buffer[0] == '\n')
	{
	 	write(2, "no buddy\n", 9);
	 	exit(1);
	}
	return (buffer);
}