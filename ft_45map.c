/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_45map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:38:45 by pbie              #+#    #+#             */
/*   Updated: 2016/02/16 18:01:30 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_steep(int x0, int y0, int x1, int y1)
{
	int		y;
	int		x;

	y = y1 - y0;
	if (y < 0)
		y *= -1;
	x = x1 - x0;
	if (x < 0)
		x *= -1;
	if (y > x)
		return (0);
	else
		return (1);
}

void			ft_linedraw(int x0, int y0, int x1, int y1, t_mlx mlx)
{
	int			dx;
	float		error;
	int			derr;
	int			y;
	int			x;
	int			ystep;

	if (ft_steep(x0, x1, y0, y1))
	{
		ft_swap(&x0, &y0);
		ft_swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	derr = y1 - y0 < 0 ? ((y1 - y0) * -1) : y1 - y0;
	ystep = y0 > y1 ? -1 : 1;
	dx = x1 - x0;
	error = 0.0;
	y = y0;
	x = x0;
	while (x <= x1)
	{
		if (ft_steep(x0, y0, x1, y1))
			mlx_pixel_put(mlx.mlx, mlx.win, y, x, mlx.c);
		else
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, mlx.c);
		error += derr;
		if (error >= 0.5)
		{
			y += ystep;
			error -= dx;
		}
		x++;
	}
}
