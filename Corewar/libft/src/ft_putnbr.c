/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:36:56 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/04 15:18:57 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	NOTE
**	This is not the standard "ft_putnbr" since
**	it returns a value when it shouldn't.
**	===================================
**	void	ft_putnbr(int n)
*/

static void		printnbr(int n, int *bcount)
{
	if (n >= 10)
		printnbr(n / 10, bcount);
	ft_putchar((n % 10) + '0');
	(*bcount)++;
}

static void		print_min(int64_t n, int *bcount)
{
	n = -n;
	if (n >= 10)
		printnbr(n / 10, bcount);
	ft_putchar((n % 10) + '0');
	(*bcount)++;
}

void			ft_putnbr(int n)
{
	int bcount;

	bcount = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == INT_MIN)
			print_min((int64_t)n, &bcount);
		else
			printnbr(-n, &bcount);
		return ;
	}
	printnbr(n, &bcount);
}
