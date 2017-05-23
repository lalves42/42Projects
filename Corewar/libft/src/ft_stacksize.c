/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:44:33 by tdefresn          #+#    #+#             */
/*   Updated: 2016/05/10 01:05:18 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

int		ft_stacksize(t_stack *stack)
{
	t_stack		*top;
	int			i;

	if (!stack)
	{
		ERROR_PARAM("ft_stacksize");
		return (-1);
	}
	top = stack;
	i = 1;
	while (top->prev)
	{
		top = top->prev;
		i++;
	}
	return (i);
}

#else

int		ft_stacksize(t_stack *stack)
{
	t_stack		*top;
	int			i;

	top = stack;
	i = 1;
	while (top->prev)
	{
		top = top->prev;
		i++;
	}
	return (i);
}
#endif
