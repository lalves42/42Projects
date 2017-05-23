/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 19:01:38 by lalves            #+#    #+#             */
/*   Updated: 2016/10/14 17:15:23 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *tmp;

	ptr = NULL;
	tmp = *alst;
	while (tmp != NULL)
	{
		ptr = tmp;
		tmp = tmp->next;
		del(ptr->content, ptr->content_size);
		free(ptr);
	}
	*alst = NULL;
}
