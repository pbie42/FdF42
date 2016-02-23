/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseaux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:22:51 by pbie              #+#    #+#             */
/*   Updated: 2016/02/23 15:25:01 by pbie             ###   ########.fr       */
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
			ft_putnbr(nl[j]);
			ft_putchar('\n');
			j++;
		}
		if ((s[i + 1] >= '0' && s[i + 1] <= '9')
				&& (s[i] >= '0' && s[i] <= '9'))
			i++;
		i++;
	}
	return (nl);
}
