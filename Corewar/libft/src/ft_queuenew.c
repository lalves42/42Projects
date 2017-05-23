/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:44:12 by tdefresn          #+#    #+#             */
/*   Updated: 2016/09/19 02:09:38 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue		*ft_queuenew(void const *content, size_t content_size)
{
	t_queue *q;

	q = (t_queue *)ft_memalloc(sizeof(t_queue));
	if (q)
	{
		if (content)
		{
			q->content = ft_memalloc(content_size);
			if (q->content)
			{
				q->content = ft_memcpy(q->content, content, content_size);
				q->content_size = content_size;
			}
			else
				ft_memdel((void **)&q);
		}
		else
		{
			q->content = NULL;
			q->content_size = 0;
		}
		q->next = NULL;
	}
	return (q);
}
