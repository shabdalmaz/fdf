/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:48:14 by ashabdan          #+#    #+#             */
/*   Updated: 2020/02/25 12:56:56 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_dupl(char *str, size_t len)
{
	char	*res;

	res = NULL;
	if (str)
	{
		if ((res = (char *)malloc(sizeof(char) + len + 1)))
		{
			*(res + len) = '\0';
			ft_memcpy(res, str, len);
		}
	}
	return (res);
}

static char		*ft_concat(char **s1, char *s2)
{
	char		*res;
	size_t		len1;
	size_t		len2;

	res = NULL;
	len1 = 0;
	len2 = 0;
	if (*s1 && s2)
	{
		len1 = ft_strlen(*s1);
		len2 = ft_strlen(s2);
		res = get_dupl(*s1, len1 + len2);
		ft_memcpy(res + len1, s2, len2);
		free(*s1);
		*s1 = NULL;
	}
	else if (!*s1 && s2)
		res = get_dupl(s2, ft_strlen(s2));
	else if (*s1 && !s2)
	{
		res = get_dupl(*s1, ft_strlen(*s1));
		free(*s1);
		*s1 = NULL;
	}
	return (res);
}

static int		set_tail(char *str, char **tail)
{
	char	*newl;
	size_t	len;

	newl = ft_strchr(str, '\n');
	len = 0;
	if (newl)
	{
		len = ft_strlen(newl + 1);
		if (len)
		{
			*tail = (char *)malloc(sizeof(char) * (len + 1));
			ft_memset(*tail, 0, len + 1);
			ft_memcpy(*tail, newl + 1, len);
		}
		*newl = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				read_bytes;
	char			*head;
	static char		*tail[FD_SIZE];

	head = NULL;
	if (fd < 0 || !line || read(fd, 0, 0))
		return (-1);
	while ((read_bytes = read(fd, buf, BUFF_SIZE)) > 0 || *(tail + fd))
	{
		*(buf + read_bytes) = '\0';
		if (*(tail + fd))
			head = ft_concat((tail + fd), buf);
		else
			head = ft_concat(&head, buf);
		if (set_tail(head, (tail + fd)))
			break ;
	}
	if (read_bytes == 0 && !*(tail + fd) && !head)
		return (0);
	*line = ft_concat(&head, NULL);
	return (1);
}
