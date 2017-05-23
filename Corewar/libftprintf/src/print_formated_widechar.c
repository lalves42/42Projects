/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_widechar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:46:54 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 14:25:52 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int	wintlen(wint_t unicode_point)
{
	int		bcount;

	bcount = -1;
	if (unicode_point & 0x80000000)
		return (-1);
	else if (unicode_point <= MASK7)
		bcount = 1;
	else if (unicode_point <= MASK11)
		bcount = 2;
	else if (unicode_point <= MASK16)
		bcount = 3;
	else if (unicode_point <= MASK21)
		bcount = 4;
	else if (unicode_point <= MASK26)
		bcount = 5;
	else if (unicode_point <= MASK31)
		bcount = 6;
	return (bcount);
}

static void	conversion(void *dst, const void *src, size_t n)
{
	ft_wstrcpy((char *)dst, (wchar_t *)src, n);
}

int			print_formated_widechar(t_fdata *fdatas)
{
	wint_t	c;
	int		length;

	remove_flags(fdatas, FLAG_SPACE | FLAG_MORE | FLAG_NUMBERSIGN);
	fdatas->precision = -1;
	remove_flags(fdatas, FLAG_SPACE | FLAG_MORE);
	c = (wint_t)va_arg(*fdatas->ap, wint_t);
	length = wintlen(c);
	if (length < 0 || length > 4)
	{
		write_error(fdatas);
		return (-1);
	}
	write_format(&c, length, fdatas, &conversion);
	return (0);
}
