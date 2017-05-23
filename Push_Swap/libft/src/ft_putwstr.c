/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:27:37 by lalves            #+#    #+#             */
/*   Updated: 2016/11/11 16:50:31 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_putwstr(wchar_t *str)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		ret += ft_putwchar(str[i]);
		i++;
	}
	return (ret);
}
