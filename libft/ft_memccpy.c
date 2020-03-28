/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:56:24 by ashabdan          #+#    #+#             */
/*   Updated: 2019/09/26 13:13:18 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dt, const void *restrict sc, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;
	unsigned char		ch;

	dest = (unsigned char *)dt;
	src = (unsigned char *)sc;
	ch = (unsigned char)c;
	while (n)
	{
		(*dest) = (*src);
		if (*src == ch)
			return (++dest);
		dest++;
		src++;
		n--;
	}
	return (NULL);
}
