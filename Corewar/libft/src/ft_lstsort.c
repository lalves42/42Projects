/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 19:01:17 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/15 21:53:21 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sort(t_list **first, int (*cmp)(void *, void *))
{
	t_list	*lst;
	t_list	*next;
	t_list	*prev;
	int		sorted;

	sorted = 1;
	prev = *first;
	lst = *first;
	next = lst->next;
	while (lst->next)
	{
		if (!cmp(lst->content, lst->next->content) && !(sorted = 0))
		{
			if (lst == *first)
				*first = lst->next;
			if (prev != lst)
				prev->next = lst->next;
			lst->next = next->next;
			next->next = lst;
		}
		prev = lst;
		lst = next;
		next = lst->next;
	}
	return (sorted);
}

t_list		*ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	while (!sort(&lst, cmp))
		;
	return (lst);
}
