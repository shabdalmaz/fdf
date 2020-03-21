/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:02:41 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/11 19:18:33 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprime(int num)
{
	int iter;

	iter = 0;
	if (num)
	{
		iter = num - 1;
		while (iter > 1)
		{
			if (num % iter == 0)
				return (0);
			iter -= 1;
		}
	}
	return (1);
}
