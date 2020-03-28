/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:58:36 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/06 00:38:20 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *needle, size_t len)
{
	size_t	i;
	int		let;

	i = 0;
	let = 0;
	while (i <= len && hst[i])
	{
		while (needle[let] == hst[i] && i < len && hst[i])
		{
			let++;
			i++;
		}
		if (needle[let] == '\0')
			return ((char *)&hst[i - let]);
		else if (needle[let] != hst[i])
		{
			i -= let;
			let = 0;
		}
		i++;
	}
	return (NULL);
}
