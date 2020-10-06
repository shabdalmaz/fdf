/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:47:35 by ashabdan          #+#    #+#             */
/*   Updated: 2020/10/05 21:27:20 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(int err)
{
	if (err == 0)
		ft_putstr_fd("usage:\t<source_file>\n", 1);
	else if (err == 1)
		perror("");
	else if (err == 2)
		ft_putstr_fd("Memory wasn't allocated", 1);
	exit(EXIT_FAILURE);
}
