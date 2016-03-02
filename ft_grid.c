/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:18:09 by pbie              #+#    #+#             */
/*   Updated: 2016/03/02 17:47:35 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_gridnew(t_mlx mlx, int **nb)
{
	int			i;
	int			j;

	ft_mapsize(&mlx);
	mlx_clear_window(mlx.mlx, mlx.win);
	mlx.size = mlx.xlen / mlx.strlen;
	i = 0;
	while (i < mlx.tablen)
	{
		ft_xyreset(&mlx);
		j = mlx.strlen - 1;
		while (j >= 0)
		{
			ft_x2y2g1(&mlx);
			if (j - 1 != -1)
				ft_g1core(&mlx, nb, i, j);
			mlx.x1x = mlx.x2;
			mlx.y1y = mlx.y2;
			j--;
		}
		mlx.x -= mlx.size;
		mlx.y += (mlx.size / 2);
		i++;
	}
	ft_gridnew2(mlx, nb);
}

void			ft_gridnew2(t_mlx mlx, int **nb)
{
	int			i;
	int			j;

	ft_mapsize(&mlx);
	mlx.size = mlx.xlen / mlx.strlen;
	j = mlx.strlen - 1;
	while (j >= 0)
	{
		ft_xyreset(&mlx);
		i = 0;
		while (i < mlx.tablen)
		{
			ft_x2y2g2(&mlx);
			if (i + 1 != mlx.tablen)
				ft_g2core(&mlx, nb, i, j);
			mlx.x1x = mlx.x2;
			mlx.y1y = mlx.y2;
			i++;
		}
		mlx.x -= mlx.size;
		mlx.y -= (mlx.size / 2);
		j--;
	}
	ft_putnbr(mlx.z);
	ft_putchar('\n');
}
