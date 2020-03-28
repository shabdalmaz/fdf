/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:47:35 by ashabdan          #+#    #+#             */
/*   Updated: 2020/03/27 19:26:08 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(int err)
{
	if (err == 0)
		ft_putstr("usage:\t<source_file>\n");
	else if (err == 1)
		perror("");
	else if (err == 2)
		ft_putstr("Memory wasn't allocated");
	exit(EXIT_FAILURE);
}
