/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:06:29 by pbie              #+#    #+#             */
/*   Updated: 2016/03/08 18:02:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE_X 1500
# define SIZE_Y 1000
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define MINUS 27
# define PLUS 24
# define MINUS2 78
# define PLUS2 69
# define ESC_KEY 53
# define PAGE_UP 116
# define PAGE_DOWN 121
# define HOME 115
# define END 119
# define HELLO "FdF by pbie"
# define START "Continue by pressing any key"
# define L_CONTROLS "             CONTROLS"
# define L_UP "  Move Up       ||     Up"
# define L_DOWN "  Move Down     ||     Down"
# define L_LEFT "  Move Left     ||     Left"
# define L_RIGHT "  Move Right    ||     Right"
# define L_PLUS "  Zoom In       ||     +"
# define L_MINUS "  Zoom Out      ||     -"
# define L_PAGE_UP "  Increase      ||     Page Up"
# define L_PAGE_DOWN "  Decrease      ||     Page Down"
# define L_HOME "  Psychadelic   ||     Home"
# define L_RESET "  Reset         ||     Enter"
# define L_ESC "  Exit          ||     Esc"
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)

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
	int				z;
	int				x2;
	int				y2;
	double			ylen;
	double			xlen;
	int				col;
	int				c;
	int				c2;
	int				tablen;
	int				strlen;
	double			mpsz;
	double			size;
	int				**nb;
	int				zoom;
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
void				ft_putnbrtab(int **nb, t_mlx *mlx);
void				ft_grid(t_mlx mlx, int **nb);
void				ft_line(t_mlx mlx);
void				ft_gridnew(t_mlx mlx);
void				ft_gridnew2(t_mlx mlx);
void				ft_xyreset(t_mlx *mlx);
void				ft_x2y2g1(t_mlx *mlx);
void				ft_x2y2g2(t_mlx *mlx);
void				ft_g1core(t_mlx *mlx, int i, int j);
void				ft_g2core(t_mlx *mlx, int i, int j);
void				ft_rectsize(t_mlx *mlx);
void				ft_mapsize(t_mlx *mlx);
void				ft_check_char_print(char *str);

#endif
