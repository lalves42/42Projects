/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:46:22 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/08 18:07:03 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*
** write on filedescriptor fd
** returns number of character printed
*/

int			ft_vdprintf(int fd, const char *restrict format, va_list *ap)
{
	char	*output;
	int		ret;

	ret = -1;
	output = NULL;
	if ((ret = ft_vasprintf(&output, format, ap)))
		write(fd, output, ret);
	free(output);
	return (ret);
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	count = ft_vdprintf(fd, format, &ap);
	va_end(ap);
	return (count);
}
