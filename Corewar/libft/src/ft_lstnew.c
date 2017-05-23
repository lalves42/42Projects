/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:30:39 by tdefresn          #+#    #+#             */
/*   Updated: 2016/01/13 23:30:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
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
	}
	return (list);
}
