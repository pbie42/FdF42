/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:56:55 by pbie              #+#    #+#             */
/*   Updated: 2016/02/09 18:31:46 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int				ft_keycheck(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void			ft_square(t_mlx *mlx)
{
	while (mlx->y < (SIZE_Y * (3 / 4)))
	{
		mlx->x = 250;
		while (mlx->x < (SIZE_X * (3 / 4)))
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->x, mlx->y, 0x00FFFFFF);
			mlx->x++;
		}
		mlx->y++;
	}
}

int				main(int argc, char **argv)
{
	t_mlx		mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZE_X, SIZE_Y, "maintest");
	mlx.y = SIZE_Y / 4;
	mlx.x = SIZE_X / 4;
	ft_square(&mlx);
	mlx_key_hook(mlx.win, ft_keycheck, 0);
	mlx_loop(mlx.mlx);
}
