/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:46:52 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 09:07:18 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void	*st_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		((char *)b)[i++] = (unsigned char)c;
	return (b);
}

/*
** write characters inside `str`, `str` needs to be big enough
** returns length of formated string (without \0)
** returns -1 on fail
** TODO unimplemented
*/

int			ft_vsprintf(char *restrict str, const char *restrict format,
																va_list *ap)
{
	t_fdata		fdatas;

	st_memset(&fdatas, 0, sizeof(t_fdata));
	fdatas.ap = ap;
	fdatas.format = format;
	fdatas.out = str;
	fdatas.write_size = INT_MAX;
	if (fdatas.write_size < 0)
		return (-1);
	parse(format, &fdatas);
	if (fdatas.flag & FLAG_WRITE_ERROR)
		return (-1);
	return (fdatas.bcount);
}

int			ft_sprintf(char *restrict str, const char *restrict format, ...)
{
	va_list		ap;
	int			out;

	va_start(ap, format);
	out = ft_vsprintf(str, format, &ap);
	va_end(ap);
	return (out);
}
