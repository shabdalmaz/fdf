/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:51:11 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/01 16:32:37 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_trim(const char *str, char c)
{
	while (*str == c)
		str++;
	return ((char *)str);
}

static int		count_words(const char *s, char c)
{
	int word;
	int i;

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

static int		count_chars(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void		put_into(char *str, int len, char *src)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
}

char			**ft_strsplit(const char *s, char c)
{
	int		words;
	char	**arr;
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	tmp = NULL;
	if (!s || !c)
		return (NULL);
	words = count_words(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	tmp = ft_trim(s, c);
	while (i < words)
	{
		len = count_chars(tmp, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		put_into(arr[i], len, tmp);
		tmp = ft_trim(tmp + len, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
