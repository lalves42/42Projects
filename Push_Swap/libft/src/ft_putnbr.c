/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:17:19 by lalves            #+#    #+#             */
/*   Updated: 2016/10/14 17:15:23 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr(int n)
{
	long long int temp;

	temp = (long long int)n;
	if (n < 0)
	{
		ft_putchar('-');
		temp = -temp;
	}
	if (temp >= 10)
	{
		ft_putnbr(temp / 10);
		ft_putchar(temp % 10 + 48);
	}
	else
		ft_putchar(temp + 48);
}
