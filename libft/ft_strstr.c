/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:00:17 by ashabdan          #+#    #+#             */
/*   Updated: 2019/09/28 22:08:57 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		let;

	let = 0;
	if (*haystack == '\0' && *needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		while (*haystack == *needle && (*needle && *haystack))
		{
			haystack++;
			needle++;
			let++;
		}
		if (*needle == '\0')
			return ((char *)(haystack - (ft_strlen(needle) + let)));
		else if (*haystack != *needle)
		{
			needle -= let;
			haystack -= let;
			let = 0;
		}
		haystack++;
	}
	return (NULL);
}
