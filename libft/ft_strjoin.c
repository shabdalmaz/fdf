/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:46:09 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/01 14:35:05 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	str = NULL;
	len1 = 0;
	len2 = 0;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if ((str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		{
			ft_strcpy(str, s1);
			ft_strcpy((str + len1), s2);
			str[len1 + len2 + 1] = '\0';
		}
	}
	return (str);
}
