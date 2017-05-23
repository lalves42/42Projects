/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:14:37 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:45:37 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

int		ft_lstsize(t_list *lst)
{
	int		i;

	if (!lst)
	{
		ERROR_PARAM("ft_lstsize");
		return (-1);
	}
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

#else

int		ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
#endif
