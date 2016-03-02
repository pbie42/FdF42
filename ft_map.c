/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:22:32 by pbie              #+#    #+#             */
/*   Updated: 2016/03/02 17:20:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_mapsize(t_mlx *mlx)
{
	mlx->mpsz = sqrt((mlx->strlen * mlx->strlen) + (mlx->tablen * mlx->tablen));
	mlx->z = 3;
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
		mlx->x = SIZE_X - (SIZE_X * .1);
		mlx->y = SIZE_Y - (SIZE_Y * .33);
		mlx->mpsz = sqrt((mlx->xlen * mlx->xlen) + (mlx->ylen * mlx->ylen));
	}
	else
	{
		mlx->xlen = ((mlx->strlen) * (SIZE_Y - (SIZE_Y * .5))) / mlx->mpsz;
		mlx->ylen = ((mlx->tablen) * (SIZE_Y - (SIZE_Y * .5))) / mlx->mpsz;
		mlx->x = SIZE_X - (SIZE_X * .1);
		mlx->y = SIZE_Y - (SIZE_Y * .33);
		mlx->mpsz = sqrt((mlx->xlen * mlx->xlen) + (mlx->ylen * mlx->ylen));
	}
}
