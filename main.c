/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:56:55 by pbie              #+#    #+#             */
/*   Updated: 2016/03/03 15:58:44 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int				ft_keycheck(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 116 || keycode == 121)
		mlx->z += (keycode == 116 ? 1 : -1);
	else if (keycode == 123 || keycode == 124)
		mlx->x += (keycode == 123 ? -2 : 2);
	else if (keycode == 126 || keycode == 125)
		mlx->y += (keycode == 126 ? -2 : 2);
	else if (keycode == 27 || keycode == 24)
		mlx->zoom += (keycode == 27 ? -2 : 2);
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
