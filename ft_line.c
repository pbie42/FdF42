/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:33:57 by pbie              #+#    #+#             */
/*   Updated: 2016/02/17 14:39:39 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line			ft_linfofill(int x0, int y0, int x1, int y1)
{
	t_line		linfo;

	linfo.x = x1 - x0;
	linfo.y = y1 - y0;
	linfo.dx0 = linfo.x < 0 ? -1 : 1;
	linfo.dy0 = linfo.y < 0 ? -1 : 1;
	linfo.dx1 = linfo.x < 0 ? -1 : 1;
	linfo.longest = abs(linfo.x);
	linfo.shortest = abs(linfo.y);
	if (!(linfo.longest > linfo.shortest))
	{
		linfo.longest = abs(linfo.y);
		linfo.shortest = abs(linfo.x);
		if (linfo.y < 0)
			linfo.dy1 = -1;
		else if (linfo.y > 0)
		{
			linfo.dy1 = 1;
			linfo.dx1 = 0;
		}
	}
	linfo.numerator = linfo.longest >> 1;
	return (linfo);
}

void			ft_line(int x0, int y0, int x1, int y1, t_mlx mlx)
{
	t_line		linfo;
	int			i;

	i = 0;
	linfo = ft_linfofill(x0, y0, x1, y1);
	while (i <= linfo.longest)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, linfo.x, linfo.y, mlx.c);
		linfo.numerator += linfo.shortest;
		if (!(linfo.numerator < linfo.longest))
		{
			linfo.x += linfo.dx0;
			linfo.y += linfo.dy0;
		}
		else
		{
			linfo.x += linfo.dx1;
			linfo.y += linfo.dy1;
		}
		i++;
	}
}