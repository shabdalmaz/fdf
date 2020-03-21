/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:48:29 by ashabdan          #+#    #+#             */
/*   Updated: 2019/09/26 08:32:27 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	size_t i;

	i = 0;
	while (i < (sizeof(*memptr) * num))
	{
		*(unsigned char *)memptr = (unsigned char)val;
		memptr++;
		i++;
	}
	return (memptr - i);
}
