/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:34:09 by lalves            #+#    #+#             */
/*   Updated: 2016/10/16 20:34:49 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_error(char *reason)
{
	ft_putstr(reason);
	ft_putendl("_error");
	exit(EXIT_FAILURE);
}
