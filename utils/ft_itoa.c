/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:50:01 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/25 12:57:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_rev(char	*s)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] && len > i)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
		i++;
		len--;
	}
}

static char	*ft_convert(char *s, int n, int count)
{
	int		i;
	int		nb;

	i = 0;
	nb = n;
	if (nb < 0)
		nb *= -1;
	while (i < count && nb > 0)
	{
		s[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	s[i] = '\0';
	ft_rev(s);
	return (s);
}

static char	*fill_tab(char *s)
{
	char	*nb;
	int		i;

	i = 0;
	nb = "-2147483648";
	while (i < 12)
	{
		s[i] = nb[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*allocate(long n)
{
	char	*s;
	int		i;

	s = NULL;
	i = 0;
	if (n == 0)
	{
		s = malloc(sizeof(char) * 2);
		s[0] = '0';
		s[1] = '\0';
	}
	else if (n == -2147483648)
	{
		s = malloc(sizeof(char) * 12);
		if (s == NULL)
			return (0);
		s = fill_tab(s);
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*s;
	int		nb;

	count = 0;
	nb = n;
	if (n == 0 || n == -2147483648)
	{
		return (allocate(n));
	}
	if (n < 0)
	{
		count = 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	s = malloc(sizeof(char) * (count + 1));
	if (s == NULL)
		return (0);
	return (ft_convert(s, n, count));
}
