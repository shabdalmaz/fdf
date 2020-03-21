/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:41:21 by ashabdan          #+#    #+#             */
/*   Updated: 2020/03/08 19:33:41 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_control(int key, t_mx *mx)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key >= LEFT && key <= UP)
		movemx(key, mx);
	else if (key == PLUS || key == MINUS)
		zoommx(key, mx);
	else if (key == SPACE)
		colorizemx(mx);
	else if (key == A_LET || key == Z_LET)
		change_z(key, mx);
	return (0);
}

void	mxinit(t_mx *mx)
{
	mx->mlx_ptr = mlx_init();
	mx->win_ptr = mlx_new_window(mx->mlx_ptr, 1280, 720, "FDF");
	mx->color = 0xffffff;
	mx->ac.shift_x = 600;
	mx->ac.shift_y = 100;
	mx->ac.zoom = 40;
	mx->ac.altitude = 5;
	mx->crd.x0 = 0;
	mx->crd.y0 = 0;
	mx->crd.x1 = 0;
	mx->crd.y1 = 0;
	mx->crd.z0 = 0;
	mx->crd.z1 = 0;
}

void	mxfree(t_mx **mx)
{
	int	y;

	y = 0;
	while (y < (*mx)->height)
	{
		free((*mx)->board[y]);
		y += 1;
	}
	free((*mx)->board);
	free(*mx);
}

int	main(int argc, char *argv[])
{
	t_mx	*mx;

	mx = NULL;
	if (argc == 2)
	{
		if (!(mx = (t_mx *)malloc(sizeof(t_mx))))
			print_error(2);
		getmatrix(argv[1], mx);
		mxinit(mx);
		get_picture(mx);
		mlx_key_hook(mx->win_ptr, key_control, mx);
		mlx_loop(mx->mlx_ptr);
	}
	else
		print_error(0);
	mxfree(&mx);
	return (0);
}
