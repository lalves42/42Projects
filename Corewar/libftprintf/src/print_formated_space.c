/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:46:32 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/16 03:54:36 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void			print_formated_space(t_fdata *fdatas)
{
	remove_flags(fdatas, FLAG_SPACE | FLAG_MORE | FLAG_NUMBERSIGN);
	fdatas->precision = -1;
	write_format(fdatas->stop, 1, fdatas, NULL);
}
