/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:19:51 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/01 21:53:06 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

static void		prepend(char **str, char *prefix)
{
	char	*str_new;

	str_new = ft_strjoin(prefix, *str);
	ft_strdel(str);
	*str = str_new;
}

void			ft_strprepend(char **str, char *prefix)
{
	if (!str || !(*str) || !prefix)
	{
		ERROR_PARAM("ft_strprepend");
		return ;
	}
	prepend(str, prefix);
}

#else

void			ft_strprepend(char **str, char *prefix)
{
	char	*str_new;

	str_new = ft_strjoin(prefix, *str);
	ft_strdel(str);
	*str = str_new;
}
#endif
