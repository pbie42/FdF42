/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:51:12 by pbie              #+#    #+#             */
/*   Updated: 2016/02/22 18:21:24 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_color(int k)
{
	if (k == 10)
		return (0x006600FF);
	else
		return (0x00FFFFFF);

}

void			ft_grid(t_mlx mlx, int **nb)
{
	int			x;
	int			y;
	int			x2;
	int			y2;
	int			j;
	int			i;

	if (mlx.tablen > mlx.strlen)
	{
		mlx.y = (SIZE_Y - 200) / mlx.tablen;
		mlx.x = (SIZE_X - 200) / mlx.tablen;
	}
	else
	{
		mlx.y = (SIZE_Y - 200) / mlx.strlen;
		mlx.x = (SIZE_X - 200) / mlx.strlen;
	}
	//mlx.y = (SIZE_Y - (SIZE_Y / 2)) / mlx.tablen;
	//mlx.x = (SIZE_X - 333) / mlx.strlen;
	i = 0;
	x = (SIZE_X - (mlx.strlen * mlx.x)) / 2;
	x2 = x;
	while (x <= (SIZE_X - x2))
	{
		y = (SIZE_Y - (mlx.tablen * mlx.y)) / 2;
		y2 = y;
		j = 0;
		while (y < (SIZE_Y - y2))
		{
			if ((y == y2 || ((y - y2) % mlx.y) == 0) && j < mlx.tablen)
			{
				ft_putendl("Color select if entered");
				if (nb[j][i] == 10 && j != mlx.tablen && nb[j + 1][i] == 10)
					mlx.c = 0x006600FF;
				else
					mlx.c = 0x00FFFFFF;
				j++;
				ft_putnbr(j);
				ft_putchar('\n');
				ft_putnbr(mlx.c);
				ft_putchar('\n');
			}
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, mlx.c);
			y++;
		}
		x += mlx.x;
		i++;
	}
	y = (SIZE_Y - (mlx.tablen * mlx.y)) / 2;
	j = 0;
	while (y <= (SIZE_Y - y2))
	{
		x = (SIZE_X - (mlx.strlen * mlx.x)) / 2;
		i = 0;
		while (x < (SIZE_X - x2))
		{
			if ((x == x2 || ((x - x2) % mlx.x) == 0) && i < mlx.strlen)
			{
				if (nb[j][i] == 10 && i != mlx.strlen && nb[j][i + 1] == 10)
					mlx.c = 0x006600FF;
				else
					mlx.c = 0x00FFFFFF;
				i++;
				ft_putnbr(i);
				ft_putchar('\n');
				ft_putnbr(mlx.c);
				ft_putchar('\n');
			}
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, mlx.c);
			x++;
		}
		y += mlx.y;
		j++;
		ft_putnbr(j);
		ft_putchar('\n');
	}
}

void			ft_displaysize(t_mlx *mlx)
{
	if (mlx->tablen > mlx->strlen)
	{
		mlx->y = (SIZE_Y) / mlx->tablen;
		mlx->x = (SIZE_X) / mlx->tablen;
	}
	else
	{
		mlx->y = (SIZE_Y) / mlx->strlen;
		mlx->x = (SIZE_X) / mlx->strlen;
	}
}

void			ft_rectsize(t_mlx *mlx)
{
	mlx->mpsz = sqrt((mlx->strlen * mlx->strlen) + (mlx->tablen * mlx->tablen));
	if (SIZE_X > SIZE_Y)
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->x = ((SIZE_X - SIZE_Y) / 2) + ((SIZE_Y * .25) / 2);
		mlx->y = (SIZE_Y) / 2;
		mlx->mpsz = sqrt((mlx->xlen * mlx->xlen) + (mlx->ylen * mlx->ylen));
		mlx->x2 = mlx->x + mlx->mpsz;
		mlx->y2 = mlx->y;
	}
	else if (SIZE_Y > SIZE_X)
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_X - (SIZE_X * .25))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_X - (SIZE_X * .25))) / mlx->mpsz;
		mlx->x = (SIZE_X) / 2;
		mlx->y = ((SIZE_Y - SIZE_X) / 2) + ((SIZE_X * .25) / 2);
		mlx->mpsz = sqrt((mlx->xlen * mlx->xlen) + (mlx->ylen * mlx->ylen));
		mlx->y2 = mlx->y + mlx->mpsz;
		mlx->x2 = mlx->x;
	}
	else
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->x = (SIZE_X) / 2;
		mlx->y = (SIZE_Y) / 2;
		mlx->mpsz = sqrt((mlx->xlen * mlx->xlen) + (mlx->ylen * mlx->ylen));
		mlx->x2 = mlx->x;
		mlx->y2 = mlx->y;
	}
		mlx->x1 = (mlx->ylen * (cos(atan(mlx->xlen / mlx->ylen)))) + mlx->x;
		mlx->y1 = -(mlx->ylen * (sin(atan(mlx->xlen / mlx->ylen)))) + mlx->y;
		mlx->y3 = mlx->y - mlx->y1 + mlx->y2;
		mlx->x3 = -(mlx->x1 - mlx->x - mlx->x2);
		mlx->size = mlx->xlen / mlx->strlen;
		mlx->desize = mlx->ylen;
}

void			ft_tophalfp1(t_mlx *mlx)
{
	mlx->x1x = (mlx->incr * (cos(atan(mlx->xlen / mlx->ylen)))) + mlx->x;
	mlx->y1y = -(mlx->incr * (sin(atan(mlx->xlen / mlx->ylen)))) + mlx->y;
}

void			ft_bottomhalfp1(t_mlx *mlx)
{
	mlx->x1z = (mlx->desize * (cos(atan(mlx->xlen / mlx->ylen)))) + mlx->x;
	mlx->y1z = -(mlx->desize * (sin(atan(mlx->xlen / mlx->ylen)))) + mlx->y;
	mlx->y3y = mlx->y - mlx->y1z + mlx->y2;
	mlx->x3x = -(mlx->x1z - mlx->x - mlx->x2);
}

void			ft_bottomhalfp2(t_mlx *mlx)
{
	//mlx->x1z = -(mlx->incr * (cos(atan(mlx->xlen / mlx->ylen)))) + mlx->x2;
	//mlx->y1z = -(mlx->incr * (sin(atan(mlx->xlen / mlx->ylen)))) + mlx->y2;
	//mlx->y3y = mlx->y - mlx->y1z + mlx->y2;
	//mlx->x3x = -(mlx->x1z - mlx->x - mlx->x2);
	mlx->x1 = (mlx->ylen * (cos(atan(mlx->xlen / mlx->ylen))));
	mlx->y1 = -(mlx->ylen * (sin(atan(mlx->xlen / mlx->ylen))));
	mlx->x3x = mlx->x1x - mlx->x1;
	mlx->y3y = mlx->y1y - mlx->y1;
}

void			ft_tophalfp2(t_mlx *mlx)
{
	mlx->x1x = -(mlx->desize * (cos(atan(mlx->ylen / mlx->xlen)))) + mlx->x2;
	mlx->y1y = -(mlx->desize * (sin(atan(mlx->ylen / mlx->xlen)))) + mlx->y2;
}

void			ft_grid2(t_mlx mlx)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_rectsize(&mlx);
	mlx.incr = 0;;

		ft_putnbr(mlx.xlen);
		ft_putchar('\n');
		ft_putnbr(mlx.ylen);
		ft_putchar('\n');
	//mlx.y1 = (SIZE_Y * .25) / 2;
	//mlx.y3 = SIZE_Y - ((SIZE_Y * .25) / 2);

	/*ft_line(mlx.x, mlx.y, mlx.x1, mlx.y1, mlx);
	ft_line(mlx.x1, mlx.y1, mlx.x2, mlx.y2, mlx);
	ft_line(mlx.x2, mlx.y2, mlx.x3, mlx.y3, mlx);
	ft_line(mlx.x, mlx.y, mlx.x3, mlx.y3, mlx);*/
	mlx.xhold = mlx.x;
	mlx.yhold = mlx.y;
	while (i <= mlx.tablen)
	{
		ft_tophalfp1(&mlx);
		ft_bottomhalfp1(&mlx);
		mlx.x3 = mlx.x3x;
		mlx.y3 = mlx.y3y;
		mlx.xhold = mlx.x1x;
		mlx.yhold = mlx.y1y;
		ft_line(mlx.xhold, mlx.yhold, mlx.x3, mlx.y3, mlx);
		mlx.incr += mlx.size;
		mlx.desize -= mlx.size;
		ft_putendl("size");
		ft_putnbr(mlx.size);
		ft_putchar('\n');
		i++;
	}
	//ft_tophalfp1(&mlx);
	//ft_line(mlx.xhold, mlx.yhold, mlx.x, mlx.y, mlx);
	ft_rectsize(&mlx);
	//ft_line(mlx.x, mlx.y, mlx.x1x, mlx.y1y, mlx);
	//ft_line(mlx.x, mlx.y, mlx.x1, mlx.y1, mlx);
	mlx.size = mlx.ylen / mlx.tablen;
	mlx.desize = mlx.xlen;
	mlx.incr = 0;
	mlx.xhold = mlx.x1;
	mlx.yhold = mlx.y1;
	ft_putendl("mlx.x and mlx.y");
	ft_putnbr(mlx.x);
	ft_putchar('\n');
	ft_putnbr(mlx.y);
	ft_putchar('\n');
	ft_putendl("mlx.x1 and mlx.y1");
	ft_putnbr(mlx.x1);
	ft_putchar('\n');
	ft_putnbr(mlx.y1);
	ft_putchar('\n');
	ft_putendl("mlx.x2 and mlx.y2");
	ft_putnbr(mlx.x2);
	ft_putchar('\n');
	ft_putnbr(mlx.y2);
	ft_putchar('\n');
	while (j <= mlx.strlen)
	{
		ft_tophalfp2(&mlx);
		ft_bottomhalfp2(&mlx);
		ft_putendl("x1x and y1y");
		ft_putnbr(mlx.x1x);
		ft_putchar(' ');
		ft_putnbr(mlx.y1y);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("x1z and y1z");
		ft_putnbr(mlx.x1z);
		ft_putchar(' ');
		ft_putnbr(mlx.y1z);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("x3x and y3y");
		ft_putnbr(mlx.x3x);
		ft_putchar(' ');
		ft_putnbr(mlx.y3y);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("size");
		ft_putnbr(mlx.size);
		ft_putchar('\n');
		mlx.x3 = mlx.x3x;
		mlx.y3 = mlx.y3y;
		mlx.xhold = mlx.x1x;
		mlx.yhold = mlx.y1y;
		ft_line(mlx.xhold, mlx.yhold, mlx.x3, mlx.y3, mlx);
		mlx.incr += mlx.size;
		mlx.desize -= mlx.size;
		j++;
	}
}
