/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gridaux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:21:13 by pbie              #+#    #+#             */
/*   Updated: 2016/03/02 17:25:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_xyreset(t_mlx *mlx)
{
	mlx->x1x = mlx->x;
	mlx->y1y = mlx->y;
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

void			ft_g1core(t_mlx *mlx, int **nb, int i, int j)
{
	mlx->y2 = nb[i][j - 1] != 0 ? mlx->y2 - (nb[i][j - 1] * mlx->z) : mlx->y2;
	mlx->y1y = nb[i][j] != 0 ? mlx->y1y - (nb[i][j] * mlx->z) : mlx->y1y;
	mlx->c = (nb[i][j] != 0 || nb[i][j - 1] != 0 ? 0x006600FF : 0x00FFFFFF);
	ft_line(mlx->x1x, mlx->y1y, mlx->x2, mlx->y2, *mlx);
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->x2, mlx->y2, mlx->c);
	mlx->y2 = nb[i][j - 1] != 0 ? mlx->y2 + (nb[i][j - 1] * mlx->z) : mlx->y2;
	mlx->y1y = nb[i][j] != 0 ? mlx->y1y + (nb[i][j] * mlx->z) : mlx->y1y;
}

void			ft_g2core(t_mlx *mlx, int **nb, int i, int j)
{
	mlx->y2 = nb[i + 1][j] != 0 ? mlx->y2 - (nb[i + 1][j] * mlx->z) : mlx->y2;
	mlx->y1y = nb[i][j] != 0 ? mlx->y1y - (nb[i][j] * mlx->z) : mlx->y1y;
	mlx->c = (nb[i][j] != 0 || nb[i + 1][j] != 0 ? 0x006600FF : 0x00FFFFFF);
	ft_line(mlx->x1x, mlx->y1y, mlx->x2, mlx->y2, *mlx);
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->x1x, mlx->y1y, mlx->c);
	mlx->y2 = nb[i + 1][j] != 0 ? mlx->y2 + (nb[i + 1][j] * mlx->z) : mlx->y2;
	mlx->y1y = nb[i][j] != 0 ? mlx->y1y + (nb[i][j] * mlx->z) : mlx->y1y;
}
