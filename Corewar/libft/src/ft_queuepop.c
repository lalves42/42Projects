/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuepop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:44:16 by tdefresn          #+#    #+#             */
/*   Updated: 2016/09/19 02:24:38 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_queuepop(t_queue **aqueue)
{
	t_queue	*first;

	if (!aqueue || !*aqueue)
	{
		ERROR_PARAM("ft_queuepop");
		return ;
	}
	first = *aqueue;
	if (first->next)
	{
		*aqueue = first->next;
		ft_memdel((void *)&first);
	}
	else
		ft_memdel((void **)aqueue);
}

#else

void	ft_queuepop(t_queue **aqueue)
{
	t_queue	*first;

	first = *aqueue;
	if (first->next)
	{
		*aqueue = first->next;
		ft_memdel((void *)&first);
	}
	else
		ft_memdel((void **)aqueue);
}
#endif
