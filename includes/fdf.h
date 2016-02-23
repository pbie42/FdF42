/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:06:29 by pbie              #+#    #+#             */
/*   Updated: 2016/02/23 18:32:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE_X 1000
# define SIZE_Y 1000

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				y;
	int				x;
	int				x1;
	int				y1;
	int				x1x;
	int				y1y;
	int				x1z;
	int				y1z;
	int				x2;
	int				y2;
	int				x3;
	int				y3;
	int				x3x;
	int				y3y;
	double				ylen;
	double				xlen;
	int				c;
	int				tablen;
	int				strlen;
	double				mpsz;
	double				sqrsz;
	double				size;
	double				desize;
	double				incr;
}					t_mlx;

typedef struct		s_fd
{
	int				fd;
	char			*line;
	int				argc;
}					t_fd;

typedef struct		s_line
{
	int				x;
	int				y;
	int				dx0;
	int				dy0;
	int				dx1;
	int				dy1;
	int				longest;
	int				shortest;
	int				numerator;
}					t_line;

int					**ft_parse1(char *file, t_fd *finfo, t_mlx *mlx);
int					*ft_parse2(char **tab, t_mlx *mlx);
char				**ft_buildtab(int j);
t_fd				ft_finfobuild(int argc);
int					*ft_chartonumline(char *s, int c);
int					ft_strlennum(char const *s);
int					**ft_numboard(int c);
void				ft_putnbrline(int *nl, int len);
//void				ft_putnbrtab(int **nb, char **tab);
void			ft_putnbrtab(int **nb, t_mlx *mlx);
void				ft_grid(t_mlx mlx, int **nb);
void				ft_line(int x0, int y0, int x1, int y1, t_mlx mlx);
void				ft_linedraw(int x0, int y0, int x1, int y1, t_mlx mlx);
void				ft_grid2(t_mlx mlx);
void				ft_rectsize(t_mlx *mlx);

#endif
