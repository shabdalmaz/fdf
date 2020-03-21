/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:08:52 by ashabdan          #+#    #+#             */
/*   Updated: 2019/10/10 21:50:06 by ashabdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;

	new_lst = NULL;
	if (lst && f)
	{
		while (lst != NULL)
		{
			ft_lstadd(&new_lst, f(lst));
			lst = lst->next;
		}
		ft_lstrev(&new_lst);
	}
	return (new_lst);
}
