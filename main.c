/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:56:55 by pbie              #+#    #+#             */
/*   Updated: 2016/03/04 17:38:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			ft_putset(t_mlx mlx)
{
	int			y;

	y = 0;
	mlx_string_put(mlx.mlx, mlx.win, 0, y, 0xccccff, L_CONTROLS);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 16, 0xccccff, L_UP);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 32, 0xccccff, L_DOWN);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 48, 0xccccff, L_LEFT);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 64, 0xccccff, L_RIGHT);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 80, 0xccccff, L_PLUS);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 96, 0xccccff, L_MINUS);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 112, 0xccccff, L_PAGE_UP);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 128, 0xccccff, L_PAGE_DOWN);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 144, 0xccccff, L_HOME);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 160, 0xccccff, L_RESET);
	mlx_string_put(mlx.mlx, mlx.win, 0, y + 176, 0xccccff, L_ESC);
}

int				ft_keycheck(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == 36)
		ft_mapsize(mlx);
	else if (keycode == PAGE_UP || keycode == PAGE_DOWN)
		mlx->z += (keycode == PAGE_UP ? 1 : -1);
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		mlx->x += (keycode == LEFT_ARROW ? -4 : 4);
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW)
		mlx->y += (keycode == UP_ARROW ? -4 : 4);
	else if (keycode == MINUS || keycode == PLUS || keycode == MINUS2 ||
			keycode == PLUS2)
		mlx->zoom += (keycode == MINUS || keycode == MINUS2 ? -2 : 2);
	else if (keycode == HOME)
	{
		mlx->c += 0x123456;
		mlx->c2 += 0x123456;
	}
	ft_gridnew(*mlx);
	ft_putset(*mlx);
	printf("key event %d\n", keycode);
	ft_putnbrtab(mlx->nb, mlx);
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx		mlx;
	t_fd		finfo;
	int			c_x;
	int			c_y;

	if (argc != 2)
		ft_exit("Wrong Number of Arguments");
	c_x = SIZE_X * 2 / 5;
	c_y = SIZE_Y * 2 / 5;
	finfo = ft_finfobuild(argc);
	if ((finfo.fd = open(argv[1], O_RDONLY)) <= 0)
		ft_exit("Invalid File");
	mlx.nb = ft_parse1(argv[1], &finfo, &mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZE_X, SIZE_Y, "fdf");
	mlx_string_put(mlx.mlx, mlx.win, c_x + 100, c_y, 0x009999FF, HELLO);
	mlx_string_put(mlx.mlx, mlx.win, c_x + 16, c_y + 30, 0x009999FF, START);
	ft_mapsize(&mlx);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, ft_keycheck, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
