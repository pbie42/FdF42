/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:56:55 by pbie              #+#    #+#             */
/*   Updated: 2016/02/11 18:25:44 by pbie             ###   ########.fr       */
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
	if (keycode == 124)
		mlx->c = mlx->c - 001010;
	else if (keycode == 53)
		exit(0);
	printf("key event %d\n", keycode);
	ft_square(*mlx);
	return (0);
}

char			**ft_buildtab(int j)
{
	char		**tab;

	tab = (char **)malloc(sizeof(char *) * j + 1);
	return (tab);
}

int				main(int argc, char **argv)
{
	t_mlx		mlx;
	int			fd;
	char		*line;
	int			i;
	char		**tab;
	int			j;
	int			**nb;

	i = 1;
	j = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZE_X, SIZE_Y, "maintest");
	mlx.c = 0x00FFFFFF;
	mlx.y = SIZE_Y / 4;
	mlx.x = SIZE_X / 4;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		while (ft_get_next_line(fd, &line) == 1)
			j++;
		++i;
	}
	close(fd);
	ft_putnbr(fd);
	ft_putchar('\n');
	tab = ft_buildtab(j);
	i = 1;
	j = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		while (ft_get_next_line(fd, &line) == 1)
		{
			tab[j] = ft_strndup(line, ft_strlen(line));
			free(line);
			j++;
		}
		++i;
	}
	ft_putnbr(fd);
	ft_putchar('\n');
	tab[j] = NULL;
	nb = ft_parse2(tab);
	ft_putnbrtab(nb, tab);
	ft_putstrtab(tab);
	ft_square(mlx);
	mlx_key_hook(mlx.win, ft_keycheck, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
