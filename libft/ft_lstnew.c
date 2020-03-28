/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:06:13 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/05 20:57:02 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*item;

	if (!(item = (struct s_list *)malloc(sizeof(struct s_list))))
		return (NULL);
	if (!content)
	{
		item->content = NULL;
		item->content_size = 0;
		item->next = NULL;
	}
	else
	{
		if (!(item->content = (struct s_list *)malloc(content_size)))
			free(item);
		else
		{
			ft_memcpy(item->content, content, content_size);
			item->content_size = content_size;
			item->next = NULL;
		}
	}
	return (item);
}
