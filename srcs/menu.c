/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:26:41 by ashabdan          #+#    #+#             */
/*   Updated: 2020/10/06 01:03:12 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_mx *mx)
{
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 25, mx->txt_color, TITLE);
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 50, mx->txt_color, MOVE);
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 75, mx->txt_color, ZOOM);
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 100, mx->txt_color, COLOR);
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 125, mx->txt_color, Z);
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 150, mx->txt_color, BG);
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 175, mx->txt_color, PROJECT);
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 200, mx->txt_color, EXIT);
}
