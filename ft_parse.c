/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:50:23 by pbie              #+#    #+#             */
/*   Updated: 2016/03/09 15:16:45 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fd				ft_finfobuild(int argc)
{
	t_fd			finfo;

	finfo.fd = 0;
	finfo.line = "";
	finfo.argc = argc;
	return (finfo);
}

void				ft_check_char_print(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 && (str[i] != '\t' && str[i] != '\n'
		&& str[i] != '\r' && str[i] != '\v' && str[i] != '\f'))
			ft_exit("Error: Found Non Printable Character");
		i++;
	}
}

void				ft_parse1bis(t_fd *finfo, t_mlx *mlx, int **nb)
{
	char			**tab;
	int				j;

	j = 0;
	while (ft_get_next_line(finfo->fd, &(finfo->line)) == 1)
	{
		tab = ft_strsplit(finfo->line, ' ');
		if (tab == NULL)
			ft_exit("Error: Empty Line Detected");
		mlx->strlen = ft_tablen(tab);
		nb[j] = ft_parse2(tab, mlx);
		free(finfo->line);
		free(tab);
		j++;
	}
}

int					**ft_parse1(char *file, t_fd *finfo, t_mlx *mlx)
{
	int				j;
	int				**nb;

	j = 0;
	while (ft_get_next_line(finfo->fd, &(finfo->line)) == 1)
	{
		ft_check_char_print(finfo->line);
		j++;
		free(finfo->line);
	}
	close(finfo->fd);
	mlx->tablen = j;
	nb = (int **)malloc(sizeof(int *) * mlx->tablen);
	j = 0;
	finfo->fd = open(file, O_RDONLY);
	ft_parse1bis(finfo, mlx, nb);
	return (nb);
}

int					*ft_parse2(char **tab, t_mlx *mlx)
{
	int				*nb;
	int				i;

	i = 0;
	nb = (int *)malloc(sizeof(int) * mlx->strlen);
	while (tab[i] != NULL)
	{
		nb[i] = ft_atoi(tab[i]);
		i++;
	}
	if (i != mlx->strlen)
		ft_exit("Error: Invalid Map");
	return (nb);
}
