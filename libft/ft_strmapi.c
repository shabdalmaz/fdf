/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 10:24:18 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/01 14:28:37 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*new_str;

	i = 0;
	len = 0;
	new_str = NULL;
	if (s && f)
	{
		len = ft_strlen(s);
		if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			new_str[i] = (*f)(i, s[i]);
			i++;
		}
		new_str[len] = '\0';
	}
	return (new_str);
}
