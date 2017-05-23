/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:44:31 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:55:39 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_stackpush(t_stack **astack, t_stack *new)
{
	if (!astack || !new || !*astack)
	{
		ERROR_PARAM("ft_stackpush");
		return ;
	}
	new->prev = *astack;
	*astack = new;
}

#else

void	ft_stackpush(t_stack **astack, t_stack *new)
{
	new->prev = *astack;
	*astack = new;
}
#endif
