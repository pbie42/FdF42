/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:22:32 by pbie              #+#    #+#             */
/*   Updated: 2016/03/04 16:39:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_mapsize(t_mlx *mlx)
{
	mlx->mpsz = sqrt((mlx->strlen * mlx->strlen) + (mlx->tablen * mlx->tablen));
	mlx->z = 3;
	mlx->zoom = 5;
	if (SIZE_X > SIZE_Y)
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_Y - (SIZE_Y * .25))) / mlx->mpsz;
		mlx->x = SIZE_X - (SIZE_X * .1);
		mlx->y = SIZE_Y - (SIZE_Y * .33);
	}
	else if (SIZE_Y > SIZE_X)
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_X - (SIZE_X * .25))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_X - (SIZE_X * .25))) / mlx->mpsz;
		mlx->x = SIZE_X - (SIZE_X * .1);
		mlx->y = SIZE_Y - (SIZE_Y * .33);
	}
	else
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_Y - (SIZE_Y * .5))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_Y - (SIZE_Y * .5))) / mlx->mpsz;
		mlx->x = SIZE_X - (SIZE_X * .1);
		mlx->y = SIZE_Y - (SIZE_Y * .33);
	}
	mlx->size = (mlx->xlen / mlx->strlen) + mlx->zoom;
	mlx->c = 0x00FFFFFF;
	mlx->c2 = 0x006600FF;
}
