/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:59:29 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/08 17:00:02 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*
** Happens on malformated widechar
*/

void	write_error(t_fdata *fdatas)
{
	fdatas->flag |= FLAG_WRITE_ERROR;
	write_to_buffer("", fdatas);
}
