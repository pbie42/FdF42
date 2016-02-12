/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:21:31 by pbie              #+#    #+#             */
/*   Updated: 2016/02/12 17:20:17 by pbie             ###   ########.fr       */
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

char			**ft_parse1(char *file, t_fd *finfo)
{
	char		**tab;
	int			j;

	j = 0;
	if (finfo->argc != 2)
		ft_exit("Wrong number of arguments!");
	if ((finfo->fd = open(file, O_RDONLY)) <= 0)
		ft_exit("File Failure");
	while (ft_get_next_line(finfo->fd, &(finfo->line)) == 1)
	{
		j++;
		free(finfo->line);
	}
	close(finfo->fd);
	tab = ft_buildtab(j);
	j = 0;
	finfo->fd = open(file, O_RDONLY);
	while (ft_get_next_line(finfo->fd, &(finfo->line)) == 1)
	{
		tab[j] = ft_strndup(finfo->line, ft_strlen(finfo->line));
		free(finfo->line);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int				**ft_parse2(char **tab, t_mlx *mlx)
{
	int			**nb;
	int			i;

	i = 0;
	mlx->tablen = ft_tablen(tab);
	nb = ft_numboard(mlx->tablen);
	while (tab[i] != NULL)
	{
		nb[i] = ft_chartonumline(tab[i], ft_strlennum(tab[i]));
		i++;
	}
	return (nb);
}
