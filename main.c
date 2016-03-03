/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:56:55 by pbie              #+#    #+#             */
/*   Updated: 2016/03/03 18:12:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int				ft_keycheck(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == PAGE_UP || keycode == PAGE_DOWN)
		mlx->z += (keycode == PAGE_UP ? 1 : -1);
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		mlx->x += (keycode == LEFT_ARROW ? -4 : 4);
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW)
		mlx->y += (keycode == UP_ARROW ? -4 : 4);
	else if (keycode == MINUS || keycode == PLUS)
		mlx->zoom += (keycode == MINUS ? -2 : 2);
	else if (keycode == HOME)
	{
		mlx->c += 0x123456;
		mlx->c2 += 0x123456;
	}
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
	finfo = ft_finfobuild(argc);
	mlx.nb = ft_parse1(argv[1], &finfo, &mlx);
	ft_mapsize(&mlx);
	ft_putnbr(mlx.z);
	ft_putchar('\n');
	ft_gridnew(mlx);
	ft_putnbr(mlx.z);
	ft_putchar('\n');
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, ft_keycheck, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
