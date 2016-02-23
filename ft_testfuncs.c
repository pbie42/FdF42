/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:26:47 by pbie              #+#    #+#             */
/*   Updated: 2016/02/23 17:39:35 by pbie             ###   ########.fr       */
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

void			ft_putnbrtab(int **nb, t_mlx *mlx)
{
	int			i;

	i = 0;
	while (i < mlx->tablen)
	{
		ft_putnbrline(nb[i], mlx->strlen);
		ft_putchar('\n');
		i++;
	}
}
