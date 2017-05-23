/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:08:50 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/08 18:08:54 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

intmax_t	va_int(t_fdata *fdatas)
{
	intmax_t	value;

	value = 0;
	if (fdatas->length == LENGTH_NONE)
		value = (intmax_t)va_arg(*fdatas->ap, int);
	else if (fdatas->length & LENGTH_Z)
		value = (intmax_t)va_arg(*fdatas->ap, size_t);
	else if (fdatas->length & LENGTH_J)
		value = (intmax_t)va_arg(*fdatas->ap, intmax_t);
	else if (fdatas->length & LENGTH_LL)
		value = (intmax_t)va_arg(*fdatas->ap, long long int);
	else if (fdatas->length & LENGTH_L)
		value = (intmax_t)va_arg(*fdatas->ap, long int);
	else if (fdatas->length & LENGTH_H)
		value = (intmax_t)((short int)va_arg(*fdatas->ap, int));
	else if (fdatas->length & LENGTH_HH)
		value = (intmax_t)((signed char)va_arg(*fdatas->ap, int));
	return (value);
}

uintmax_t	va_uint(t_fdata *fdatas)
{
	uintmax_t	value;

	value = 0;
	if (fdatas->length == LENGTH_NONE)
		value = (uintmax_t)va_arg(*fdatas->ap, unsigned int);
	else if (fdatas->length & LENGTH_Z)
		value = (uintmax_t)va_arg(*fdatas->ap, size_t);
	else if (fdatas->length & LENGTH_J)
		value = (uintmax_t)va_arg(*fdatas->ap, uintmax_t);
	else if (fdatas->length & LENGTH_LL)
		value = (uintmax_t)va_arg(*fdatas->ap, uint64_t);
	else if (fdatas->length & LENGTH_L)
		value = (uintmax_t)va_arg(*fdatas->ap, unsigned long);
	else if (fdatas->length & LENGTH_H)
		value = (uintmax_t)((unsigned short)va_arg(*fdatas->ap, unsigned int));
	else if (fdatas->length & LENGTH_HH)
		value = (uintmax_t)((unsigned char)va_arg(*fdatas->ap, unsigned int));
	return (value);
}
