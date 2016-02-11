/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:06:29 by pbie              #+#    #+#             */
/*   Updated: 2016/02/11 15:09:02 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE_X 1000
# define SIZE_Y 1000

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				y;
	int				x;
	int				c;
}					t_mlx;

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"

#endif
