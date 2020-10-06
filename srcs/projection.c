/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 00:51:46 by ashabdan          #+#    #+#             */
/*   Updated: 2020/10/06 00:52:06 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(0.5) - z;
}

void	switch_projection(t_mx *mx)
{
	if (mx->iso)
		mx->iso = 0;
	else
		mx->iso = 1;
	mlx_clear_window(mx->mlx_ptr, mx->win_ptr);
	get_picture(mx);
}
