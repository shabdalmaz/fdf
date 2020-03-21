/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:40:19 by ashabdan          #+#    #+#             */
/*   Updated: 2020/03/08 20:25:30 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	paint_px(t_mx mx, int len, int dx_or_dy, t_brevar var)
{
	int		i;
	int		dist;

	i = -1;
	dist = 0;
	while (++i <= len)
	{
		mlx_pixel_put(mx.mlx_ptr, mx.win_ptr, mx.crd.x0, mx.crd.y0, mx.color);
		dist += dx_or_dy;
		if (2 * dist >= len)
		{
			mx.crd.y0 += var.signum_y;
			mx.crd.x0 += var.signum_x;
			dist -= len;
		}
		else
		{
			mx.crd.y0 += var.error_y;
			mx.crd.x0 += var.error_x;
		}
	}
}

void		bresenham_line(t_coords *crd, t_mx *mx)
{
	t_brevar	var;

	var.delta_x = abs(crd->x1 - crd->x0);
	var.delta_y = abs(crd->y1 - crd->y0);
	var.signum_x = (crd->x1 - crd->x0 > 0) ? 1 : -1;
	var.signum_y = (crd->y1 - crd->y0 > 0) ? 1 : -1;
	var.error_x = 0;
	var.error_y = 0;
	if (var.delta_y > var.delta_x)
	{
		var.error_y = var.signum_y;
		paint_px(*mx, var.delta_y, var.delta_x, var);
	}
	else
	{
		var.error_x = var.signum_x;
		paint_px(*mx, var.delta_x, var.delta_y, var);
	}
}

static void	iso(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(0.5) - z;
}

static void	draw(t_mx mx)
{
	mx.crd.z0 = mx.board[mx.crd.y0][mx.crd.x0];
	mx.crd.z1 = mx.board[mx.crd.y1][mx.crd.x1];
	if (mx.crd.z0 || mx.crd.z1)
	{
		mx.crd.z0 *= mx.ac.altitude;
		mx.crd.z1 *= mx.ac.altitude;
	}
	mx.crd.x0 *= mx.ac.zoom;
	mx.crd.x1 *= mx.ac.zoom;
	mx.crd.y0 *= mx.ac.zoom;
	mx.crd.y1 *= mx.ac.zoom;
	iso(&mx.crd.x0, &mx.crd.y0, mx.crd.z0);
	iso(&mx.crd.x1, &mx.crd.y1, mx.crd.z1);
	mx.crd.x0 += mx.ac.shift_x;
	mx.crd.x1 += mx.ac.shift_x;
	mx.crd.y0 += mx.ac.shift_y;
	mx.crd.y1 += mx.ac.shift_y;
	bresenham_line(&mx.crd, &mx);
}

void		get_picture(t_mx *mx)
{
	mx->crd.y0 = 0;
	while (mx->crd.y0 < mx->height)
	{
		mx->crd.x0 = 0;
		while (mx->crd.x0 < mx->width)
		{
			if (mx->crd.x0 < mx->width - 1)
			{
				mx->crd.x1 = mx->crd.x0 + 1;
				mx->crd.y1 = mx->crd.y0;
				draw(*mx);
			}
			if (mx->crd.y0 < mx->height - 1)
			{
				mx->crd.x1 = mx->crd.x0;
				mx->crd.y1 = mx->crd.y0 + 1;
				draw(*mx);
			}
			mx->crd.x0 += 1;
		}
		mx->crd.y0 += 1;
	}
}
