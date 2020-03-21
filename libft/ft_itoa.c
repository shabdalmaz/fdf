/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 03:03:01 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/10 20:58:58 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static char		*if_min(char *ptr)
{
	*ptr++ = '-';
	*ptr++ = '2';
	*ptr++ = '1';
	*ptr++ = '4';
	*ptr++ = '7';
	*ptr++ = '4';
	*ptr++ = '8';
	*ptr++ = '3';
	*ptr++ = '6';
	*ptr++ = '4';
	*ptr++ = '8';
	*ptr++ = '\0';
	return (ptr - 12);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = ft_numlen(n, 10);
	res = NULL;
	if ((res = (char *)malloc(sizeof(char) * (size + 1 + is_neg(n)))))
	{
		if (n == -2147483648)
			return (if_min(res));
		else if (is_neg(n))
		{
			res[i++] = '-';
			n = -n;
		}
		while (size)
		{
			res[i++] = '0' + n / ft_power(10, size - 1);
			n %= ft_power(10, size-- - 1);
		}
		res[i] = '\0';
	}
	return (res);
}
