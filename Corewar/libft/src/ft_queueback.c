/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:43:55 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:49:55 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

t_queue		*ft_queueback(t_queue *queue)
{
	if (!queue)
	{
		ERROR_PARAM("ft_queueback");
		return (NULL);
	}
	if (queue->next)
		return (ft_queueback(queue->next));
	return (queue);
}

#else

t_queue		*ft_queueback(t_queue *queue)
{
	if (queue->next)
		return (ft_queueback(queue->next));
	return (queue);
}
#endif
