/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:21:31 by pbie              #+#    #+#             */
/*   Updated: 2016/02/11 16:08:05 by pbie             ###   ########.fr       */
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

int				**ft_parse(char **tab)
{
	int			**nb;
	int			i;

	i = 0;
	nb = ft_numboard(ft_tablen(tab));
	while (tab[i] != NULL)
	{
		nb[i] = (int *)malloc(sizeof(int) * ft_strlennum(tab[i]));
		i++;
	}
	i = 0;

	return (nb);
}
