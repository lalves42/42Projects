/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:38:59 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 07:41:04 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*next_arg(char *arg)
{
	while (*arg)
	{
		if (*arg == SEPARATOR_CHAR || *arg == COMMENT_CHAR || *arg == ';')
		{
			arg++;
			break ;
		}
		arg++;
	}
	return (arg);
}
