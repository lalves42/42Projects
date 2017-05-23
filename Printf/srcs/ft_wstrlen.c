/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:27:14 by lalves            #+#    #+#             */
/*   Updated: 2016/11/09 15:27:16 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_wstrlen(wchar_t *str)
{
	int ret;

	ret = 0;
	while (*str)
	{
		ret += ft_wcharlen(*str);
		str++;
	}
	return (ret);
}
