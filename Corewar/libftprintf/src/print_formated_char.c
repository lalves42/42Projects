/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:45:50 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/08 12:44:06 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int				print_formated_char(t_fdata *fdatas)
{
	wint_t	c;

	c = 0;
	if (fdatas->length == LENGTH_NONE)
		c = (wint_t)va_arg(*fdatas->ap, int);
	else if (fdatas->length == LENGTH_L)
	{
		if (print_formated_widechar(fdatas) < 0)
			return (-1);
		return (0);
	}
	fdatas->precision = -1;
	remove_flags(fdatas, FLAG_SPACE | FLAG_MORE | FLAG_NUMBERSIGN);
	write_format((char *)&c, 1, fdatas, NULL);
	return (0);
}
