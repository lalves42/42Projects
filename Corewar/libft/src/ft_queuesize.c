/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuesize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:44:22 by tdefresn          #+#    #+#             */
/*   Updated: 2016/09/19 02:32:49 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

int		ft_queuesize(t_queue *queue)
{
	int		i;

	if (!queue)
	{
		ERROR_PARAM("ft_queuesize");
		return (-1);
	}
	i = 0;
	while (queue)
	{
		queue = queue->next;
		i++;
	}
	return (i);
}

#else

int		ft_queuesize(t_queue *queue)
{
	int		i;

	i = 0;
	while (queue)
	{
		queue = queue->next;
		i++;
	}
	return (i);
}
#endif
