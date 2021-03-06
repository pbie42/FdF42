/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gridaux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:21:13 by pbie              #+#    #+#             */
/*   Updated: 2016/03/08 18:02:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_xyreset(t_mlx *mlx)
{
	mlx->x1x = mlx->x1;
	mlx->y1y = mlx->y1;
}

void			ft_x2y2g1(t_mlx *mlx)
{
	mlx->x2 = mlx->x1x - mlx->size;
	mlx->y2 = mlx->y1y - (mlx->size / 2);
}

void			ft_x2y2g2(t_mlx *mlx)
{
	mlx->x2 = mlx->x1x - mlx->size;
	mlx->y2 = mlx->y1y + (mlx->size / 2);
}

void			ft_g1core(t_mlx *mlx, int i, int j)
{
	mlx->y2 = mlx->nb[i][j - 1] != 0 ? mlx->y2 - ((mlx->nb[i][j - 1] * mlx->z)
			+ mlx->zoom) : mlx->y2;
	mlx->y1y = mlx->nb[i][j] != 0 ? mlx->y1y - ((mlx->nb[i][j] * mlx->z)
			+ mlx->zoom) : mlx->y1y;
	mlx->col = (mlx->nb[i][j] != 0 || mlx->nb[i][j - 1] != 0 ?
			mlx->c2 : mlx->c);
	ft_line(*mlx);
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->x2, mlx->y2, mlx->col);
	mlx->y2 = mlx->nb[i][j - 1] != 0 ? mlx->y2 + ((mlx->nb[i][j - 1] * mlx->z)
			+ mlx->zoom) : mlx->y2;
	mlx->y1y = mlx->nb[i][j] != 0 ? mlx->y1y + ((mlx->nb[i][j] * mlx->z)
			+ mlx->zoom) : mlx->y1y;
}

void			ft_g2core(t_mlx *mlx, int i, int j)
{
	mlx->y2 = mlx->nb[i + 1][j] != 0 ? mlx->y2 - ((mlx->nb[i + 1][j] * mlx->z)
			+ mlx->zoom) : mlx->y2;
	mlx->y1y = mlx->nb[i][j] != 0 ? mlx->y1y - ((mlx->nb[i][j] * mlx->z)
			+ mlx->zoom) : mlx->y1y;
	mlx->col = (mlx->nb[i][j] != 0 || mlx->nb[i + 1][j] != 0 ?
			mlx->c2 : mlx->c);
	ft_line(*mlx);
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->x1x, mlx->y1y, mlx->col);
	mlx->y2 = mlx->nb[i + 1][j] != 0 ? mlx->y2 + ((mlx->nb[i + 1][j] * mlx->z)
			+ mlx->zoom) : mlx->y2;
	mlx->y1y = mlx->nb[i][j] != 0 ? mlx->y1y + ((mlx->nb[i][j] * mlx->z)
			+ mlx->zoom) : mlx->y1y;
}
