/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:48:57 by ashabdan          #+#    #+#             */
/*   Updated: 2020/03/27 19:40:23 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

# define ESC 53
# define LEFT 123
# define UP 126
# define RIGHT 124
# define DOWN 125
# define PLUS 24
# define MINUS 27
# define SPACE 49
# define Z_UP 47
# define Z_DOWN 43
# define DARK 2
# define LIGHT 37

typedef struct	s_bresenvar
{
	int			delta_x;
	int			delta_y;
	int			signum_x;
	int			signum_y;
	int			error_x;
	int			error_y;
}				t_brevar;

typedef struct	s_coords
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			z0;
	int			z1;
}				t_coords;

typedef struct	s_control
{
	int			zoom;
	int			shift_x;
	int			shift_y;
	int			altitude;
}				t_control;

typedef struct	s_matrix
{
	int			**board;
	int			width;
	int			height;
	int			color;
	int			base_color;
	int			relief_color;
	char			*bg_img;
	int			txt_color;
	int			mode;
	int			iso;

	void		*mlx_ptr;
	void		*win_ptr;

	t_brevar	brevar;
	t_coords	crd;
	t_control	ac;
}				t_mx;

void			getmatrix(char *filename, t_mx *matrix);
void			get_picture(t_mx *mx);
void			print_error(int err);
void			print_menu(t_mx *mx);

/*
**	Control
*/

void			movemx(int key, t_mx *mx);
void			zoommx(int key, t_mx *mx);
void			colorizemx(t_mx *mx);
void			change_z(int key, t_mx *mx);
void			switch_mode(int key, t_mx *mx);

/*
**	Utils
*/

void			swapcoords(int *a, int *b, int *c, int *d);
void			ft_swap(int *a, int *b);
int			wordcounter(const char *s, char c);
void			iso(int *x, int *y, int z);

#endif
