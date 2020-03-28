/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:34:42 by ashabdan          #+#    #+#             */
/*   Updated: 2020/03/27 19:40:53 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swapcoords(int *a, int *b, int *c, int *d)
{
	ft_swap(a, b);
	ft_swap(c, d);
}

int		wordcounter(const char *s, char c)
{
	int		word;
	int		i;

	i = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			i++;
			word = 1;
		}
		else if (*s == c && word == 1)
			word = 0;
		s++;
	}
	return (i);
}

void	iso(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(0.5) - z;
}
