/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:12:04 by ashabdan          #+#    #+#             */
/*   Updated: 2019/09/27 19:51:34 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *str;

	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		ft_strcpy(str, src);
	return (str);
}
