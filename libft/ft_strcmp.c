/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:44:42 by ashabdan          #+#    #+#             */
/*   Updated: 2019/09/26 13:56:18 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
