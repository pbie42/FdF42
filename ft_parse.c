/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:50:23 by pbie              #+#    #+#             */
/*   Updated: 2016/03/02 17:28:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fd			ft_finfobuild(int argc)
{
	t_fd		finfo;

	finfo.fd = 0;
	finfo.line = "";
	finfo.argc = argc;
	return (finfo);
}

int				**ft_numboard(int c)
{
	int			**nb;

	nb = (int **)malloc(sizeof(int *) * c);
	return (nb);
}

int				**ft_parse1(char *file, t_fd *finfo, t_mlx *mlx)
{
	char		**tab;
	int			j;
	int			**nb;

	j = 0;
	if ((finfo->fd = open(file, O_RDONLY)) <= 0)
		ft_exit("File Failure");
	while (ft_get_next_line(finfo->fd, &(finfo->line)) == 1)
	{
		j++;
		free(finfo->line);
	}
	close(finfo->fd);
	mlx->tablen = j;
	nb = ft_numboard(mlx->tablen);
	j = 0;
	finfo->fd = open(file, O_RDONLY);
	while (ft_get_next_line(finfo->fd, &(finfo->line)) == 1)
	{
		tab = ft_strsplit(finfo->line, ' ');
		mlx->strlen = (ft_tablen(tab));
		nb[j] = ft_parse2(tab, mlx);
		free(finfo->line);
		free(tab);
		j++;
	}
	return (nb);
}

int				*ft_parse2(char **tab, t_mlx *mlx)
{
	int			*nb;
	int			i;

	i = 0;
	nb = (int *)malloc(sizeof(int) * mlx->strlen);
	while (tab[i] != NULL)
	{
		nb[i] = ft_atoi(tab[i]);
		i++;
	}
	return (nb);
}
