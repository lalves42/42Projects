/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:36:20 by lalves            #+#    #+#             */
/*   Updated: 2016/10/14 17:15:23 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	long long int temp;

	temp = (long long int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		temp = -temp;
	}
	if (temp >= 10)
	{
		ft_putnbr_fd(temp / 10, fd);
		ft_putchar_fd(temp % 10 + 48, fd);
	}
	else
		ft_putchar_fd(temp + 48, fd);
}
