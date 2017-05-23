/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:44:25 by tdefresn          #+#    #+#             */
/*   Updated: 2015/12/14 11:51:53 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_stacknew(void const *content, size_t content_size)
{
	t_stack *stack;

	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (stack)
	{
		if (content)
		{
			stack->content = ft_memalloc(content_size);
			if (stack->content)
			{
				stack->content = ft_memcpy(stack->content,
											content, content_size);
				stack->content_size = content_size;
			}
			else
				ft_memdel((void **)&stack);
		}
		else
		{
			stack->content = NULL;
			stack->content_size = 0;
		}
		stack->prev = NULL;
	}
	return (stack);
}
