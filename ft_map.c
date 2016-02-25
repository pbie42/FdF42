/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:22:32 by pbie              #+#    #+#             */
/*   Updated: 2016/02/25 18:30:08 by pbie             ###   ########.fr       */
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
		mlx->x = SIZE_X - (SIZE_X * .1);
		mlx->y = SIZE_Y - (SIZE_Y * .33);
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

	/*j = mlx.strlen;
	while (j >= 0)
	{
		mlx.x1x = mlx.x;
		mlx.y1y = mlx.y;
		i = 0;
		while (i <= mlx.tablen)
		{
			mlx.x2 = mlx.x1x - mlx.size;
			mlx.y2 = mlx.y1y - (mlx.size / 2);
			if (j - 1 != -1)
			{
				mlx.y2 = nb[i][j - 1] != 0 ? mlx.y2 - nb[i][j] : mlx.y2;
				mlx.c = nb[i][j - 1] != 0 ? 0x006600FF : 0x00FFFFFF;
				ft_line(mlx.x1x, mlx.y1y, mlx.x2, mlx.y2, mlx);
				mlx.y2 = nb[i][j - 1] != 0 ? mlx.y2 + nb[i][j] : mlx.y2;
			}
			mlx.y2 += mlx.size;
			if (i + 1 != mlx.tablen + 1)
			{
				mlx.y2 = nb[i + 1][j] != 0 ? mlx.y2 - nb[i][j] : mlx.y2;
				mlx.c = nb[i + 1][j] != 0 ? 0x006600FF : 0x00FFFFFF;
				ft_line(mlx.x1x, mlx.y1y, mlx.x2, mlx.y2, mlx);
				mlx.y2 = nb[i][j - 1] != 0 ? mlx.y2 + nb[i][j] : mlx.y2;
			}
			mlx.x1x = mlx.x2;
			mlx.y1y = mlx.y2;
			i++;
		}
		mlx.x -= mlx.size;
		mlx.y -= (mlx.size / 2);
		j--;
	}*/

	i = 0;
	while (i <= mlx.tablen)
	{
		mlx.x1x = mlx.x;
		mlx.y1y = mlx.y;
		j = mlx.strlen;
		while (j >= 0)
		{
			mlx.x2 = mlx.x1x - mlx.size;
			mlx.y2 = mlx.y1y - (mlx.size / 2);
			if (j - 1 != -1)
			{
				mlx.y2 = nb[i][j - 1] != 0 ? mlx.y2 - nb[i][j] : mlx.y2;
				mlx.c = (nb[i][j] != 0 && nb[i][j - 1] != 0 ? mlx.c = 0x006600FF : 0x00FFFFFF);
				ft_line(mlx.x1x, mlx.y1y, mlx.x2, mlx.y2, mlx);
				mlx.y2 = nb[i][j - 1] != 0 ? mlx.y2 + nb[i][j] : mlx.y2;
			}
			mlx.x1x = mlx.x2;
			mlx.y1y = mlx.y2;
			j--;
		}
		mlx.x -= mlx.size;
		mlx.y += (mlx.size / 2);
		i++;
	}


	/*while (i <= mlx.tablen)
	{
		mlx.x1x = mlx.x;
		mlx.y1y = mlx.y;
		j = mlx.strlen;
		while (j >= 0)
		{
			mlx.x2 = mlx.x1x - mlx.size;
			mlx.y2 = mlx.y1y - (mlx.size / 2);
			if (j - 1 != -1)
				ft_line(mlx.x1x, mlx.y1y, mlx.x2, mlx.y2, mlx);
			mlx.y2 += mlx.size;
			if (i + 1 != mlx.tablen + 1)
				ft_line(mlx.x1x, mlx.y1y, mlx.x2, mlx.y2, mlx);
			mlx.x1x = mlx.x2;
			mlx.x1x = mlx.y2;
			j--;
		}
		mlx.x -= mlx.size;
		mlx.y += (mlx.size / 2);
		i++;
	}*/



	/*while (i <= mlx.tablen)
	{
		j = mlx.strlen;
		mlx.x1x = mlx.x;
		mlx.y1y = mlx.y;
		while (j >= 0)
		{
			mlx.x2 = mlx.x1x - mlx.size;
			mlx.y2 = mlx.y1y + (mlx.size / 2);
			//if (nb[i][j])
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
		i++;
	}*/
}
