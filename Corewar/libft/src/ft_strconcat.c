/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 22:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2016/04/22 19:26:22 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strconcat(char *dst, char const *src)
{
	char	*buf;

	buf = dst;
	dst = ft_strjoin(dst, src);
	ft_strdel(&buf);
	return (dst);
}
