/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:46:53 by ashabdan          #+#    #+#             */
/*   Updated: 2019/09/27 19:47:28 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int n, int power)
{
	int origin;

	origin = n;
	if (power == 0)
		return (1);
	else if (power > 0)
	{
		while (--power)
			n *= origin;
		return (n);
	}
	else
		return (0);
}
