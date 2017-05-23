/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:46:07 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 11:14:07 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static size_t	nblen(uintptr_t value)
{
	size_t		l;

	l = 1;
	while (value /= 16)
		l++;
	return (l);
}

static void		conversion(void *dst, const void *src, size_t n)
{
	char		*to;
	char		*str;
	uintptr_t	value;
	int			l;

	value = (uintptr_t)*((uintptr_t *)src);
	l = nblen(value) - 1;
	while (l-- >= (int)n)
		value /= 16;
	str = &((char *)dst)[n - 1];
	to = (char *)dst;
	while (str >= to)
	{
		*str-- = HEX_TABLE(value % 16);
		value /= 16;
	}
	dst = (void *)str;
}

static void		conversion_upper(void *dst, const void *src, size_t n)
{
	char		*to;
	char		*str;
	uintptr_t	value;
	int			l;

	value = (uintptr_t)*((uintptr_t *)src);
	l = nblen(value) - 1;
	while (l-- >= (int)n)
		value /= 16;
	str = &((char *)dst)[n - 1];
	to = (char *)dst;
	while (str >= to)
	{
		*str-- = HEX_TABLE_UPPER(value % 16);
		value /= 16;
	}
	dst = (void *)str;
}

void			print_formated_hex(t_fdata *fdatas)
{
	uintmax_t	value;

	remove_flags(fdatas, FLAG_SPACE | FLAG_MORE);
	fdatas->flag |= FLAG_HEX;
	if ((value = va_uint(fdatas)))
	{
		if (*fdatas->stop == 'X')
			write_format(&value, nblen(value), fdatas, &conversion_upper);
		else
			write_format(&value, nblen(value), fdatas, &conversion);
	}
	else if (fdatas->precision == 0)
	{
		if (*fdatas->stop != 'p')
			remove_flags(fdatas, FLAG_NUMBERSIGN);
		write_format("", 0, fdatas, NULL);
	}
	else
	{
		if (*fdatas->stop != 'p')
			remove_flags(fdatas, FLAG_NUMBERSIGN);
		write_format("0", 1, fdatas, NULL);
	}
}
