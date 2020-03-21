/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 07:15:45 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/01 21:25:13 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	len;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i += 1;
	if (i >= len + 1)
		return (ft_strdup(""));
	while (s[len] == 32 || (s[len] >= 9 && s[len] <= 13))
		len -= 1;
	len += 1;
	if (!(str = (char *)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	while (i < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
