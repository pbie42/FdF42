/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:51:12 by pbie              #+#    #+#             */
/*   Updated: 2016/02/12 18:13:04 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_grid(t_mlx mlx)
{
	int			x;
	int			y;

	if (mlx.tablen > mlx.strlen)
	{
		mlx.y = SIZE_Y / mlx.tablen;
		mlx.x = SIZE_X / mlx.tablen;
	}
	else
	{
		mlx.y = SIZE_Y / mlx.strlen;
		mlx.x = SIZE_X / mlx.strlen;
	}
	x = (SIZE_X - (mlx.strlen * mlx.x)) / 2;
	while (x < (SIZE_X - mlx.x))
	{
		y = (SIZE_Y - (mlx.tablen * mlx.y)) / 2;
		while (y < (SIZE_Y - mlx.y))
		{
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, mlx.c);
			y++;
		}
		x += mlx.x;
	}
	y = (SIZE_Y - (mlx.tablen * mlx.y)) / 2;
	while (y < (SIZE_Y - mlx.y))
	{
		x = (SIZE_X - (mlx.strlen * mlx.x)) / 2;
		while (x < (SIZE_X - mlx.x))
		{
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, mlx.c);
			x++;
		}
		y += mlx.y;
	}
}
