/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:07:26 by ashabdan          #+#    #+#             */
/*   Updated: 2020/03/08 17:26:03 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	movemx(int key, t_mx *mx)
{
	if (key == UP)
		mx->ac.shift_y -= 10;
	else if (key == DOWN)
		mx->ac.shift_y += 10;
	else if (key == RIGHT)
		mx->ac.shift_x += 10;
	else if (key == LEFT)
		mx->ac.shift_x -= 10;
	mlx_clear_window(mx->mlx_ptr, mx->win_ptr);
	get_picture(mx);
}

void	zoommx(int key, t_mx *mx)
{
	if (key == PLUS)
		mx->ac.zoom += 5;
	else if (key == MINUS && mx->ac.zoom > 5)
		mx->ac.zoom -= 5;
	mlx_clear_window(mx->mlx_ptr, mx->win_ptr);
	get_picture(mx);
}

void	colorizemx(t_mx *mx)
{
	int			color[5];
	static int	index;

	if (index == 5)
		index = 0;
	color[0] = 0xfad02c;
	color[1] = 0x145da0;
	color[2] = 0xdb1f48;
	color[3] = 0x21b6a8;
	color[4] = 0xf8efe4;
	mx->color = color[index];
	mlx_clear_window(mx->mlx_ptr, mx->win_ptr);
	get_picture(mx);
	index += 1;
}

void	change_z(int key, t_mx *mx)
{
	printf("key - %d; A_LET - %d; Z_LET - %d\n", key, A_LET, Z_LET);
	if (key == A_LET)
		mx->ac.altitude += 1;
	else if (key == Z_LET)
		mx->ac.altitude -= 1;
	mlx_clear_window(mx->mlx_ptr, mx->win_ptr);
	get_picture(mx);
}
