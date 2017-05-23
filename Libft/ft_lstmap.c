/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 20:39:44 by lalves            #+#    #+#             */
/*   Updated: 2015/12/16 21:33:55 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *ret;

	new = f(lst);
	if (new == NULL)
		return (NULL);
	ret = new;
	lst = lst->next;
	while (lst != NULL)
	{
		new->next = f(lst);
		if (new->next == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (ret);
}
