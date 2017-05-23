/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:46:39 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/08 18:07:25 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*
**	printf format usage
**	%[flags][width][.precision][length]specifier
*/

/*
**	flags matching table
**	sS: -
**	p: -
**	cC: -
**	xX: - # 0
**	uU: - 0
**	oO: - # 0
**	i: + - 0 {space}
**	dD: + - 0 {space}
*/

/*
**	flags:
**	'-'
**	'+' works with i, d and D
**	' ' is ignored when '+' present
**	'#'
**		used with o, x or X specifiers
**		-> print '0', '0x' or '0X' before the number
**		used with a, A, e, E, f, F, g, G
**		-> force the out to contain a digital point,
**			even when none is necessary
**	'0' left pad the number with zeroes
**		is ignored when '-' present
*/

/*
**	.precision:
**	d i o u x X
**	s max character printed
*/

/*
**	#define ft_printf(format, ...) ft_dprintf(stdout, format, __VA_ARGS__)
*/

/*
** write on filedescriptor stdout
** returns number of character printed
*/

int					ft_vprintf(const char *restrict format, va_list *ap)
{
	return (ft_vdprintf(1, format, ap));
}

int					ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	count = ft_vprintf(format, &ap);
	va_end(ap);
	return (count);
}
