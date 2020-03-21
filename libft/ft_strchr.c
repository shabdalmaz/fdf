/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:16:30 by ashabdan          #+#    #+#             */
/*   Updated: 2019/09/28 20:41:15 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int sym)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (*str == sym)
			return ((char *)str);
		str += 1;
		i += 1;
	}
	return (NULL);
}
