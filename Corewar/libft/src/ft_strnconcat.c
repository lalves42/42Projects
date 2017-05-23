/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnconcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 22:23:41 by tdefresn          #+#    #+#             */
/*   Updated: 2016/04/22 19:37:40 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnconcat(char *dst, char const *src, int n)
{
	char	*buf;

	buf = dst;
	dst = ft_strnjoin(dst, src, n);
	ft_strdel(&buf);
	return (dst);
}
