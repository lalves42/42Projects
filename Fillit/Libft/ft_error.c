/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:34:09 by lalves            #+#    #+#             */
/*   Updated: 2016/04/09 14:36:59 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *reason)
{
	write(1, reason, ft_strlen(reason));
	write(1, "_error\n", 7);
	exit(EXIT_FAILURE);
}
