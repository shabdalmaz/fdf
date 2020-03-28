/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:26:41 by ashabdan          #+#    #+#             */
/*   Updated: 2020/03/27 19:41:41 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_mx *mx)
{
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 25, mx->txt_color, "HOW TO USE");
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 50, mx->txt_color, "Move: Arrows");
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 75, mx->txt_color, "Zoom: +/-");
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 100, mx->txt_color, "Change color: Space");
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 125, mx->txt_color, "Z-Axis: </>");
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 150, mx->txt_color, "Dark/Light: D/L");
	mlx_string_put(mx->mlx_ptr, mx->win_ptr, 25, 175, mx->txt_color, "Exit: Esc");
}
