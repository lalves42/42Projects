/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuepush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:44:19 by tdefresn          #+#    #+#             */
/*   Updated: 2016/09/19 02:09:55 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_queuepush(t_queue *queue, t_queue *new)
{
	t_queue	*last;

	if (!queue || !new)
	{
		ERROR_PARAM("ft_queuepush");
		return ;
	}
	last = ft_queueback(queue);
	last->next = new;
}

#else

void	ft_queuepush(t_queue *queue, t_queue *new)
{
	t_queue	*last;

	last = ft_queueback(queue);
	last->next = new;
}
#endif
