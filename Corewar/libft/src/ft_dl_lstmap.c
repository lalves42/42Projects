/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:30:01 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:59:01 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

t_dl_list		*ft_dl_lstmap(t_dl_list *lst,
					t_dl_list *(*f)(t_dl_list *elem))
{
	t_dl_list	*new_list;

	if (!lst || !f)
	{
		ERROR_PARAM("ft_dl_lstmap");
		return (NULL);
	}
	new_list = f(lst);
	if (new_list)
	{
		if (lst->next)
		{
			new_list->next = ft_dl_lstmap(lst->next, f);
			if (!new_list->next)
			{
				if (new_list->content)
					ft_memdel((void **)&new_list->content);
				ft_memdel((void **)&new_list);
			}
		}
	}
	return (new_list);
}

#else

t_dl_list		*ft_dl_lstmap(t_dl_list *lst,
					t_dl_list *(*f)(t_dl_list *elem))
{
	t_dl_list	*new_list;

	new_list = f(lst);
	if (new_list)
	{
		if (lst->next)
		{
			new_list->next = ft_dl_lstmap(lst->next, f);
			if (!new_list->next)
			{
				if (new_list->content)
					ft_memdel((void **)&new_list->content);
				ft_memdel((void **)&new_list);
			}
		}
	}
	return (new_list);
}
#endif
