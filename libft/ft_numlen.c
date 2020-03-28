/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:49:16 by ashabdan          #+#    #+#             */
/*   Updated: 2020/02/25 19:09:44 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(int n, int base)
{
	int size;

	size = 0;
	if (n == 0)
		size = 1;
	else if (n < 0)
	{
		size += 1;
		n *= -1;
	}
	else
	{
		while (n)
		{
			n /= base;
			size++;
		}
	}
	return (size);
}
