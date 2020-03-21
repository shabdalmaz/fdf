/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:49:03 by ashabdan          #+#    #+#             */
/*   Updated: 2019/09/25 08:51:00 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int sym)
{
	int len;

	len = (int)ft_strlen(str);
	str = str + len;
	while (len >= 0)
	{
		if (*str == sym)
			return ((char *)str);
		str--;
		len--;
	}
	return (NULL);
}
