/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:10:18 by pbie              #+#    #+#             */
/*   Updated: 2016/02/09 15:30:49 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int				my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	return (0);
}

int				main()
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	y = 50;
	while (y < 150)
	{
		x = 250;
		while (x < 350)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	y = 250;
	while (y < 350)
	{
		x = 50;
		while (x < 350)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
}
