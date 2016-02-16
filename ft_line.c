/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:33:57 by pbie              #+#    #+#             */
/*   Updated: 2016/02/16 18:41:40 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line			ft_linfofill(int x0, int y0, int x1, int y1)
{
	t_line		linfo;

	linfo.x = x1 - x0;
	linfo.y = y1 - y0;
	linfo.dx0 = linfo.x < 0 ? -1 : 1;
	return (linfo);
}

void			ft_line(int x0, int y0, int x1, int y1)
{
	t_line		linfo;

	linfo = ft_linfofill;
}
