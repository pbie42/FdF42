/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:21:31 by pbie              #+#    #+#             */
/*   Updated: 2016/02/11 17:30:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_strlennum(char const *s)
{
	int			i;
	int			c;

	i = 0;
	c = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i + 1] < '0' || s[i + 1] > '9' || s[i + 1] == '\0')
				c++;
		}
		i++;
	}
	return (c);
}

int				**ft_numboard(int c)
{
	int			**nb;

	nb = (int **)malloc(sizeof(int *) * c);
	return (nb);
}

int				*ft_chartonumline(char *s, int c)
{
	int			*nl;
	int			i;
	int			j;

	i = 0;
	j = 0;
	nl = (int *)malloc(sizeof(int) * c);
	while (s[i] != '\0')
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+')
		{
			nl[j] = ft_atoi(&s[i]);
			j++;
		}
		if ((s[i + 1] >= '0' && s[i + 1] <= '9') 
				&& (s[i] >= '0' && s[i] <= '9'))
			i++;
		i++;
	}
	return (nl);
}

char			**ft_parse1(int argc, char **argv)
{
	char		**tab;
	char		*line;
	int			fd;
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		while (ft_get_next_line(fd, &line) == 1)
			j++;
		i++;
	}
	tab = ft_buildtab(j);
	i = 1;
	j = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		while (ft_get_next_line(fd, &line) == 1)
			j++;
		i++;
	}
	return (tab);
}

int				**ft_parse2(char **tab)
{
	int			**nb;
	int			i;

	i = 0;
	nb = ft_numboard(ft_tablen(tab));
	while (tab[i] != NULL)
	{
		nb[i] = ft_chartonumline(tab[i], ft_strlennum(tab[i]));
		i++;
	}
	return (nb);
}
