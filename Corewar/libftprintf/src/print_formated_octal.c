/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:46:17 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 15:07:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int	nblen(uintptr_t value)
{
	int		l;

	l = 1;
	while (value /= 8)
		l++;
	return (l);
}

static void	conversion(void *dst, const void *src, size_t n)
{
	char		*to;
	char		*str;
	uintptr_t	value;
	int			l;

	value = (uintptr_t)*((uintptr_t *)src);
	l = nblen(value) - 1;
	while (l-- >= (int)n)
		value /= 8;
	str = &((char *)dst)[n - 1];
	to = (char *)dst;
	while (str >= to)
	{
		*str-- = HEX_TABLE(value % 8);
		value /= 8;
	}
	dst = (void *)str;
}

void		print_formated_octal(t_fdata *fdatas)
{
	uintmax_t	value;
	int			length;

	remove_flags(fdatas, FLAG_MORE | FLAG_SPACE | FLAG_NEGATIVE);
	fdatas->flag |= FLAG_OCTAL;
	if ((value = va_uint(fdatas)))
	{
		length = nblen(value);
		if (length < fdatas->precision)
			remove_flags(fdatas, FLAG_NUMBERSIGN);
		write_format(&value, length, fdatas, conversion);
	}
	else if (fdatas->precision == 0 && !(fdatas->flag & FLAG_NUMBERSIGN))
		write_format("", 0, fdatas, NULL);
	else
	{
		remove_flags(fdatas, FLAG_NUMBERSIGN);
		write_format("0", 1, fdatas, NULL);
	}
}
