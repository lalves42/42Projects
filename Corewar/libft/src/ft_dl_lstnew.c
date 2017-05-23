/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:30:53 by tdefresn          #+#    #+#             */
/*   Updated: 2015/12/14 11:51:52 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dl_list	*ft_dl_lstnew(void const *content, size_t content_size)
{
	t_dl_list *list;

	list = (t_dl_list *)ft_memalloc(sizeof(t_dl_list));
	if (list)
	{
		if (content)
		{
			list->content = ft_memalloc(content_size);
			if (list->content)
			{
				list->content = ft_memcpy(list->content, content, content_size);
				list->content_size = content_size;
			}
			else
				ft_memdel((void **)&list);
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
		list->next = NULL;
		list->prev = NULL;
	}
	return (list);
}
