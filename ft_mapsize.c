/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:51:12 by pbie              #+#    #+#             */
/*   Updated: 2016/02/17 18:12:42 by pbie             ###   ########.fr       */
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

void			ft_squaresize(t_mlx *mlx)
{
	mlx->sqrs = sqrt((mlx->strlen * mlx->strlen) + (mlx->tablen * mlx->tablen));
	if (SIZE_X > SIZE_Y)
		mlx->size = (SIZE_Y - (SIZE_Y * .25)) / mlx->sqrs;
	else
		mlx->size = (SIZE_X - (SIZE_X * .25)) / mlx->sqrs;
}

void			ft_grid2(t_mlx mlx, int nb)
{
	int			x;
	int			y;
	int			x2;
	int			y2;
	int			i;
	int			j;

	ft_displaysize(&mlx);
	i = 0;

	x2 = x;
	
}
