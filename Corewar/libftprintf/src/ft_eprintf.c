/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:46:27 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/08 18:13:49 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*
**	#define ft_eprintf(format, ...) ft_dprintf(stderr, format, __VA_ARGS__)
*/

/*
** write on stderr
** returns number of character printed
*/

int		ft_veprintf(const char *restrict format, va_list *ap)
{
	return (ft_vdprintf(2, format, ap));
}

int		ft_eprintf(const char *restrict format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	count = ft_veprintf(format, &ap);
	va_end(ap);
	return (count);
}
