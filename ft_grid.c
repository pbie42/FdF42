/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:18:09 by pbie              #+#    #+#             */
/*   Updated: 2016/03/08 17:39:41 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_xyset(t_mlx *mlx)
{
	mlx->x1 = mlx->x;
	mlx->y1 = mlx->y;
}

void			ft_gridnew(t_mlx mlx)
{
	int			i;
	int			j;

	mlx_clear_window(mlx.mlx, mlx.win);
	ft_xyset(&mlx);
	mlx.size = (mlx.xlen / mlx.strlen) + mlx.zoom;
	i = 0;
	while (i < mlx.tablen)
	{
		ft_xyreset(&mlx);
		j = mlx.strlen - 1;
		while (j >= 0)
		{
			ft_x2y2g1(&mlx);
			if (j - 1 != -1)
				ft_g1core(&mlx, i, j);
			mlx.x1x = mlx.x2;
			mlx.y1y = mlx.y2;
			j--;
		}
		mlx.x1 -= mlx.size;
		mlx.y1 += (mlx.size / 2);
		i++;
	}
	ft_gridnew2(mlx);
}

void			ft_gridnew2(t_mlx mlx)
{
	int			i;
	int			j;

	j = mlx.strlen - 1;
	ft_xyset(&mlx);
	while (j >= 0)
	{
		ft_xyreset(&mlx);
		i = 0;
		while (i < mlx.tablen)
		{
			ft_x2y2g2(&mlx);
			if (i + 1 != mlx.tablen)
				ft_g2core(&mlx, i, j);
			mlx.x1x = mlx.x2;
			mlx.y1y = mlx.y2;
			i++;
		}
		mlx.x1 -= mlx.size;
		mlx.y1 -= (mlx.size / 2);
		j--;
	}
}
