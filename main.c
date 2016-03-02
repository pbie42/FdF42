/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:56:55 by pbie              #+#    #+#             */
/*   Updated: 2016/03/02 18:23:46 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			ft_square(t_mlx mlx)
{
	while (mlx.y < (SIZE_Y * (0.75)))
	{
		mlx.x = 250;
		while (mlx.x < (SIZE_X * (0.75)))
		{
			mlx_pixel_put(mlx.mlx, mlx.win, mlx.x, mlx.y, mlx.c);
			mlx.x++;
		}
		mlx.y++;
	}
}

int				ft_keycheck(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 116)
		mlx->z += 1;
	else if (keycode == 121)
		mlx->z -= 1;
	else if (keycode == 123)
		mlx->x -= 2;
	else if (keycode == 124)
		mlx->x += 2;
	else if (keycode == 126)
		mlx->y -= 2;
	else if (keycode == 125)
		mlx->y += 2;
	ft_gridnew(*mlx);
	printf("key event %d\n", keycode);
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx		mlx;
	t_fd		finfo;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZE_X, SIZE_Y, "maintest");
	mlx.c = 0x00FFFFFF;
	finfo = ft_finfobuild(argc);
	mlx.nb = ft_parse1(argv[1], &finfo, &mlx);
	ft_mapsize(&mlx);
	ft_putnbr(mlx.z);
	ft_putchar('\n');
	ft_gridnew(mlx);
	ft_putnbr(mlx.z);
	ft_putchar('\n');
	mlx_key_hook(mlx.win, ft_keycheck, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
