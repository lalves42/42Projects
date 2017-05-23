/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:46:41 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 08:58:18 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void	conversion(void *dst, const void *src, size_t n)
{
	ft_wstrcpy((char *)dst, (wchar_t *)src, n);
}

static void	print_null(t_fdata *fdatas)
{
	if (fdatas->precision >= 0 && fdatas->precision < 6)
		write_format("      ", fdatas->precision, fdatas, NULL);
	else
	{
		fdatas->precision = 6;
		write_format("(null)", 6, fdatas, NULL);
	}
}

static void	print_wide(t_fdata *fdatas)
{
	wchar_t	*wstr;
	int		length;

	if ((wstr = (wchar_t *)va_arg(*fdatas->ap, wchar_t *)))
	{
		length = ft_wstrlen(wstr);
		if (length < 0)
		{
			write_error(fdatas);
			return ;
		}
		if (fdatas->precision >= 0)
			length = (length > fdatas->precision) ? fdatas->precision : length;
		fdatas->precision = -1;
		write_format(wstr, length, fdatas, &conversion);
	}
	else
		print_null(fdatas);
}

static void	print_ascii(t_fdata *fdatas)
{
	char	*str;
	int		length;

	if ((str = va_arg(*fdatas->ap, char *)))
	{
		length = ft_strlen(str);
		if (fdatas->precision >= 0)
			length = (length > fdatas->precision) ? fdatas->precision : length;
		write_format(str, length, fdatas, NULL);
	}
	else
		print_null(fdatas);
}

void		print_formated_string(t_fdata *fdatas, char *s)
{
	remove_flags(fdatas, FLAG_SPACE | FLAG_MORE | FLAG_NUMBERSIGN);
	if (s != NULL)
		write_format(s, ft_strlen(s), fdatas, NULL);
	else if (fdatas->length == LENGTH_L)
		print_wide(fdatas);
	else
		print_ascii(fdatas);
}
