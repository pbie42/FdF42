/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:22:32 by pbie              #+#    #+#             */
/*   Updated: 2016/02/24 18:25:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_mapsize(t_mlx *mlx)
{
	mlx->mpsz = sqrt((mlx->strlen * mlx->strlen) + (mlx->tablen * mlx->tablen));
	if (SIZE_X > SIZE_Y)
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->x = ((SIZE_X - SIZE_Y) / 2);
		mlx->y = (SIZE_Y) / 2;
		mlx->mpsz = sqrt((mlx->xlen * mlx->xlen) + (mlx->ylen * mlx->ylen));
	}
	else if (SIZE_Y > SIZE_X)
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_X - (SIZE_X * .25))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_X - (SIZE_X * .25))) / mlx->mpsz;
		mlx->x = (SIZE_X) / 2;
		mlx->y = ((SIZE_Y - SIZE_X) / 2) + ((SIZE_X * .25) / 2);
		mlx->mpsz = sqrt((mlx->xlen * mlx->xlen) + (mlx->ylen * mlx->ylen));
	}
	else
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->x = (SIZE_X * .25) / 2;
		mlx->y = (SIZE_Y) / 2;
		mlx->mpsz = sqrt((mlx->xlen * mlx->xlen) + (mlx->ylen * mlx->ylen));
	}
	mlx->size = mlx->xlen / mlx->strlen;
	mlx->desize = mlx->ylen / mlx->tablen;
}

/*Tomorrow you need to fix the below function. Right now it is making the top
 * row first and then moving down. You need it to make the column closest to 
 * the starting points first. Fix this.*/

void			ft_gridnew(t_mlx mlx, int **nb)
{
	int			i;
	int			j;
	int			**nb2;

	nb2 = nb;

	i = mlx.tablen;
	mlx.x = mlx.x + (mlx.strlen * mlx.size);
	//mlx.y = mlx.y + (mlx.tablen * (mlx.size / 2));
	ft_putendl("mlx.x and mlx.y");
	ft_putnbr(mlx.x);
	ft_putchar(' ');
	ft_putnbr(mlx.y);
	ft_putchar(' ');
	while (i >= 0)
	{
		j = mlx.strlen;
		mlx.x1x = mlx.x;
		mlx.y1y = mlx.y;
		while (j >= 0)
		{
			mlx.x2 = mlx.x1x - mlx.size;
			mlx.y2 = mlx.y1y + (mlx.size / 2);
			if (i - 1 != -1)
				ft_line(mlx.x1x, mlx.y1y, mlx.x2, mlx.y2, mlx);
			mlx.y2 -= mlx.size;
			if (j - 1 != -1)
				ft_line(mlx.x1x, mlx.y1y, mlx.x2, mlx.y2, mlx);
			mlx.x1x = mlx.x2;
			mlx.y1y = mlx.y2;
			j--;
		}
		mlx.x -= mlx.size;
		mlx.y += (mlx.size / 2);
		i--;
	}
}
