/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:26:47 by pbie              #+#    #+#             */
/*   Updated: 2016/02/11 17:27:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_putnbrline(int *nl, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		ft_putchar(' ');
		ft_putnbr(nl[i]);
		ft_putchar(' ');
		i++;
	}
}

void			ft_putnbrtab(int **nb, char **tab)
{
	int			i;

	i = 0;
	while (i < ft_tablen(tab))
	{
		ft_putnbrline(nb[i], ft_strlennum(tab[i]));
		ft_putchar('\n');
		i++;
	}
}
