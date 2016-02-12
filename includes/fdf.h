/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:06:29 by pbie              #+#    #+#             */
/*   Updated: 2016/02/12 17:20:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE_X 1000
# define SIZE_Y 1000

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				y;
	int				x;
	int				c;
	int				tablen;
}					t_mlx;

typedef struct		s_fd
{
	int				fd;
	char			*line;
	int				argc;
}					t_fd;

char				**ft_parse1(char *file, t_fd *finfo);
int					**ft_parse2(char **tab, t_mlx *mlx);
char				**ft_buildtab(int j);
t_fd				ft_finfobuild(int argc);
int					*ft_chartonumline(char *s, int c);
int					ft_strlennum(char const *s);
int					**ft_numboard(int c);
void				ft_putnbrline(int *nl, int len);
void				ft_putnbrtab(int **nb, char **tab);

#endif
